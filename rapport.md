Rapport
=======
Målet og ambisjonsnivået var først og fremst å lage et fungerende program, som implementerer de grunnleggende reglene, samt å bli kjent med C++ og få
det inn i fingrene, da jeg kom ganske sent til kurset og ikke hadde rukket å sette meg så mye inn i språket på forhånd.

##Beskrivelse
Programmet er ganske enkelt. Det er klassen card som definerer et spillekort (verdi og type), og klassen card_deck som da inneholder kort, med funksjoner
for å stokke, dele ut OSV. Resten ligger i fila blackjack.cpp, altså selve spilllogikken, I/O med bruker og funksjoner for å regne ut poengsummer og
gevinster. Fokuset var kun på å få spillet til å kjøre godt i terminal her og nå, at det ser ryddig ut og er lett og forstå for bruker. Det er 
riktignok endel svakheter når det gjelder unntakshåndtering, som gjør at programmet fort oppfører seg unaturlig spesielt hvis bruker gir ugyldig input når
innsats oppgis. All brukerinput skjer via *cin* og det skapte endel problemer programmeringsmessig som jeg ikke helt klarte/fikk tid til å løse. I tillegg
bidrar nok selve programdesignen til at det blir vanskeligere.

##Alternativt Design
Kunne objektorientert mer, f.eks hatt en egen klasse for brukerinteraksjonen for å få skilt det litt mer fra resten og dermed enklere kunne lagt til
f.eks GUI. Kunne kanskje også hatt egne klasser for spiller og dealer, og dermed gjøre mer av koden gjenbrukbar til andre spill.
Generelt sett 'modularisert' det mer, og dermed gjort det enklere å bygge på med ny funksjonalitet. Hadde nok også vært lettere å få til skikkelig
unntakshåndtering med et slikt design. Fordelen med det er at programmet blir mer oversiktlig, lettere å forstå og kode/endre for andre, det blir lettere 
å bygge på og gjøre det mer komplekst. Ulempen er vel at det krever muligens mer tid og ikke minst mer kunnskap om språket og hvordan det fungerer.
 