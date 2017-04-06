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
#define SALARY 8

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
		void loadTo(EmployeeList*);

	private:
		ifstream inFile;
		string tokenizedLine[16];
		
		void tokenizer(string);
		int toInt(string);
		double toDouble(string);
		void cleanTokenizedLine();
};

#endif
