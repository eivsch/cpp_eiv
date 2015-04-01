Oppgaver
========

##1. 
   Protected datamedlem vil si at alle subklasser av animated har direkte tilgang til datafeltet.
   Fordelen er altså at det er enkelt for subklassene å gjøre endringer/lese dataene, noe som jo
   ofte er hensiktsmessig i en subklasse. Ulempen er tap av kontroll, da baseklassen ikke lenger 
   har full kontroll over sitt eget datafelt. Dersom det f.eks er svært mange klasser som arver
   kan disse fort bli ustabile når datafeltene i baseklassen endres. Alternativet for animated er 
   å gjøre datafeltet private og ha public/protected metoder som kan aksessere/lese variabelen (get/set).
   Det blir en avveining uten nødvendigvis et fasitsvar. Ettersom animated er en ganske generell klasse,
   kunne det hypotetisk vært slik at svært mange forskjellige klasser ville arve, protected ville
   da antageligvis ikke vært så lurt. Men dersom man har god kontroll på hvem og hvordan klassen
   skal brukes, burde protected fungere helt fint.

2. Er funksjonene draw()/clear() i dot, og konstruktør og timer() i animation_canvas som bruker
   rene FLTK funksjoner. Det er også darken og lighten_color i has_color, samt vindusopprettingen i
   main.cpp. Er i utgangspunktet ikke så fryktelig mye å forandre fra starten av. Bruker også endel
   funksjonen fl_rgb_color() for å konvertere RGB til farge, spesielt i Factory.cpp. Kunne muligens 
   hatt en egen klasse som samlet håndterte alle slike FLTK-funksjoner, slik at man kun ville trengt å
   forandre noe et sted dersom man bestemte seg for å bytte grafikkbibliotek.

3. Man kunne f.eks definere et namespace for dot, da dette er kode som kunne vært brukt andre steder
   i andre typer animasjoner eller med andre animasjonsrammeverk. For da å unngå navnekonflikter
   kunne det være greit med et namespace.

4. Når man bruker draw() metoden i animation_canvas vil denne inkrementere alle objekter som er/arver
   'animated', altså polymorfi. Dette er en god og elegant løsning som krever minimalt med kode.
   Dersom man skulle brukt templates måtte altså draw() vært programmert generisk, det gir ikke så
   mye mening all den tid animation_canvas bruker en vector<animated>, altså allerede impliserer arv.
   Da blir det i tilfelle mer unødvendig kode og en mindre elegant løsning, større sannsyligheter for
   programmeringsfeil etc. Fordelen med å bruke templates måtte isåfall være at man kan bruke samme
   draw() funksjon for å tegne opp objekter som ikke arver 'animated', for det er begrensningen ved
   en polymorfisk løsning. Såvidt jeg kan se må det da gjøres endel endringer i designen for at det
   skal være mulig. Spørsmålet er jo også om det er ønskelig i et så 'enkelt' program, dersom man
   skulle gjort det mye mer avansert og laget mye mer enn bare raketter hadde det vært mer naturlig.

5. Programmet og designen fungerer stort sett fint i forhold til hva som var intensjonen og målet
   med programmet. Det kan sikkert riktignok alltid gjøres mer 'clean' og gjenbrukbart, jmf. tidligere
   oppgaver, f.eks kunne det sikkert vært enda mer generisk slik at man kunne tenget opp/animert flere
   typer objekter samtidig enn bare raketter (dots) og fått god ytelse. En annen som kan nevnes er 
   klassen is_vector som kun gir en tilfeldig retning og fart til vektorene, den kunne vært utvidet
   slik at man selv kan sende med retning og fart for å få de grafiske elementene til å bevege seg
   i andre mønstre. 