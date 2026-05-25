#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Card.h"
#include "Player.h"

using namespace std;

void clearConsole() {
	cout << endl << "===========================";
	cout << endl << "\033[2J\033[1;1H";
}

int main(void) {
	srand(time(0)); // ensures the cards don't generate the same number all the time
	/*PokerCard card[10];

	for (int i = 0; i < 10; i++) {
		cout << card[i].getSuits() << " " << card[i].getValue() << endl;
	}

	*/ // debugging kills me

	Player user;
	Player dealer;

	while (user.getCash() > 0) {
		int bet = 0;

		user.resetDeck();
		dealer.resetDeck();

		while (bet <= 0 or bet > user.getCash()) {
			cout << "Your cash : $" << user.getCash() <<  " ; Place your bet: ";

			cin >> bet;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			clearConsole();
		}

		user.drawCard(2);
		dealer.drawCard(2);

		bool end = false;
		int userInput = 0;

		while (end == false) {
			cout << "Your bet is " << bet << endl << endl;

			cout << "Your deck:\n" << endl;

			for (PokerCard card : user.getDeck()) {
				card.print();
			}

			cout << "\n\n" << "Total Value: " << user.getDeckValue() << endl;

			cout << endl;

			cout << "-----------------";

			cout << endl;

			cout << "Dealer's deck:\n" << endl;

			for (PokerCard card : dealer.getDeck()) {
				card.print();
			}

			cout << "\n\n" << "Total Value: " << dealer.getDeckValue() << endl;

			cout << endl;

			if (user.getDeckValue() <= 21 and userInput != 2) {
				cout << "Input 1 to hit, input 2 to stand: ";
				cin >> userInput;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (userInput == 1) {
					user.drawCard(1);
				}
			}
			else {
				if (dealer.getDeckValue() >= 17) {
					break;
				}
				dealer.drawCard(1);
			}
			clearConsole();
		}

		if (user.getDeckValue() > 21 or (dealer.getDeckValue() > user.getDeckValue() and dealer.getDeckValue() <= 21)) {
			user.addCash(-bet);
			cout << "\nBUSTED, you lost $" << bet << endl;
		}
		else if (dealer.getDeckValue() == user.getDeckValue()) {
			cout << "\nPUSH, you keep your $" << bet << endl;
		}
		else if (user.getDeckValue() == 21) {
			user.addCash(bet*2);
			cout << "\nBLACKJACK, you earn double of $" << bet << endl;
		}
		else {
			user.addCash(bet);
			cout << "\nWIN, you earn $" << bet << endl;
		}

		system("pause");

		clearConsole();
	}

	cout << "You have lost all your money! Better luck next time." << endl;

	system("pause");
}