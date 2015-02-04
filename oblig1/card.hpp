#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class card{
	char type;
	int value;
public:
	card(char t, int v);
	// getters
	char get_type();
	int get_value();
	//setters
	void set_type(char c);
	void set_value(int v);

	std::string to_string();
};

#endif