#include <iostream>
#include <stdexcept>
#include "card_deck.hpp"

using namespace std;

const string DEALER = "DEALER";
const string PLAYER = "PLAYER";

int cash{1500};
int total_bet{0};


vector<int> value_of_hand(vector<card> hand){
	vector<int> vsum{0,0};
	for(vector<card>::const_iterator it = hand.begin(); it != hand.end(); it++){
		card c = *it;
		if(c.get_value() < 11){
			vsum.at(0) += c.get_value();
			vsum.at(1) += c.get_value();
		}
		else if(c.get_value() < 14){             //value of face cards
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

int highest_legal_value_of_hand(vector<card> hand){
	vector<int> v = value_of_hand(hand);
	
	if(v[0] <= 21 && v[1] <= 21) {
		if(v[0] > v[1]) return v[0];
		else return v[1];
	}

	if(v[0] <= 21 && v[1] > 21) return v[0];
	else if(v[0] > 21 && v[1] <=21)	return v[1];

	else return 0;
}


void bet(){
	int input_bet{0};
	cout << "Enter bet: " << endl;
	cin >> input_bet;
	if(cin.fail()) throw invalid_argument("Wrong input type!");
	if(input_bet > cash){
		cout << "Not enough cash!" << endl;
		bet();
	}
	if(input_bet < 0){
		cout << "Positive number!" << endl;
	}
	cash -= input_bet;
	total_bet += input_bet;
	cout << "Bet totalling: " << total_bet << endl;
	cout << "Remaining cash: " << cash << endl;
}
// Takes card_deck pointer as argument in case of multiple card decks
void deal_cards(card_deck *cd, vector<card> *hand, int n){
	for(int i = 0; i<n; i++) hand->push_back(cd->pull_card());	
}

// print cards + highest/best value of the hand
void print_hand(vector<card> hand){	
	for(vector<card>::const_iterator it = hand.begin(); it != hand.end(); it++){
		card c = *it;
		cout << c.get_type() << c.get_value() << " ";
	}
	
	int v = highest_legal_value_of_hand(hand);
	string value{""};
	if(v == 0) value = "Over 21!";
	else value = " " + to_string(v);
	cout << "\t\t" << value << endl;
}

// hides 2nd card from user
void print_dealerhand(vector<card> hand){
	int v = hand[0].get_value();
	if(v>10 && v < 14) v = 10;
	else if(v == 14) v = 11;
	cout << hand[0].to_string() << "\t\t " << to_string(v) << endl;
}

bool values_or_comp(vector<card> hand, int v){
	if(value_of_hand(hand)[0] > v || 
	   value_of_hand(hand)[1] > v) return true;

	return false;
}
bool values_and_comp(vector<card> hand, int v){
	if(value_of_hand(hand)[0] > v && 
	   value_of_hand(hand)[1] > v) return true;

	return false;
}

int main(){
	vector<card> player_hand;
	vector<card> dealer_hand;

	cout << "Welcome to Blackjack Quest!" << endl;
	while(cash > 0){
		card_deck cd{};
		bet();

		// initial hand out
		deal_cards(&cd, &player_hand, 2);
		deal_cards(&cd, &dealer_hand, 2);

		while(true) {
			string user_input{""};
			print_hand(player_hand); print_dealerhand(dealer_hand);

			if(values_or_comp(player_hand,21)){
				cout << "Blackjack!" << endl;
				break;
			}

			if(values_and_comp(player_hand, 21)){
				cout << "You bust out!" << endl;
				break;
			}

			bool dealer_done = false;
			
			cout << "Type 'hit' or 'stand'" << endl;
			cin >> user_input;
			if(user_input == "hit"){
				deal_cards(&cd, &player_hand, 1);
			}else if(user_input == "stand"){
				// dealer plays
				while(true){
					// dealer must hit below 17
 					if(!(values_or_comp(dealer_hand, 17))){
 						cout << "here" << endl;
 						deal_cards(&cd, &dealer_hand, 1);
 					} else{
 						dealer_done = true;
 						break;
 					}
 				}				
			}
			if(dealer_done) break;
		}

		print_hand(player_hand); print_hand(dealer_hand);

		cout << "Dealer: " << highest_legal_value_of_hand(dealer_hand) << endl;
		cout << "You: " << highest_legal_value_of_hand(player_hand)<<endl;	
		
		if(highest_legal_value_of_hand(dealer_hand) < 
		   highest_legal_value_of_hand(player_hand)){
			cout << "You won this round!" << endl;
		} else if(highest_legal_value_of_hand(dealer_hand) >
				  highest_legal_value_of_hand(player_hand)){
			cout << "You lost!" << endl;
		} else cout << "Equal hands" << endl;
		
		total_bet = 0;
		player_hand.clear(); dealer_hand.clear();
	}
}