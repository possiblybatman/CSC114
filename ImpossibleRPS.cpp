#include <iostream>
#include <string>

using namespace std;

int main() {


	string userChoice;
	
	while (true) {
		cout << "Welcome to the game.\n";
		cout << "Enter rock, paper, or scissors (Enter 'exit' to quit): ";
		cin >> userChoice;
		
		if (userChoice == "exit") {
			cout << "Fine, I didn't want to play anyway!" << endl;
			break;
		}
		
		if (userChoice == "Rock") {
			cout << "Paper, I choose you!" << endl;
			cout << "Paper beats rock, you lose." << endl;
		} else if (userChoice == "paper") {
			cout << "Scissors, get in there!" << endl;
			cout << "Scissors beats paper, you lose." << endl;
		} else if (userChoice == "scissors") {
			cout << "Rock, you got this!" << endl;
			cout << "Rock beats scissors, I win!" << endl;
		} else {
			cout << "Invalid response. Come on, you know the rules." << endl;
		}
	}
	
	return 0;
}
