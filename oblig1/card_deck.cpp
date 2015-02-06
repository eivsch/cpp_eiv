#include "card_deck.hpp"
#include <stdexcept>
#include <stdlib.h>

using namespace std;

card_deck::card_deck(){
	deck.reserve(52);
		for(int i = 2; i<15; i++){	// bruke iterator her?		
			card c{'H', i};
			deck.push_back(c);
			
			c.set_type('S');
			c.set_value(i);
			deck.push_back(c);

			c.set_type('C');
			c.set_value(i);
			deck.push_back(c);

			c.set_type('D');
			c.set_value(i);
			deck.push_back(c);
		}
		shuffle();
}

void card_deck::shuffle(){
	srand(time(NULL));
	int rnd1, rnd2;
	int i{0};
	while(i++ < 1000){
		rnd1=rand()%(int)deck.size(); 
		rnd2=rand()%(int)deck.size();
		card temp_card = deck[rnd1];
		deck[rnd1] = deck[rnd2];
		deck[rnd2] = temp_card;
	}
}

card card_deck::pull_card(){
	if(!deck.empty()){
		card temp_card = deck.back();
		deck.pop_back();
		return temp_card;
	} else throw runtime_error("Can't pull from empty card deck!");
}

int card_deck::cards_remaining(){
	return deck.size();
}

string card_deck::to_string(){
	string s;
	for(auto a : deck){
		s += a.get_type() + a.get_value() + "\n";
	}
	return s;
}
