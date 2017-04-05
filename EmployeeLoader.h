#ifndef EMPLOYEELOADER_H
#define EMPLOYEELOADER_H

#include "TermEmployee.h"
#include "ContinuingEmployee.h"
#include "EmployeeList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class EmployeeLoader {
	public:
        EmployeeLoader(char*);
	
		int loadTo(EmployeeList*);
	private:
		ifstream inFile;

        void parseAttribute(string,string*);
        void readAndParse(string*);
};

#endif
