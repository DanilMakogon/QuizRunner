#include "../headers/functions.h"
#include "../headers/design.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>

using namespace std;

int main() {
	init();
	intro();
	mainMenu();
	returnToNormalMode();
	return 0;
}
