#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <list>
#include <vector>

#include "Player.hxx"

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
};

#endif /* GAME_H_ */
