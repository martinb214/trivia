#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

Game::Game() : currentPlayer(0){
	for (int i = 0; i < 50; i++){

		ostringstream oss(ostringstream::out);
		oss << "Pop Question " << i;

		popQuestions.push_back(oss.str());

		char str[255];
		sprintf(str, "Science Question %d", i);
		scienceQuestions.push_back(str);

		char str1[255];
		sprintf(str1, "Sports Question %d", i);
		sportsQuestions.push_back(str1);

		rockQuestions.push_back(createRockQuestion(i));
	}
}

string Game::createRockQuestion(int index){
	char indexStr[127];
	sprintf(indexStr, "Rock Question %d", index);
	return indexStr;
}

bool Game::isPlayable(){
	return (howManyPlayers() >= 2);
}

bool Game::add(string playerName){
	players.push_back(Player(playerName));

	cout << playerName << " was added" << endl;
	cout << playerName << " is player #" << players.size() << endl;
}

int Game::howManyPlayers(){
	return players.size();
}

void Game::roll(int roll){
	cout << players[currentPlayer].getName() << " is the current player" << endl;
	cout << "They have rolled a " << roll << endl;

	if (players[currentPlayer].getInPenaltyBox()){
		if (roll % 2 != 0){
			isGettingOutOfPenaltyBox = true;

			cout << players[currentPlayer].getName() << " is getting out of the penalty box" << endl;
			players[currentPlayer].setPlace(players[currentPlayer].getPlace() + roll);
			if (players[currentPlayer].getPlace() > 11)
				players[currentPlayer].setPlace(players[currentPlayer].getPlace() - 12);

			cout << players[currentPlayer].getName() << "'s new location is " << players[currentPlayer].getPlace() << endl;
			cout << "The category is " << currentCategory() << endl;
			askQuestion();
		}else{
			cout << players[currentPlayer].getName() << " is not getting out of the penalty box" << endl;
			isGettingOutOfPenaltyBox = false;
		}
	}else{
		players[currentPlayer].setPlace(players[currentPlayer].getPlace() + roll);
		if (players[currentPlayer].getPlace() > 11)
			players[currentPlayer].setPlace(players[currentPlayer].getPlace() - 12);

		cout << players[currentPlayer].getName() << "'s new location is " << players[currentPlayer].getPlace() << endl;
		cout << "The category is " << currentCategory() << endl;
		askQuestion();
	}
}

void Game::askQuestion()
{
	if (currentCategory() == "Pop"){
		cout << popQuestions.front() << endl;
		popQuestions.pop_front();
	}
	if (currentCategory() == "Science"){
		cout << scienceQuestions.front() << endl;
		scienceQuestions.pop_front();
	}
	if (currentCategory() == "Sports"){
		cout << sportsQuestions.front() << endl;
		sportsQuestions.pop_front();
	}
	if (currentCategory() == "Rock"){
		cout << rockQuestions.front() << endl;
		rockQuestions.pop_front();
	}
}

string Game::currentCategory(){
	if (players[currentPlayer].getPlace() == 0)
		return "Pop";
	if (players[currentPlayer].getPlace() == 4)
		return "Pop";
	if (players[currentPlayer].getPlace() == 8)
		return "Pop";
	if (players[currentPlayer].getPlace() == 1)
		return "Science";
	if (players[currentPlayer].getPlace() == 5)
		return "Science";
	if (players[currentPlayer].getPlace() == 9)
		return "Science";
	if (players[currentPlayer].getPlace() == 2)
		return "Sports";
	if (players[currentPlayer].getPlace() == 6)
		return "Sports";
	if (players[currentPlayer].getPlace() == 10)
		return "Sports";
	return "Rock";
}

bool Game::wasCorrectlyAnswered(){
	if (players[currentPlayer].getInPenaltyBox()){
		if (isGettingOutOfPenaltyBox){
			cout << "Answer was correct!!!!" << endl;
			players[currentPlayer].setPurse();
			cout << players[currentPlayer].getName()
				 << " now has "
				 << players[currentPlayer].getPurse()
				 << " Gold Coins." << endl;

			bool winner = didPlayerWin();
			currentPlayer++;
			if (currentPlayer == players.size())
				currentPlayer = 0;

			return winner;
		}else{
			currentPlayer++;
			if (currentPlayer == players.size())
				currentPlayer = 0;
			return true;
		}
	}else{
		cout << "Answer was correct!!!!" << endl;
		players[currentPlayer].setPurse();
		cout << players[currentPlayer].getName()
				<< " now has "
				<< players[currentPlayer].getPurse()
				<< " Gold Coins." << endl;

		bool winner = didPlayerWin();
		currentPlayer++;
		if (currentPlayer == players.size())
			currentPlayer = 0;

		return winner;
	}
}

bool Game::wrongAnswer(){
	cout << "Question was incorrectly answered" << endl;
	cout << players[currentPlayer].getName() + " was sent to the penalty box" << endl;
	players[currentPlayer].setInPenaltyBox();

	currentPlayer++;
	if (currentPlayer == players.size())
		currentPlayer = 0;
	return true;
}

bool Game::didPlayerWin(){
	return !(players[currentPlayer].getPurse() == 6);
}
