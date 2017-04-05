#ifndef EMPLOYEELOADER_H
#define EMPLOYEELOADER_H

#define EID 0
#define FIRST_NAME 1
#define LAST_NAME 2
#define ROLE 3
#define HOURS 4
#define TYPE 5
#define START_DATE 6
#define END_DATE 7

#include "TermEmployee.h"
#include "ContinuingEmployee.h"
#include "EmployeeList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

class EmployeeLoader {
	public:
        EmployeeLoader(char*);	
	int loadTo(EmployeeList*);

	private:
	ifstream inFile;
	char id[256];
	char tokenizedLine[52][512];
        void parseAttribute(string,string*);
        void readAndParse(string*);
	int tokenizer(char);
	void readFile(ifstream, EmployeeList*);
};

#endif
