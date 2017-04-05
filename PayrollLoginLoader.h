#ifndef PAYROLLLOGINLOADER_H
#define PAYROLLLOGINLOADER_H

#include "TermEmployee.h"
#include "ContinuingEmployee.h"
#include "EmployeeList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class PayrollLoginLoader {
	public:
        PayrollLoginLoader(char*);
	
		int loadTo(map<string,string>*);
	private:
		ifstream inFile;
		
        void parseAttribute(string,string*);
        void readAndParse(string*);
};

#endif
