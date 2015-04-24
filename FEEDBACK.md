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


---

# Oblig 2

### Resultat: 
Godkjent


### Checklist:
* [/] Prosjektet innholder makefile med følgende kommando:
	* [x] `make` - bygger fireworks
	* [x] `make fireworks` - bygger fireworks
	* [x] `make fireworks2` - bygger fireworks2
	* [/] `make clean` - fjerner alle kompilerte filer
	
* [x] **fireworks** oppfyller kravene.
	* [x] Raketter starter på forskjellig tid og plass.
	* [x] Raketter har dotter med en hastighet og med ulike farger (med overvekt av en farge) og retning.
	* [x] Arv og polymorfi er brukt slikt det er tenkt.
	
* [x] **fireworks2** oppfyller kravene.
	* [x] Factory er implementert.
	* [x] Template er implementert.

* [x] Header-filene skal være uforandret.
* [x] Ingen alvorlige kjøretidsfeil (segfault etc.)
* [] Ingen minnelekasjer funnet med `valgrind`.
* [x] Repo innholder `answers_to_questions.md`.
	* [x] Spørsmålene er godt besvart.

* [] Det er laget en egen animasjon **(optional)**
	* [] Kompileres med `make custom`.
	* [] `animation_canvas` og `animated` er brukt.
	* [] Minst tre animerte elementer.


### Tilbakemelding:
*Kommentar gis ved forespørsel.*

`make clean` fjerner alle .o filer, men ikke `fireworks` og `fireworks2`. Det er også noen minnelekkasjer - her er det glemt å implementere flere destructors (animation_canvas deleter alle parts, rocket deleter alle dots etc.). I fireworks2 sender du også med factories, uten å slette disse i rocket2 etter de er brukt. Er godkjent, men husk på å rydde opp etter deg i minnet (viktig!).

#### Fix:

---
