#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Card.h"

using namespace std;

PokerCard::PokerCard()
{
	suits = 1+(rand()%4);
	value = 1+(rand()%13);
}

PokerCard::PokerCard(int x, int y)
{
	suits = x;
	value = y;
}

void PokerCard::setSuits(int x)
{
	suits = x;
}

int PokerCard::getSuits()const
{
	return suits;
}

void PokerCard::setValue(int x)
{
	value = x;
}

int PokerCard::getValue()const
{
	return value;
}

// 1 = cubes, 2 = diamonds, 3 = hearts, 4 = spades
void PokerCard::print()const
{
	string w;

	switch (suits) {
	case 1:
		w = "Cubes ";
		break;
	case 2:
		w = "Diamonds ";
		break;
	case 3:
		w = "Hearts ";
		break;
	case 4:
		w = "Spades ";
		break;
	}
	cout << fixed << setw(12) << w << " " << value;
}
