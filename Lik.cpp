#include <iostream>
#include <cstring>
#include <cstdlib>    //za rand()
#include <ctime>      // za time()
#include <iomanip>    //za setw() i setfill()
#include "Lik.h"

//posto nisam od prakse std:: , bar da ih nabrojim
using std::cout;
using std::cin;
using std::endl;
using std::strcpy;
using std::setw;
using std::setfill;

//konsturktor
Lik::Lik(const char* i, int z, int ln, int sn, int c){
	
	 ime = new char[strlen(i) + 1];
	 strcpy(ime, i);
	 
	 zdravlje = new int(z);
	 lakiNapad = ln;
	 specNapad = sn;
	 crit = c;
	 iskoristioSpec = false;
}

//destruktor
Lik::~Lik(){
	
	delete[] ime;
	delete zdravlje;
}

//duboka kopija
Lik::Lik(const Lik& l){
	
	ime = new char[strlen(l.ime) + 1];
	strcpy(ime, l.ime);
	
	zdravlje = new int(*l.zdravlje);
	lakiNapad = l.lakiNapad;
	specNapad = l.specNapad;
	crit = l.crit;
	iskoristioSpec = l.iskoristioSpec; //mada moze se stavljati na default vrijednost false
}


//getteri: 
const char* Lik::getIme() const{
	return ime;
}

int Lik::getZdravlje() const{
	return *zdravlje;
}

int Lik::getLakiNapad() const{
    return lakiNapad;
}

int Lik::getSpecNapad() const{
	return specNapad;
}

int Lik::getCrit() const{
	return crit;
}

bool Lik::getIskoristioSpec() const{
	return iskoristioSpec;
}

//Prikladan prikaz lika 
void Lik::prikazLika() const{
	
	cout << "\n\t\t\033[90m" << setw(39) << setfill('=') << "" << "\033[0m\n"
	     << "\033[0m\t\t| Zdravlje: \033[92m" << *zdravlje << "HP" << endl
	     << "\033[0m\t\t| Laki napad: \033[91m" << lakiNapad << "ATK" << endl
	     << "\033[0m\t\t| Specijalni napad: \033[31m" << specNapad << "ATK" << endl
	     << "\033[0m\t\t| Sansa za critical strike: \033[33m" << crit << "%\033[0m" << endl
	     << "\t\t\033[90m" << setw(39) << setfill('=') << "" << "\033[0m\n\n";
}


//implementacija metoda za borbu
void Lik::potez(Lik& b){
	
	 short x; //Promjenjiva za odabir napada
	 
	 
	 //do-while koji omogucava validan unos i provjeru iskoristioSpec da se moze iskljucivo jednom koristiti
	 do{
	     cout << "Odaberi napad: \t\033[91m1---LAKI NAPAD\033[0m\n\t        \033[31m2---SPECIJALNI NAPAD\033[93m "
	     << (iskoristioSpec ? "(Iskoristen)\n" : "(nije koristen)\n") 
	     << "\033[0mUNESI NAPAD: ";
	     cin >> x;
	     if(x == 2 && iskoristioSpec) 
	          cout << "\033[31m[SPECIJALNI NAPAD JE ISKORISTEN]\033[0m\n\n";
	     else if(x < 1 || x > 2)
	          cout << "\033[31m[POGRESAN ODABIR NAPADA]\033[0m\n\n";
	 }while((x == 2 && iskoristioSpec) || (x < 1 || x > 2));
	 
	    switch(x){                            
	    	
	    	//laki napad gdje se provjerava i sansa za critical strike
	    	case 1:{
	    		cout << "\033[33m" << setw(60) << setfill('=') << "\033[0m\n";
	    		int sansa = rand() % 101;
	    	   
			   if(sansa <= crit) 
			      kritNapad(b);
			   else 
			      lahkiNapad(b);
				break;
			}
			    
			//specijalni napad gdje se nakon iskoristavanja napada, iskoristioSpec postavlja na true
			case 2:
				speciNapad(b);
				iskoristioSpec = true;
				
				 break;
		}
		
}

//metode za napad
void Lik::lahkiNapad(Lik& b){
	
	 cout << "\n\033[96m" << ime << "\033[0m napada \033[96m" << b.ime << "a\033[0m lakim napadom \033[91m(" << lakiNapad << "DMG)\033[0m\n";
	//smanjivanje zdravlja za vrijednost
	*b.zdravlje -= lakiNapad;
	
	//izbjegavanje vrijednosti zdravlja da bude manje od nule
    if(*b.zdravlje < 0) *b.zdravlje = 0;

}

void Lik::speciNapad(Lik &b){
	
	cout << "\n\033[96m" << ime << "\033[0m napada \033[96m" << b.ime << "a\033[0m specijalnim napadom \033[31m(" << specNapad << "DMG)\033[0m\n";
	*b.zdravlje -= specNapad;
	
	   if(*b.zdravlje < 0) *b.zdravlje = 0;
    
}

void Lik::kritNapad(Lik& b){
	
	cout << "\n\033[96m" << this->ime << "\033[0m napada \033[96m" << b.ime << "a\033[0m critical napadom  \033[6;93m(" << 2 * this->lakiNapad << "DMG)\033[0m\n";
	*b.zdravlje -= 2 * lakiNapad;
	
    if(*b.zdravlje < 0) *b.zdravlje = 0;
    
}


//GLAVNA METODA BORBA
 void Lik::borba(Lik& b){
 	
 	bool flag = true;
 	cout << "\t\t ||=== BORBA IZMEDJU: \033[96m" << this->getIme() << "\033[0m  i  \033[96m" << b.getIme() << "\033[0m ===||\n\n";
 	     
 	     while(*this->zdravlje > 0 && *b.zdravlje > 0){
 	     	if(flag){
 	     		cout << "\033[96m" << this->ime << "\033[93m(ti)\033[0m je na potezu:\n";
 	     	    	this->potez(b);
			  }
			   else {
			   	   int x = rand()% 2 + 1;
			   	    if(x == 2 && !b.iskoristioSpec){
			   	    	b.speciNapad(*this);
			   	    	b.iskoristioSpec = true;
					   }
					else{ 
					 int sansa = rand() % 101;
					  if(sansa <= b.crit) b.kritNapad(*this);
					  else b.lahkiNapad(*this);
					
					} 
			   }
			  
			   cout << "\t\t\033[90m" << setw(20) << setfill('=') << "" <<"\033[0m\n"
			        << "\t\tSTATUS NAKON POTEZA:\n\t\t\033[96m" << this->ime << " \033[92m" << *this->zdravlje << "HP\033[0m\n\t\t\033[96m"
			        << b.ime << " \033[92m" << *b.zdravlje << "HP\033[0m\n" "\t\t\033[90m" << setw(20) << setfill('=') << "" << "\033[0m\n\n";
					
					
			if(!flag)  cout << "\033[33m" << setw(60) << setfill('=') << "\033[0m\n";
			        
			flag = !flag;
		  }
		  if(*this->zdravlje)
		         cout << "POBJEDNIK JE: \033[6;96m" << this->ime << "\033[6;0m!!\033[0m\n\n";
		         
		   else cout << "POBJEDNIK JE: \033[6;96m" << b.ime << "\033[0m!!\n\n";
 }
