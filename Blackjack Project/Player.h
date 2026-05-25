#pragma once

#include <vector>
#include "Card.h"

using namespace std;

class Player {
private:
	vector<PokerCard> deck;
	int cardAmount;
	int cash;
public:
	Player();

	void setCash(int);
	void addCash(int);
	int getCash()const;

	void resetDeck();
	void drawCard(int);

	vector<PokerCard> getDeck();
	int getDeckValue();
};