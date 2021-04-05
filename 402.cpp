#include <iostream>
#include "coins.h"

// Name: Aryeh Bruce
// ID : 209313907
// Course : 80-515-11


void coinsGame() {
	int boardSize,winner;
	int arrCoins[MAX_BOARD_SIZE] = {};
	printWelcomeMessage();
	getNumOfCells(boardSize);
	initBoard(arrCoins, boardSize);
	placeCoins(arrCoins, boardSize);
	printBoard(arrCoins, boardSize);
	isGameOver(arrCoins, boardSize);
	bool flag = isGameOver;
	winner = 1;
	
	while (flag != 0) {
		makeMove(arrCoins, boardSize, winner);
		flag = isGameOver(arrCoins, boardSize);
		if (flag != 0) {
			printBoard(arrCoins, boardSize);
			if (winner == NUM_OF_PLAYERS) {
				winner = 1;
				continue;
			} // dont go over player num
			winner++; //next player
		} // dont print last time
	}
	printGameSummary(arrCoins, boardSize, winner);
}