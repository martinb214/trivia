#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <list>
#include <vector>

class Game{
  private:
	std::vector<std::string> players;

	int places[6];
	int purses[6];

	bool inPenaltyBox[6];

	std::list<std::string> popQuestions;
	std::list<std::string> scienceQuestions;
	std::list<std::string> sportsQuestions;
	std::list<std::string> rockQuestions;

	int currentPlayer;
	bool isGettingOutOfPenaltyBox;

	void askQuestion();
	std::string currentCategory();
	bool didPlayerWin();

  public:
	Game();
	std::string createRockQuestion(int index);
	bool isPlayable();
	bool add(std::string playerName);

	int howManyPlayers();
	void roll(int roll);

	bool wasCorrectlyAnswered();
	bool wrongAnswer();
};

#endif /* GAME_H_ */
