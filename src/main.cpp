#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/Lik.h"
#include "../include/Animation.h"

//iostream
using std::cout;
using std::cin;
using std::endl;


int main() {
	
    srand(time(0));  //inicijalizacija za rand
    
    //Predefinisani likovi za V1.0
    Lik karakteri[3] = {
    	Lik("Ares", 2000, 300, 850, 30),
    	Lik("Zeus", 2800, 200, 600, 60),
    	Lik("Prometej", 4000, 120, 450, 80)
	};
	
	
  //dovoljne su dvije varijable za manipulaciju kroz opcije
  short m, n;  
  
	writeLine("   UCITAVANJE IGRE \033[96m", 20); bar(20, 70); cout << "\033[0m\n\n";
	cout << "\n\t\t\t "; writeLine("||=== \033[5;36mBORBA (V1.2) \033[0m ===||\n", 50);
	
	do{
	cout << "\t\t   "; writeLine("||=== \033[1;36mIZABERI SVOG KARAKTERA:\033[0m ===||", 50); cout << "\n\n";
		
		for(int i=0;i<3;i++){
	    	cout << "\033[33m\t\t" << i + 1 << ".\033[0m \033[96m"; writeLine(karakteri[i].getImeStr(), 60);  cout << "\033[0m";
	    	karakteri[i].prikazLika();
		}
			
		do{
			
			writeLine("Odaberi svog borca \033[93m(1-3)\033[0m: ",40);
			cin >> m;
			
			if(m < 0 || m > 3){
				cout << "\t\t\033[31m"; writeLine("[NEVAZECI IZBOR]\033[0m pokusaj ponovo...\n\n", 30);
			} 
			
		}while(m < 0 || m > 3);
		
		//zbog pristupa stvarnom indeksu
		  m--;
		
	     writeLine("\n\t\t||===   \033[96mIZABERI SVOG PROTIVNIKA:\033[0m ===||\n\n", 50);
		
		  for(int i=0;i<3;i++){
		  	
			if(m == i) continue;
			
			cout << "\033[33m\t\t" << i + 1 << ".\033[0m \033[96m"; writeLine(karakteri[i].getImeStr(), 60);  cout << "\033[0m";
			karakteri[i].prikazLika();
		}
		
		  do{
		  	
		  	writeLine("Odaberi svog protivnika \033[93m(tvoj karakter je nedostupan)\033[0m: ", 40);
		  	cin >> n;
		  	
		  	if(n-1 == m) writeLine("\t\t\033[31m[NEVAZECI IZBOR]\033[0m vec izabran, pokusaj ponovo...\n\n", 30);
		  	
		  	else if(n < 0 || n > 3) {
		  		cout << "\t\t\033[31m"; writeLine("[NEVAZECI IZBOR]\033[0m pokusaj ponovo...\n\n", 30);
			  } 
			  
		  }while ((n < 0 || n > 3) || (n-1 == m));
		  
		  //takodjer radi pristupa stvarnom indeksu
		    n--;
		    
		    //duboke kopije ulaze u igru
            Lik* igrac = new Lik(karakteri[m]);
            Lik* protivnik = new Lik(karakteri[n]);
                
        cout << "\n\n";   loading("\033[96m                           UCITAVANJE BORBE  ", 3); cout << "\033[0m\n\n";
            writeLine("\n   \t\t||=== \033[96mBORBA POCINJE\033[0m ===||\n\n", 30);
            
            //poziv metode borba
            igrac->borba(*protivnik); 
            
            //nakon kraja borbe brise
            delete igrac;
            delete protivnik;
                        
		 do{
		 	
		 	writeLine("DA LI ZELIS OPET \033[93m(1---DA   0---NE)\033[0m: ", 40);
		 	cin >> m;
		 	
		 	if(m < 0 || m > 1) {
		 		
		 		cout << "\t\t\033[31m"; 
				writeLine("[NEVAZECI IZBOR]\033[0m pokusaj ponovo...\n\n", 30);
				 
			 }
		 }while(m < 0 || m > 1);
		 
	}while(m != 0);
	
	  writeLine("\n\t\t\t||=== \033[96mKRAJ IGRE\033[0m ===||\n\n", 50);
	  return 0;
}
