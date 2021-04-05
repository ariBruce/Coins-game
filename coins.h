// Name: Aryeh Bruce
// ID : 209313907
// Course : 80-515-11

#pragma once
#ifndef __COINSGAMEDECLR_H__
#define __COINSGAMEDECLR_H__


const unsigned int MIN_BOARD_SIZE=10;
const unsigned int MAX_BOARD_SIZE=25;
const unsigned int NUM_OF_COINS=4;
const unsigned int NUM_OF_PLAYERS=2;

void printWelcomeMessage();
void getNumOfCells(int& numOfCells);
void initBoard(int board[], unsigned int boardSize);
void placeCoins(int board[], unsigned int boardSize);
void printBoard(int board[], unsigned int boardSize);
void printLine(unsigned int boardSize);
void makeMove(int board[], unsigned int boardSize, int playerNum);
bool isGameOver(int board[], unsigned int boardSize);
void printGameSummary(int board[], unsigned int boardSize, int playerNum);


#endif //__COINSGAMEDECLR_H__