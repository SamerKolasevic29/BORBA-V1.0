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
	
	cout << "\n===============================================\n"
	     << "\t| Ime: " << ime << endl
	     << "\t| Zdravlje: " << *zdravlje << "HP" << endl
	     << "\t| Laki napad: " << lakiNapad << "ATK" << endl
	     << "\t| Specijalni napad: " << specNapad << "ATK" << endl
	     << "\t| Sansa za critical strike: " << crit << "%" << endl
	     << "===============================================\n\n";
}


//implementacija metoda za borbu
void Lik::potez(Lik& b){
	
	 short x; //Promjenjiva za odabir napada
	 
	 
	 //do-while koji omogucava validan unos i provjeru iskoristioSpec da se moze iskljucivo jednom koristiti
	 do{
	     cout << "Odaberi napad: \t1---LAKI NAPAD\n\t        2---SPECIJALNI NAPAD "
	     << (iskoristioSpec ? "(Iskoristen)\n" : "(nije koristen)\n") 
	     << "UNESI NAPAD: ";
	     cin >> x;
	     if(x == 2 && iskoristioSpec) 
	          cout << "SPECIJALNI NAPAD JE ISKORISTEN\n\n";
	     else if(x < 1 || x > 2)
	          cout << "POGRESAN ODABIR NAPADA\n\n";
	 }while((x == 2 && iskoristioSpec) || (x < 1 || x > 2));
	 
	    switch(x){                            
	    	
	    	//laki napad gdje se provjerava i sansa za critical strike
	    	case 1:{
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
	
	 cout << this->ime << " napada " << b.ime << " lakim napadom (" << this->lakiNapad << "DMG)\n\n";
	//smanjivanje zdravlja za vrijednost
	*b.zdravlje -= lakiNapad;
	
	//izbjegavanje vrijednosti zdravlja da bude manje od nule
    if(*b.zdravlje < 0) *b.zdravlje = 0;

    //prikladan ispis
     cout << b.ime << " je pretrpio " << lakiNapad << "DMG i sada ima " << *b.zdravlje << "HP\n\n";
}

void Lik::speciNapad(Lik &b){
	
	cout << this->ime << " napada " << b.ime << " specijalnim napadom (" << this->specNapad << "DMG)\n\n";
	*b.zdravlje -= specNapad;
	
	   if(*b.zdravlje < 0) *b.zdravlje = 0;
    
     cout << b.ime << " je pretrpio " << specNapad << "DMG i sada ima " << *b.zdravlje << "\n\n";
}

void Lik::kritNapad(Lik& b){
	
	cout << this->ime << " napada " << b.ime << " critical napadom  (" << 2 * this->lakiNapad << "DMG)\n\n";
	*b.zdravlje -= 2 * lakiNapad;
	
    if(*b.zdravlje < 0) *b.zdravlje = 0;
    
     cout << b.ime << " je pretrpio " <<2 * lakiNapad << "DMG i sada ima " << *b.zdravlje << "\n\n";
}


//GLAVNA METODA BORBA
 void Lik::borba(Lik& b){
 	
 	bool flag = true;
 	cout << "BORBA IZMEDJU: " << this->getIme() << "  i  " << b.getIme() << endl;
 	     
 	     while(*this->zdravlje > 0 && *b.zdravlje > 0){
 	     	if(flag){
 	     		cout << this->ime << " je na potezu:\n";
 	     	    	this->potez(b);
			  }
			   else {
			   	  cout << b.ime << " je na potezu\n\n";
			   	   int x = rand()% 2 + 1;
			   	    if(x == 2 && !b.iskoristioSpec){
			   	    	b.speciNapad(*this);
					   }
					else b.lahkiNapad(*this);
			   }
			  
			   cout << "\nSTATUS NAKON POTEZA:\n\t" << this->ime << " " << *this->zdravlje << "HP\n\t"
			        << b.ime << " " << *b.zdravlje << "HP\n\n";
			        
			flag = !flag;
		  }
		  if(*this->zdravlje)
		         cout << "POBJEDNIK JE: " << this->ime << "!!\n\n";
		         
		   else cout << "POBJEDNIK JE: " << b.ime << "!!\n\n";
 }
