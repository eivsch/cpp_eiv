#ifndef CARD_DECK_HPP
#define CARD_DECK_HPP

#include <vector>
#include <string>
#include "card.hpp"

class card_deck{
	std::vector<card> deck;
public:
	card_deck();
	void shuffle();
	card pull_card();
	int cards_remaining();
	std::string to_string();
};

#endif