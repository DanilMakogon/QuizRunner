#include "../headers/functions.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>

using namespace std;

vector< baseStruct > dataBase;

int readBase(char *filename) {
	ifstream ist(filename);
	baseStruct tempStruct;
	while(!ist.eof()) {
		ist >> tempStruct.ques >> tempStruct.ans1 >> tempStruct.ans2 >> tempStruct.ans3 >> tempStruct.ans4 >> tempStruct.right_ans;
		dataBase.push_back(tempStruct);
		if (ist.eof())
			break;
	}
	return dataBase.size();
}

int readKey() {
	initscr();
	echo();
	char c;
	scanf("%c", &c);
	switch(c) {
		case 'a': case 'A': case '1': {
			return 1;
			break;
		}
		case 'b': case 'B': case '2': {
			return 2;
			break;
		}
		case 'c': case 'C': case '3': {
			return 3;
			break;
		}
		case 'd': case 'D': case '4': {
			return 4;
			break;
		}
	}
	return -1;
}