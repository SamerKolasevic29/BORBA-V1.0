
# BORBA V1.0 - Tekstualna igra borbe

Ova verzija predstavlja prvu verziju tekstualne borbene igre implementirane u C++

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

## ✅ Planirano za buduće verzije

- 💡 **Ljepši formatiran tekst preko ANSI escape sekvenci**  
  Planiran je vizualno privlačniji prikaz borbi koristeći ANSI escape kodove, u kombinaciji sa `iomanip` bibliotekom (već pripremljeno u `lik.cpp`).

- 🎞️ **Animacije i fluidnije sekvence borbe**  
  Umjesto jednokratnog ispisa teksta, borba će se prikazivati kao niz stilizovanih animacija i blokova teksta, koristeći `std::chrono` i `std::this_thread::sleep_for` za vremensko upravljanje iz `<chrono>` i `<thread>` biblioteka

- 📄 **Čitanje karaktera iz CSV fajla**  
  Planirana je podrška za učitavanje unaprijed definisanih likova iz `.csv` fajlova, što omogućava fleksibilnije dodavanje sadržaja.

- 🧙 **Kreiranje vlastitog karaktera**  
  Nakon implementacije CSV podrške, korisnici će moći samostalno kreirati i koristiti svoje likove u borbi.

- ⚔️ **Napredni sistemi borbe (otom potom)**  
  U budućnosti se planira dodavanje naprednijih mehanika:
  - Ability slotovi za posebne moći (npr. "povećaj zdravlje za 60 HP", "trovanje: -50 HP po rundi")
  - Efekti koji traju više rundi
  - Veća taktička dubina borbi
