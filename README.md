# BORBA V1.1 - Tekstualna igra borbe

## 📋 Opis

- Igrač bira jednog od 3 predefinisana karaktera.
- Protivnik se bira iz preostalih karaktera.
- Svaki lik ima svoje statistike: zdravlje, laki napad, specijalni napad, i šansu za kritični udarac.
- Borba se odvija na poteze dok jedan lik ne pobijedi.
- Podržana je logika za specijalne napade i kritične udarce `(kritčan udarac = 2 × laki udarac)`
- Dinamička alokacija i duboka kopija su implementirani.

## 🛠 Tehnologije

- C++
- Objektno-orijentisano programiranje
- Dinamička alokacija memorije

## 🆕 What's New in v1.1

- 🌈 ANSI ESCAPE sekvence: Jedinstvena kombinacija boje i atributa kroz cijelu igru – svaki parametar ima svoju boju
- 🧾 Formatiran i obnovljen ispis na CMD-u: Bolje snalaženje, ljepše iskustvo, grupisanje ispisa
- 🧮 Korištene funkcije biblioteke `<iomanip>`

## 🐞 Bugfixes

- ✅ Ispravljena sintaksna greška u scenariju napada protivnika
- ✅ Obnovljena logika izbornika karaktera


## 🔜 Očekivanja za v1.2

- 🔄 Kombinacija `<thread>` i `<iomanip>` za izradu univerzalne prenosive biblioteke `Animacije.h`, kompatibilne sa sličnim tipovima ispisa


## ✅ Planirano za buduće verzije

- 📄 **Čitanje karaktera iz CSV fajla**  
  Planirana je podrška za učitavanje unaprijed definisanih likova iz `.csv` fajlova, što omogućava fleksibilnije dodavanje sadržaja.

- 🧙 **Kreiranje vlastitog karaktera**  
  Nakon implementacije CSV podrške, korisnici će moći samostalno kreirati i koristiti svoje likove u borbi.

- ⚔️ **Napredni sistemi borbe (otom potom)**  
  U budućnosti se planira dodavanje naprednijih mehanika:
  - Ability slotovi za posebne moći (npr. "povećaj zdravlje za 60 HP", "trovanje: -50 HP po rundi")
  - Efekti koji traju više rundi
  - Veća taktička dubina borbi
