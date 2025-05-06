#ifndef LIK_H
#define LIK_H

class Lik {                                            //KLASA LIK ce nam sada biti dovoljna za rad (enkapsulacija, getteri {BEZ SETTERA},
 private:                                             // konstruktori, destruktori, i ostale metode vezano za borbu i poteze)
      char* ime;
	  int* zdravlje;
	  int lakiNapad;
	  int specNapad;
	  int crit;              // vrijednost od 1 do 100 koja predstavlja % sanse za kriticni udarac
	  bool iskoristioSpec;
	
 public:
 	
 	  //konstruktor
 	  Lik(const char* i, int z, int ln, int sn, int c);
 	  
 	  //destruktor
 	  ~Lik();
 	  
 	  //duboka kopija
 	  Lik(const Lik& l);
 	  
 	  //Svi getteri jer cu ih koristiti za ispis
 	  const char* getIme() const;
 	  int getZdravlje() const;
 	  int getLakiNapad() const;
 	  int getSpecNapad() const;
 	  int getCrit() const;
 	  bool getIskoristioSpec() const;      //zlu ne trebalo nezz
 	  
 	  void prikazLika() const;
 	  
 	    //setteri u ovoj verziji stvarno nemaju smisla a provjeravat cu sta je dobra sintasa za njih
		 
	 
	  //metode za borbu
      void potez(Lik& b);
	  void lahkiNapad(Lik& b);
	  void speciNapad(Lik& b);
	  void kritNapad(Lik& b);
	  
	     //ova je glavna, u njoj se sve odvija
	  void borba(Lik& b);
	  
		 
};        
#endif                 
