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

	const std::string gameTable[12] = {"Pop", "Science", "Sports", "Rock",
									   "Pop", "Science", "Sports", "Rock",
									   "Pop", "Science", "Sports", "Rock"};

	std::list<std::string> popQuestions;
	std::list<std::string> scienceQuestions;
	std::list<std::string> sportsQuestions;
	std::list<std::string> rockQuestions;

	void askQuestion(std::string place);
	bool didPlayerWin();

  public:
	Game();

	void add(std::string playerName);
	void playGame();
	
	bool isPlayable();

	int howManyPlayers();
};

#endif /* GAME_H_ */
