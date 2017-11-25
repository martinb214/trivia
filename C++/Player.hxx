#ifndef PLAYER_HXX_
#define PLAYER_HXX_

#include <iostream>
#include <stdlib.h>

class Player{
  private:
	const std::string name;
	int place;
	int purse;
	bool inPenaltyBox;

  public:
	Player(std::string newName) : name(newName), place(0), purse(0), inPenaltyBox(false){};

	const std::string &getName() { return name; };
	const int &getPlace() { return place; };
	const int &getPurse() { return purse; };
	const bool &getInPenaltyBox() { return inPenaltyBox; };

	void setPlace(int newPlace){
		place = newPlace;
		if (place > 11) place -= 12;
	};
	void setPurse() { purse++; };
	void setInPenaltyBox(){
		if (inPenaltyBox)
			inPenaltyBox = false;
		else
			inPenaltyBox = true;
	};

	int roll() { return (rand() % 5 + 1); };
	int answer() { return (rand() % 9); };
};

#endif /* PLAYER_HXX_ */
