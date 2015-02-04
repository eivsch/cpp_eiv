#include "card.hpp"

using namespace std;

card::card(char t, int v) : type{t}, value{v}
{
}

char card::get_type(){
	return type;
}

int card::get_value(){
	return value;
}

void card::set_type(char c){
	type = c;
}

void card::set_value(int v){
	value = v;
}

string card::to_string(){
	string s{type};
	return s + std::to_string(value);
}