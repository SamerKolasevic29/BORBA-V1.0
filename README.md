
# BORBA V1.2 - Tekstualna igra borbe

## 📋 Opis

- Igrač bira jednog od 3 predefinisana karaktera.
- Protivnik se bira iz preostalih karaktera.
- Svaki lik ima svoje statistike: zdravlje, laki napad, specijalni napad, i šansu za kritični udarac.
- Borba se odvija na poteze dok jedan lik ne pobijedi.
- Podržana je logika za specijalne napade i kritične udarce `(kritičan udarac = 2 × laki udarac)`
- Dinamička alokacija i duboka kopija su implementirani.

## 🛠 Tehnologije

- C++
- Objektno-orijentisano programiranje
- Dinamička alokacija memorije

## 🆕 What's New in v1.2

- 🎞 **Animation.h – Prilagođeni animacijski sistem**  
  Implementirana je prenosiva i modularna zaglavlja `Animation.h`, bazirana na standardnim bibliotekama `<thread>` i `<chrono>`, omogućavajući dinamičan i fluidan ispis (npr. simulacija razmišljanja, postepeno ispisivanje teksta).  
  Kompatibilno sa drugim C++ projektima zahvaljujući univerzalnom dizajnu i čistoći implementacije.


## 🔜 Očekivanja za v1.3

- 📂 **Učitavanje likova iz `lista.csv` fajla**  
  Likovi će biti definisani u CSV fajlu, omogućavajući jednostavno proširenje baze karaktera.

- 🎮 **Režimi igre: Singleplayer & 1v1**  
  Planirano je uvođenje opcije da se igra protiv drugog igrača ili protiv AI protivnika.

- 🎯 **Precizniji sistem vjerovatnoće**  
  Implementacija nasumičnosti pomoću standardne biblioteke `<random>` radi tačnijeg i stabilnijeg izračuna vjerovatnoće za kritične udarce.
