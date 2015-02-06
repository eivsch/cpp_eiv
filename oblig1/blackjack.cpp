#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include "card_deck.hpp"

using namespace std;

const string DEALER = "DEALER";
const string PLAYER = "PLAYER";

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


void bet(int *cash, int *total_bet){
	int input_bet{0};
	cout << "Enter bet: ";
	
	cin >> input_bet;
	
	if(cin.fail()) throw invalid_argument("Wrong input!");
	if(input_bet > *cash){
		cout << "Not enough cash!" << endl;
	}
	if(input_bet < 0){
		cout << "Positive number!" << endl;
		cin.ignore();
		cin.clear();
		bet(cash,total_bet);
	}
	*cash -= input_bet;
	*total_bet += input_bet;
	cout << "Remaining cash: " << *cash << endl;
}
// Takes card_deck pointer as argument in case of multiple card decks
void deal_cards(card_deck *cd, vector<card> *hand, int n){
	for(int i = 0; i<n; i++) hand->push_back(cd->pull_card());	
}

// print cards + highest/best value of the hand
void print_hand(vector<card> hand){	
	for(vector<card>::const_iterator it = hand.begin(); it != hand.end(); it++){
		card c = *it;
		cout << c.to_string() << " ";
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
bool values_and_comp(vector<card> hand, int v){
	if(value_of_hand(hand)[0] > v && 
	   value_of_hand(hand)[1] > v) return true;

	return false;
}

string decide_round(vector<card> player, vector<card> dealer){
	string s{""};
	if(highest_legal_value_of_hand(dealer) < 
	   highest_legal_value_of_hand(player)){
		s = "\nYou won this round! Please collect you reward: ";
	} else if(highest_legal_value_of_hand(dealer) >
			  highest_legal_value_of_hand(player)){
	 	s = "\nYou lost...";
	} else{ 
		s = "Equal hands!";
	}
	return s;
}

bool continue_game(string message){
	cout << message << endl;
	string s;
	cin.ignore();
	getline(cin,s);
	if(s == "quit") return false;
	else if(s.empty()) return true;
}

/*
void print_current_result(vector<card> player, vector<card> dealer){
	cout << "You: "; print_hand(player); 
	cout << "Dealer: "; print_hand(dealer);
}
*/

int main(){
	int cash{1500}, total_bet{0}, count{1};
	vector<card> player_hand;
	vector<card> dealer_hand;

	cout << "\nWelcome to Blackjack Quest!\n" << endl;
	//game logic
	while(cash > 0){
		if(count%10 == 0) 
			cout << "Your blackjack skill just increased to " + count/10 << endl;
		card_deck cd{};
		bet(&cash, &total_bet);
		
		// initial hand out
		deal_cards(&cd, &player_hand, 2);
		deal_cards(&cd, &dealer_hand, 2);

		continue_game("Press <enter> to hand out cards.");
		
		cout << "You: "; print_hand(player_hand); 
		cout << "Dealer: "; print_dealerhand(dealer_hand);

		if(value_of_hand(player_hand)[0] == 21 || 
	       value_of_hand(player_hand)[1] == 21 ) 
			cout << "Blackjack!" << endl;
		else{
			while(true) {
				string user_input{""};

				if(highest_legal_value_of_hand(player_hand) == 21){
					cout << "You got 21!" << endl;
					break;
				}

				if(values_and_comp(player_hand, 21)){
					break;
				}

				bool dealer_done = false;
			
				cout << "\nType 'hit' or 'stand': ";
				cin >> user_input;
				if(user_input == "hit"){
					deal_cards(&cd, &player_hand, 1);
					cout << "\nYou: "; print_hand(player_hand); 
					cout << "Dealer: "; print_dealerhand(dealer_hand);
				}else if(user_input == "stand"){
					cout << "\n";
					// dealer plays after showing hidden card
					while(true){
						cout << "Dealer: "; print_hand(dealer_hand);
						// dealer must hit below 17
 						if(!(values_and_comp(dealer_hand, 16))){
 							deal_cards(&cd, &dealer_hand, 1);
 							sleep(1);
 						} else{
 							dealer_done = true;
 							break;
 						}
 					}				
				}
				if(dealer_done) break;
			}
		}
		sleep(2);
		cout << decide_round(player_hand, dealer_hand) << endl;
		
		total_bet = 0;
		player_hand.clear(); dealer_hand.clear();
		if(!continue_game("\nPress <enter> for a new round ('quit' to quit playing).")){
			break;
		}
		count++;
	}
	cout << "\nFarewell, hope you enjoyed Blackjack Quest!\n" << endl;
}