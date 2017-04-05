#ifndef ROLELOADER_H
#define ROLELOADER_H

#include "TermEmployee.h"
#include "ContinuingEmployee.h"
#include "EmployeeList.h"
#include "Faculty.h"
#include "Staff.h"
#include "Ta.h"
#include "Ra.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>


using namespace std;

class RoleLoader {
	public:
        RoleLoader(char*);
	
		int loadTo(Role**);
	private:
		ifstream inFile;
		
        void parseAttribute(string,string*);
        void readAndParse(string*);
};

#endif
