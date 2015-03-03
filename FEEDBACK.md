# Oblig 1

### Resultat: 
Godkjent!


### Checklist:
* [/] Begge programmen bygger med `make`.
* [x] Begge programmen starter og kjører under Linux.
* [x] **oppvarming** gir riktig output.
* [x] **blackjack** har det viktigeste funksjonaliteten.
	* [x] En spiller har et saldo og kan satse et beløp.
	* [x] En spiller har valgen "HIT" og "STAND".
	* [x] En spiller kan ikke fortsette når den har gått tom for penger.
	* [x] Dealerns handlinger virker riktige.
	* [x] Spillet følger reglene til BlackJack.
* [x] Ingen alvorlige kjøretidsfeil (segfault etc.)
* [x] Ingen minnelekasjer funnet med `valgrind`.
* [x] Repo innholder `RAPPORT.md`.



### Tilbakemelding:

Spillet ditt ser fint ut - fint at du lagd en objektorientert løsning med separate filer og header!

Funksjonene ser også greie ut, selvforklarende og enkle å lese. En ting jeg dog savner er representasjon av de kleddekorten, `A J Q K`, da det er litt forvirrende hvilke kort du faktiskt har på hånden når det står f.eks. 11 eller 14.