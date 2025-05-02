#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Lik.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    srand(time(NULL));  //inicijalizacija za rand
    
    //Predefinisani likovi za V1.0
    Lik karakteri[3] = {
    	Lik("Ares", 2000, 300, 850, 30),
    	Lik("Zeus", 2800, 200, 600, 60),
    	Lik("prometej", 4000, 120, 450, 80)
	};
	
	int m, n;
	
	while(true){
		cout << "\t\t||=== BORBA (V1.0) ===||\n\n"
		     << "\t\t||=== IZABERI SVOG KARAKTERA: ===||\n";
		     
	    for(int i=0;i<3;i++){
	    	cout << i + 1 << ".";
	    	karakteri[i].prikazLika();
		}
		
		cout << "Odaberi svog borca (1-3) ili 0 za izlaz: ";
		cin >> m;
		
		if(m == 0 || m < 1 || m > 3) break;
		m--;
		
		cout << "\t\t||=== IZABERI SVOG PROTIVNIKA: ===||\n\n";
		
		for(int i=0;i<3;i++){
			if(m == i) continue;
			cout << i + 1 << ".";
			karakteri[i].prikazLika();
		}
		
	cout << "Odaberi svog protivnika (tvoj karakter je nedostupan) ili 0. za izlaz: ";
		cin >> n;
		if(n-1 == m || n == 0 || n < 0 || n > 3) break;
		n--;
		
		//duboke kopije ulaze u igru
		Lik* igrac = new Lik(karakteri[m]);
		Lik* protivnik = new Lik(karakteri[n]);
		
		cout << "\t\t||=== BORBA POCINJE ===||\n\n";;
		igrac->borba(*protivnik);
		
		delete igrac;
		delete protivnik;
		
		cout << "DA LI ZELIS OPET (1---DA   0---NE): ";
		  cin >> m;
		if(m == 0) break; 
	}
	
	cout << "\t\t||=== KRAJ IGRE ===||\n\n";
	
	return 0;
}

