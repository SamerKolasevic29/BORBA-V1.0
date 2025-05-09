#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>    //za rand()
#include <ctime>      // za time()
#include <iomanip>    //za setw() i setfill()
#include "Lik.h"
#include "Animation.h"  //od v1.2

//posto nisam od prakse std:: , bar da ih nabrojim
using std::cout;
using std::cin;
using std::endl;
using std::strcpy;
using std::setw;
using std::setfill;
using std::string;
using std::to_string;

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
const char* Lik::getIme() const  {  return ime; }


int Lik::getZdravlje() const   {  return *zdravlje;  }


int Lik::getLakiNapad() const    {  return lakiNapad;  }


int Lik::getSpecNapad() const    {	return specNapad;  }


int Lik::getCrit() const  {	return crit; }


bool Lik::getIskoristioSpec() const   {	return iskoristioSpec; }



//string getteri
string Lik::getZdravljeStr() const {   return to_string(*zdravlje) + "HP"; }


string Lik::getLakiNapadStr() const  {  return to_string(lakiNapad) + "ATK"; }


string Lik::getSpecNapadStr() const {  return to_string(specNapad) + "ATK"; }


string Lik::getCritStr() const { return to_string(crit) + "%"; }


string Lik::getImeStr() const {  return string(ime); }





//Prikladan prikaz lika 
void Lik::prikazLika() const{
	
	cout << "\n\t\t\033[90m"; writeLine("=======================================", 10); cout << "\033[0m\n"
	     << "\033[0m\t\t"; writeLine("| Zdravlje: \033[92m" + this->getZdravljeStr(), 20);
	    cout << "\n\033[0m\t\t"; writeLine("| Laki napad: \033[91m" + this->getLakiNapadStr(), 20);
	    cout << "\n\033[0m\t\t"; writeLine("| Specijalni napad: \033[31m" + this->getSpecNapadStr(),20);
	    cout << "\n\033[0m\t\t"; writeLine("| Sansa za critical strike: \033[93m" + this->getCritStr(), 20);
	    cout << "\n\t\t\033[90m"; writeLine("=======================================", 10); cout << "\033[0m\n\n";
}


//implementacija metoda za borbu
void Lik::potez(Lik& b){
	
	 short x; //Promjenjiva za odabir napada
	 
	 
	 //do-while koji omogucava validan unos i provjeru iskoristioSpec da se moze iskljucivo jednom koristiti
	 do{
	 	
	     writeLine("Odaberi napad: \t\033[91m1---LAKI NAPAD\033[0m\n\t        \033[31m2---SPECIJALNI NAPAD\033[93m ", 30);
	     (iskoristioSpec ? writeLine("(Iskoristen)\n",30) : writeLine("(nije koristen)\n", 30)); 
	     writeLine("\033[0mUNESI NAPAD: ", 30);
	     cin >> x;
	     
	     
	     if(x == 2 && iskoristioSpec) writeLine("\033[31m[SPECIJALNI NAPAD JE ISKORISTEN]\033[0m\n\n", 30);
	     
		 else if(x < 1 || x > 2) writeLine("\033[31m[POGRESAN ODABIR NAPADA]\033[0m\n\n", 30);
	
	 }while((x == 2 && iskoristioSpec) || (x < 1 || x > 2));
	 
	    switch(x){                            
	    	
	    	//laki napad gdje se provjerava i sansa za critical strike
	    	case 1:{
	    		cout << "\033[33m"; writeLine("=======================================================", 10); cout << "\033[0m\n";
	    		
			   int sansa = rand() % 101;

			   if(sansa <= crit)    kritNapad(b);
			   
			   else  lahkiNapad(b);
			   
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
	
	 cout << "\n\033[96m"; 
	 writeLine( this->getImeStr() +"\033[0m napada \033[96m" + b.getImeStr() + "a\033[0m lakim napadom \033[91m(", 30);
     writeLine(this->getLakiNapadStr() + ")\033[0m\n", 30);
     
	//smanjivanje zdravlja za vrijednost
	*b.zdravlje -= lakiNapad;
	
	//izbjegavanje vrijednosti zdravlja da bude manje od nule
    if(*b.zdravlje < 0) *b.zdravlje = 0;

}

void Lik::speciNapad(Lik &b){
	
	cout << "\n\033[96m"; 
	writeLine( this->getImeStr() +"\033[0m napada \033[96m" + b.getImeStr() + "a\033[0m specijalnim napadom \033[31m(", 30);
    writeLine(this->getSpecNapadStr() + ")\033[0m\n", 30);
    
       *b.zdravlje -= specNapad;
	
	   if(*b.zdravlje < 0) *b.zdravlje = 0;
    
}

void Lik::kritNapad(Lik& b){
	
	cout << "\n\033[96m";
	writeLine( this->getImeStr() +"\033[0m napada \033[96m" + b.getImeStr() + "a\033[0m critical napadom \033[6;93m(", 30);
    writeLine(to_string(2 * this->lakiNapad) + "ATK)\033[0m\n", 30);

	*b.zdravlje -= 2 * lakiNapad;
	
    if(*b.zdravlje < 0) *b.zdravlje = 0;
    
}


//GLAVNA METODA BORBA
 void Lik::borba(Lik& b){
 	
 	bool flag = true;
 	
      writeLine("\t ||=== BORBA IZMEDJU: \033[96m" + this->getImeStr(), 50);
      writeLine("\033[0m  i  \033[96m" + b.getImeStr() + "\033[0m ===||\n\n", 50);
 	     
 	     while(*this->zdravlje > 0 && *b.zdravlje > 0){
 	     	
 	     	if(flag){
 	     		
 	     		writeLine("\033[96m" + this->getImeStr() + "\033[93m(ti)\033[0m je na potezu:\n", 30);
 	     	    	this->potez(b);
			  }
			   else {
			   	
			   	cout << "\033[96m"; thinking("\t\tProtivnik razmislja ", 4, 300);
			   	 cout << "\n";
			   	 
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
					
					
			if(!flag) {
				cout << "\033[33m"; writeLine("=======================================================", 10); cout << "\033[0m\n";
			} 
			        
			flag = !flag;
		  }
		  if(*this->zdravlje)
		        writeLine("POBJEDNIK JE: \033[6;96m" + this->getImeStr() + "\033[6;0m!!\033[0m\n\n", 30);
		         
		   else writeLine("POBJEDNIK JE: \033[6;96m" + b.getImeStr() + "\033[6;0m!!\033[0m\n\n", 30);
 }
