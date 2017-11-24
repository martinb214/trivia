#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>

class Player{
	private:
		const std::string name;
		int place;
		int purse;
		bool inPenaltyBox;
	public:
		Player(std::string newName): name(newName), place(0), purse(0), inPenaltyBox(false) {};
		
		const std::string& getName() {return name; };
		const int& getPlace() {return place; };
		const int& getPurse() {return purse; };
		const bool& getInPenaltyBox() {return inPenaltyBox; };

		void setPlace(int newPlace) {place = newPlace; if(place > 11) place -= 12; };
		void setPurse() {purse++; };
		void setInPenaltyBox(){
			if(inPenaltyBox) inPenaltyBox = false;
			else inPenaltyBox = true; 
		};

		int roll() { return (rand() % 5 + 1); };
		int answer() {return (rand() % 9); };
};

class Game{
  private:
	std::vector<Player> players;
	int currentPlayer;
	bool hasWinner;

	std::list<std::string> popQuestions;
	std::list<std::string> scienceQuestions;
	std::list<std::string> sportsQuestions;
	std::list<std::string> rockQuestions;

	void askQuestion();
	std::string currentCategory();
	bool didPlayerWin();

  public:
	Game();

	void playGame();	
	
	std::string createRockQuestion(int index);
	bool isPlayable();
	bool add(std::string playerName);

	int howManyPlayers();
};

#endif /* GAME_H_ */
