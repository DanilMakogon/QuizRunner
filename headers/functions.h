#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>

using namespace std;

struct baseStruct {
	string ques;
	string ans1;
	string ans2;
	string ans3;
	string ans4;
	short right_ans;
};

extern vector< baseStruct > dataBase;


int readBase();
int readKey();
bool checkAnswer(short questionNumber, short choose);
void endProgramm();

#endif
