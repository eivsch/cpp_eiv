Bruker ikke 'new' noe sted.

lager en egen standalone funksjon for beregning av poeng en hånd har.
Måtte evt vært en medlemsfunksjon i card_deck, men verdiene gjelder jo kun
for blackjack så unødvendig.

har en global variabel (struct) for et spillkort. Kunne kanskje gjort dette
annerledes/mer kompakt. Er nødt til å ha det slik med dette designet, for
å kunne lage 'hender' i f.eks main() som inneholder kort. 
Kunne f.eks gjort det slik at et spillkort kun ble definert av en string = 
"H8", eller gjort klassen card_deck mer generell, f.eks card_hand og brukt
den som datastruktur for kortene. Mulig det finnes andre bedre løsninger på
det også.