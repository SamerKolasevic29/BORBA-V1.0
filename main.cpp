#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Lik.h"

//iostream
using std::cout;
using std::cin;
using std::endl;


int main() {
    srand(time(NULL));  //inicijalizacija za rand
    
    //Predefinisani likovi za V1.0
    Lik karakteri[3] = {
    	Lik("Ares", 2000, 300, 850, 30),
    	Lik("Zeus", 2800, 200, 600, 60),
    	Lik("Prometej", 4000, 120, 450, 80)
	};
	
	
  //dovoljne su dvije varijable za manipulaciju kroz opcije
  short m, n;  
	
	cout << "\n\t\t\t ||=== \033[5;36mBORBA (V1.1) \033[0m ===||\n";
	
	do{
	cout << "\t\t   ||=== \033[1;36mIZABERI SVOG KARAKTERA:\033[0m ===||\n\n";
		
		for(int i=0;i<3;i++){
	    	cout << "\033[33m\t\t" << i + 1 << ".\033[0m \033[96m" << karakteri[i].getIme() << "\033[0m";
	    	karakteri[i].prikazLika();
		}
			
		do{
			cout << "Odaberi svog borca \033[93m(1-3)\033[0m: ";
			cin >> m;
			if(m < 0 || m > 3) cout << "\t\t\033[31m[NEVAZECI IZBOR]\033[0m pokusaj ponovo...\n\n";
		}while(m < 0 || m > 3);
		
		//zbog pristupa stvarnom indeksu
		  m--;
		
		cout << "\n\t\t||===   \033[96mIZABERI SVOG PROTIVNIKA:\033[0m ===||\n\n";
		
		  for(int i=0;i<3;i++){
			if(m == i) continue;
			cout << "\033[33m\t\t" << i + 1 << ".\033[0m \033[96m" << karakteri[i].getIme() << "\033[0m";
			karakteri[i].prikazLika();
		}
		
		  do{
		  	cout << "Odaberi svog protivnika \033[93m(tvoj karakter je nedostupan)\033[0m: ";
		  	cin >> n;
		  	
		  	if(n-1 == m) cout << "\t\t\033[31m[NEVAZECI IZBOR]\033[0m vec izabran, pokusaj ponovo...\n\n";
		  	else if(n < 0 || n > 3) cout << "\t\t\033[31m[NEVAZECI IZBOR]\033[0m pokusaj ponovo...\n\n";
		  }while ((n < 0 || n > 3) || (n-1 == m));
		  
		  //takodjer radi pristupa stvarnom indeksu
		    n--;
		    
		    //duboke kopije ulaze u igru
            Lik* igrac = new Lik(karakteri[m]);
            Lik* protivnik = new Lik(karakteri[n]);
                
                
            cout << "\n   \t\t||=== \033[96mBORBA POCINJE\033[0m ===||\n\n";
            
            //poziv metode borba
            igrac->borba(*protivnik); 
            
            //nakon kraja borbe brise
            delete igrac;
            delete protivnik;
                        
		 do{
		 	cout << "DA LI ZELIS OPET \033[93m(1---DA   0---NE)\033[0m: ";
		 	cin >> m;
		 	if(m < 0 || m > 1) cout << "\t\t\033[31m[NEVAZECI IZBOR]\033[0m pokusaj ponovo...\n\n";
		 }while(m < 0 || m > 1);
	}while(m != 0);
	
	   cout << "\n\t\t\t||=== \033[96mKRAJ IGRE\033[0m ===||\n\n";
	return 0;
}

