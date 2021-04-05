#include <iostream>
#include "coins.h"
#include <stdlib.h>
// Name: Aryeh Bruce
// ID : 209313907
// Course : 80-515-11


void printWelcomeMessage() {
	std::cout << "***********************************************" << std::endl;
	std::cout << "*             THE COINS GAME                  *" << std::endl;
	std::cout << "***********************************************" << std::endl;
} //print game title

void getNumOfCells(int& numOfCells) {
	while (MIN_BOARD_SIZE > numOfCells || MAX_BOARD_SIZE < numOfCells) {
		std::cout << "Please enter the size of the board (" << MIN_BOARD_SIZE << "-" << MAX_BOARD_SIZE << "): ";
		std::cin >> numOfCells;
		std::cout << std::endl;
	}
} //limit board size

void initBoard(int board[], unsigned int boardSize) {
	for (int i = 0; i < boardSize; ++i) {
		board[i] = 0;
	} //make all spots 0
}

void placeCoins(int board[], unsigned int boardSize) {
	for (int COIN = 0; COIN < NUM_OF_COINS; COIN++) { // place 4 coins
		int random = rand() % boardSize;
		while (board[random] == 1) {
			random = rand() % boardSize;
		}  //ensure the coin will not be placed in the same box
		board[random] = 1;
	}
}

void makeMove(int board[], unsigned int boardSize, int playerNum) {
	int coinNum, coinLoc;
	{
		std::cout << std::endl;
		std::cout << "Player " << playerNum << ", please choose the coin to move: ";
		std::cin >> coinNum;
		std::cout << std::endl;
	} //print messages to start the turn
	while (coinNum == 1 || board[coinNum - 2] == 1 || board[coinNum - 1] == !1 || boardSize < coinNum || 1 > coinNum) {
		if (board[coinNum - 1] == !1 && boardSize >= coinNum && 1 <= coinNum) {
			std::cout << "Error: no coin in this location." << std::endl << std::endl;
			std::cout << "Player " << playerNum << ", please choose the coin to move: ";
			std::cin >> coinNum;
			std::cout << std::endl;
			continue;
		}  // within the board and a coin
		if (coinNum == 1 || board[coinNum - 2] == 1) {
			std::cout << "Error: no place to move this coin." << std::endl << std::endl;
			std::cout << "Player " << playerNum << ", please choose the coin to move: ";
			std::cin >> coinNum;
			std::cout << std::endl;
			continue;
		}  // cant move the coin in the first spot or any with one right after it
		if (boardSize < coinNum || 1 > coinNum) {
			std::cout << "Error: invalid location of coin." << std::endl << std::endl;
			std::cout << "Player " << playerNum << ", please choose the coin to move: ";
			std::cin >> coinNum;
			std::cout << std::endl;
			continue;
		} //coin not on board
		std::cout << std::endl;
	} //any problamatic coin
	{
		std::cout << "Please choose the new location of this coin: ";
		std::cin >> coinLoc;
		std::cout << std::endl;
	} //print messages to find location
	while (board[coinLoc - 1] == 1 || coinNum < coinLoc || coinLoc < 1) {
		if (coinNum < coinLoc || coinLoc < 1) {
			std::cout << "Error: only left moves are allowed." << std::endl << std::endl;
			std::cout << "Please choose the new location of this coin: ";
			std::cin >> coinLoc;
			std::cout << std::endl;
			continue;
		} // so the coin moves left
		if (board[coinLoc - 1] == 1) {
			std::cout << "Error: this location is already used." << std::endl << std::endl;
			std::cout << "Please choose the new location of this coin: ";
			std::cin >> coinLoc;
			std::cout << std::endl;
			continue;
		} // two coins in the same location
	} //all problamatic locations
	for (int i = 0; i < coinNum - coinLoc; ++i) {
		if (board[coinNum - 2 - i] == 1) {
			std::cout << "Error: passing another coin is not allowed." << std::endl << std::endl;
			std::cout << "Please choose the new location of this coin: ";
			std::cin >> coinLoc;
			std::cout << std::endl;
			while (board[coinLoc - 1] == 1 || coinNum < coinLoc || coinLoc < 1) {
				if (coinNum < coinLoc || coinLoc < 1) {
					std::cout << "Error: only left moves are allowed." << std::endl << std::endl;
					std::cout << "Please choose the new location of this coin: ";
					std::cin >> coinLoc;
					std::cout << std::endl;
					continue;
				} // so the coin moves left
				if (board[coinLoc - 1] == 1) {
					std::cout << "Error: this location is already used." << std::endl << std::endl;
					std::cout << "Please choose the new location of this coin: ";
					std::cin >> coinLoc;
					std::cout << std::endl;
					continue;
				} // two coins in the same location
			} //all problamatic locations
			i = 0;
		}
	} // check all spaces in between

	board[coinNum - 1] = 0;
	board[coinLoc - 1] = 1;
}

void printLine(unsigned int boardSize) {
	for (int i = 0; i < boardSize; i++) {
		std::cout << "---";
	}//print outer lines
	std::cout << std::endl;
}

void printMidBoard(int board[], unsigned int boardSize) {
	for (int i = 0; i <= boardSize; i++) {
		std::cout << "|";
		if (board[i] == 0) {
			std::cout << "  ";
		} // print no coin
		if (board[i] == 1) {
			std::cout << "**";
		} // print coin
	} //print inner boxes
	std::cout << std::endl;
}

void printBoard(int board[], unsigned int boardSize) {
	printLine(boardSize);
	printMidBoard(board, boardSize);
	printLine(boardSize);
} // a function of functions to make the coinsGame more readable

bool isGameOver(int board[], unsigned int boardSize) {
	int indicator = 0;
	for (int i = 0; NUM_OF_COINS > i; i++) {
		if (board[i] == 1) {
			indicator++;
		}
	}
	if (indicator <= NUM_OF_COINS-1) {
		return true;
	}
	else {
		return false;
	}
}//check if all four slots are full

void printGameSummary(int board[], unsigned int boardSize, int player) {
	printBoard(board, boardSize);
	std::cout << std::endl;
	std::cout << "*** WINNER: PLAYER " << player <<" ***" << std::endl << std::endl;
} //declare winner
