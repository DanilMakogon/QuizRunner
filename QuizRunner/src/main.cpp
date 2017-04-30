#include "../headers/functions.h"
#include "../headers/design.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>

using namespace std;

int main() {
	initscr();
	noecho();
	int c = readKey();
	cout << c;
	echo();
	endwin();
	return 0;
}
