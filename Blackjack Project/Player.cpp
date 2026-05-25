#include <vector>
#include "Card.h"
#include "Player.h"

using namespace std;

Player::Player(){
	cash = 1000;

	resetDeck();
}

void Player::setCash(int x)
{
	cash = x;
}

void Player::addCash(int x)
{
	cash += x;
}

int Player::getCash()const
{
	return cash;
}

void Player::resetDeck()
{
	deck.clear();
	cardAmount = 0;
}

void Player::drawCard(int times)
{
	while (times > 0) {
		deck.push_back(PokerCard());
		cardAmount++;

		times--;
	}
}

vector<PokerCard> Player::getDeck()
{
	return deck;
}

int Player::getDeckValue()
{
	int totalValue = 0;
	int totalAces = 0;

	for (PokerCard card : deck) {
		if (card.getValue() > 1 and card.getValue() < 10) {
			totalValue += card.getValue();
		}
		else if (card.getValue() == 1) {
			totalValue += 11;
			totalAces++;
		}
		else {
			totalValue += 10;
		}
	}
	
	while (totalValue > 21 and totalAces > 0) {
		totalValue -= 10;
		totalAces--;
	}

	return totalValue;
}
