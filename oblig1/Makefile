GPP=g++
GPPOPT=-std=c++11

OBJ=oppvarming blackjack

all: $(OBJ)

oppvarming:
	$(GPP) $(GPPOPT) oppvarming.cpp -o oppvarming

blackjack: classes
	$(GPP) $(GPPOPT) blackjack.cpp card.o card_deck.o -o blackjack

classes:
	$(GPP) $(GPPOPT) -c card.cpp
	$(GPP) $(GPPOPT) -c card_deck.cpp


clean: 
	-$(RM) $(OBJ)