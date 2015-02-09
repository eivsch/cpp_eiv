Rapport
--------------------------------
Målet og ambisjonsnivået var først og fremst å lage et fungerende program, som implementerer de grunnleggende reglene, samt å bli kjent med C++ og få
det inn i fingrene da jeg kom ganske sent til kurset, og ikke hadde rukket å sette meg så mye inn i språket på forhånd.
##Beskrivelse
Programmet er ganske enkelt. Det er klassen card som definerer et spillekort (verdi og type), og klassen card_deck som da inneholder kort, med funksjoner
for å stokke, dele ut OSV. Resten ligger i fila blackjack.cpp, altså selve spilllogikken, I/O med bruker og funksjoner for å regne ut poengsummer og
gevinster. Fokuset var kun på å få spillet til å kjøre godt i terminal her og nå, at det ser ryddig ut og lett og forstå for bruker. Det er 
riktignok endel svakheter når det gjelder unntakshåndtering, som gjør at programmet fort kræsjer hvis bruker gir ugyldig input. All brukerinput
skjer via *cin* og det skapte endel problemer programmeringsmessig som jeg ikke helt klarte/fikk tid til å løse.


##Alternativt Design
Diskutere et alternativt programdesign, hvis du har et, eller idéer til et. Er det noe du ville gjort anderledes? Hvilke fordeler *og evt. ulemper* ville alternativet gitt?
Kunne objektorientert mer, f.eks hatt en egen klasse for brukerinteraksjonen for å få skilt det litt mer fra resten og dermed enklere kunne lagt til
f.eks GUI. Generelt sett 'modularisert' det mer, slik at fremtidige utvidelser hadde blitt enklere.