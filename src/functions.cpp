#include "../headers/functions.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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
	return 0;
}
