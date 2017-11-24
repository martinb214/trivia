﻿#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

Game::Game() : currentPlayer(0), hasWinner(false){
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

void Game::playGame(){
	if(isPlayable()){
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
				cout << "Question category is " << currentCategory() << endl;
				askQuestion();
				if(players[currentPlayer].answer() == 7){
					cout << "Answer was incorrect!" << endl;
					cout << players[currentPlayer].getName() + " was sent to the penalty box" << endl;
					players[currentPlayer].setInPenaltyBox();
				}else{
					cout << "Answer was corrent!" << endl;
					players[currentPlayer].setPurse();
					cout << players[currentPlayer].getName() << " now has " << players[currentPlayer].getPurse() << " Gold Coins." << endl;
					hasWinner = didPlayerWin();
				}
			}

			currentPlayer++;
			if (currentPlayer == players.size()) currentPlayer = 0;
		}
	}else{
		cout << "Not enough player to start the game!" << endl;
	}
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

bool Game::didPlayerWin(){
	return (players[currentPlayer].getPurse() == 6);
}
