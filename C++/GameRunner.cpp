#include "Game.h"

int main(){
	//Original repo's behavior
	//Test for normal number of players
	//Waiting: Normal execute without error
	Game aGame;

	aGame.add("Chet");
	aGame.add("Pat");
	aGame.add("Sue");

	aGame.playGame();

	//Test for one player
	//Waiting: Can't start game, getting error message
	/*
	Game bGame;

	bGame.add("Bob");

	bGame.playGame();
	*/
	return 0;
}
