#include "../headers/design.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>

void init() {
	initscr();
	noecho();
	refresh();
}

void intro();
void mainMenu();
void returnToNormalMode() {
	echo();
	endwin();
}