#include <iostream>
#include "coins.h"

// Name: Aryeh Bruce
// ID : 209313907
// Course : 80-515-11

void coinsGame();
int main() {
	int replay = 1;
	while (replay == 1) {
		coinsGame();
		std::cout << "Play again? (0-No/1-Yes):";
		std::cin >> replay;
	} //continue the game as long as they want
	std::cout <<std::endl << std::endl <<"Thanks for playing!";
}