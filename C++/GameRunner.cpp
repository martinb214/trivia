#include "Game.h"

int main(){
	//Original repo's behavior
	//Test for normal number of players
	//Waiting: Normal execute without error
	Game aGame;

	aGame.addPlayer("Chet");
	aGame.addPlayer("Pat");
	aGame.addPlayer("Sue");

	aGame.playGame();

	//Test for one player
	//Waiting: Can't start game, getting error message
	/*
	Game bGame;

	bGame.addPlayer("Bob");

	bGame.playGame();
	*/
	return 0;
}
