#pragma once

class PokerCard {
private:
	int suits; // 1 = cubes, 2 = diamonds, 3 = hearts, 4 = spades
	int value; // from 1 to 13
public:
	PokerCard();
	PokerCard(int,int);

	void setSuits(int);
	int getSuits()const;
	void setValue(int);
	int getValue()const;

	void print()const;
};