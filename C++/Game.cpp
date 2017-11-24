#include "Game.h"

using namespace std;

Game::Game(){
	currentPlayer = 0;
	hasWinner = false;

	for (int i = 0; i < 50; i++){
		string j = to_string(i);
		popQuestions.push_back("Pop Question " + j);
		scienceQuestions.push_back("Science Question " + j);
		sportsQuestions.push_back("Sports Question " + j);
		rockQuestions.push_back("Rock Question " + j);
	}
}

void Game::add(string playerName){
	players.push_back(Player(playerName));

	cout << playerName << " was added" << endl;
	cout << playerName << " is player #" << players.size() << endl;
}

void Game::playGame(){
	if(players.size() >= 2){
		while(!hasWinner){
			cout << players[currentPlayer].getName() << " is the current player" << endl;
			int roll = players[currentPlayer].roll();
			cout << players[currentPlayer].getName() << " has rolled a " << roll << endl;
			
			if(players[currentPlayer].getInPenaltyBox() && roll % 2 == 0){
				cout << players[currentPlayer].getName() << " is not getting out of the penalty box" << endl;
			}else{
				if (players[currentPlayer].getInPenaltyBox()){
					players[currentPlayer].setInPenaltyBox();
					cout << players[currentPlayer].getName() << " is getting out of the penalty box" << endl;
				}
				players[currentPlayer].setPlace(players[currentPlayer].getPlace() + roll);
				cout << players[currentPlayer].getName() << "'s new location is " << players[currentPlayer].getPlace() << endl;
				cout << "Question category is " << gameTable[players[currentPlayer].getPlace()] << endl;
				askQuestion(gameTable[players[currentPlayer].getPlace()]);
				if(players[currentPlayer].answer() == 7){
					cout << "Answer was incorrect!" << endl;
					cout << players[currentPlayer].getName() + " was sent to the penalty box" << endl;
					players[currentPlayer].setInPenaltyBox();
				}else{
					cout << "Answer was corrent!" << endl;
					players[currentPlayer].setPurse();
					cout << players[currentPlayer].getName() << " now has " << players[currentPlayer].getPurse() << " Gold Coins" << endl;
					hasWinner = didPlayerWin();
				}
			}

			currentPlayer++;
			if (currentPlayer == players.size()) currentPlayer = 0;
		}
		cout << players[currentPlayer-1].getName() << " has won the game" << endl;
	}else{
		cout << "Not enough player to start the game!" << endl;
	}
}

void Game::askQuestion(string place)
{
	if (place == "Pop"){
		cout << popQuestions.front() << endl;
		popQuestions.pop_front();
	}else if (place == "Science"){
		cout << scienceQuestions.front() << endl;
		scienceQuestions.pop_front();
	}else if (place == "Sports"){
		cout << sportsQuestions.front() << endl;
		sportsQuestions.pop_front();
	}else if (place == "Rock"){
		cout << rockQuestions.front() << endl;
		rockQuestions.pop_front();
	}
}

bool Game::didPlayerWin(){
	return (players[currentPlayer].getPurse() == 6);
}
