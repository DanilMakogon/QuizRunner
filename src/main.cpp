#include "../headers/functions.h"
#include "../headers/design.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>

using namespace std;

int main() {
	readBase();
	init();
	while (true) {
		intro();
		mainMenu();

		short counter = 0;
		short choose = 0;
		for (short i = 0; i < 20; ++i) {
			showQuestion(i);
			choose = readKey();
			if (checkAnswer(i, choose))
				counter++;
		}
		returnToNormalMode();
	}
	return 0;
}
