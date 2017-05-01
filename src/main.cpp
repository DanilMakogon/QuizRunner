#include "../headers/functions.h"
#include "../headers/design.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	readBase();
	init();
	short questionNumbers[20];
	while (true) {
		intro();
		mainMenu();
		
		/*srand(time(NULL));
		for (int i = 0; i < 20; ++i)
			questionNumbers[i] = 0;
		for (int i = 0; i < 20; ++i) {
			questionNumbers[i] = rand() % dataBase.size();
			for (int j = i - 1; j >= 0; --j) {
				if (questionNumbers[i] == questionNumbers[j]) {
					--i;
					break;
				}
			}
		}

		short counter = 0;
		short choose = 0;
		for (short i = 0; i < 20; ++i) {
			showQuestion(questionNumbers[i]);
			choose = readKey();
			if (checkAnswer(i, choose))
				counter++;
		}
		*/
		showResult(4);
	}
	endProgramm();
	return 0;
}
