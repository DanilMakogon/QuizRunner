#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
using namespace std;

struct base {
	string ques;
	string ans1;
	string ans2;
	string ans3;
	string ans4;
	short right_ans;
};

int readBase(char *filename);


#endif
