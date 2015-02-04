#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


using namespace std;

	string player_name;
	int cash{1500};
	int bet{0};

//define a global variable playingcard
struct card{
	char type;
	int value;
};

class card_deck{
	vector<card> array_of_cards;
public:
	card_deck(){
		//initialize deck with 52 cards and shuffle
		//H,S,C,D - Hearts, Spades, Clubs, Diamonds 
		array_of_cards.reserve(52);
		for(int i = 2; i<15; i++){	// bruke iterator her?		
			card c{'H', i};
			array_of_cards.push_back(c);
			
			c.type = 'S';
			c.value = i;
			array_of_cards.push_back(c);

			c.type = 'C';
			c.value = i;
			array_of_cards.push_back(c);

			c.type = 'D';
			c.value = i;
			array_of_cards.push_back(c);
		}
		shuffle();
	}
	string to_string(){
		string s;
		for(auto a : array_of_cards){
			s += a.type + std::to_string(a.value) + "\n";
		}
		return s;
	}
	void shuffle(){
		srand(time(NULL));
		int rnd1, rnd2;
		int i{0};
		while(i++ < 1000){
		    // casting .size() as it should never be bigger than 52
			rnd1=rand()%(int)array_of_cards.size(); 
			rnd2=rand()%(int)array_of_cards.size();
			card temp_card = array_of_cards[rnd1];
			array_of_cards[rnd1] = array_of_cards[rnd2];
			array_of_cards[rnd2] = temp_card;
		}
	}
	card pull_card(){
		if(!array_of_cards.empty()){
			card temp_card = array_of_cards.back();
			array_of_cards.pop_back();
			return temp_card;
		} // unntakshåndtering HER!!!!
	}
	int cards_remaining(){
		return array_of_cards.size();
	}
};

vector<int> value_of_hand(vector<card> hand){
	vector<int> vsum{0,0};
	for(vector<card>::const_iterator it = hand.begin(); it != hand.end(); it++){
		card c = *it;
		if(c.value < 11){
			vsum.at(0) += c.value;
			vsum.at(1) += c.value;
		}
		else if(c.value < 14){             //value of face cards
			vsum.at(0) += 10;
			vsum.at(1) += 10;  
		}
		// ace
		else{
			vsum.at(0) += 1;
			vsum.at(1) += 11;
		}
	}
	return vsum;
}

void print_value_of_hand(vector<card> hand){
	vector<int> values = value_of_hand(hand);
	cout << "\nValue of hand: " << values.at(0) << " -or " << values.at(1) <<endl;
}

void bet_message(){
	cout << "Enter bet: " << endl;
	cin >> bet;
	cash -= bet;
	cout << "Remaining cash: " << cash << endl;
}

vector<card> deal_cards(vector<card> v, int n){
	
}

int main(){

	cout << "Welcome! Please type in your name:" <<endl;
	getline(cin, player_name);
	cout << player_name << endl;
	sleep(2);
	bet_message();

	card_deck cd1{};
	cout << cd1.cards_remaining() << "\n" << endl;


	int size_of_hand{3};
	vector<card> hand;
	while(hand.size() < size_of_hand){
		hand.push_back(cd1.pull_card());
	}

	for(vector<card>::const_iterator it = hand.begin(); it != hand.end(); it++){
		cout << (*it).type << (*it).value << endl;
	}

	print_value_of_hand(hand);
}