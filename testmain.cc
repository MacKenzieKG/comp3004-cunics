// testmain.cc
// Testing the DataFileUpdater

#include "DataFileUpdater.h"
#include "EmployeeLoader.h"
#include <iostream>
using namespace std;

int main()
{
	DataFileUpdater dfu;
	EmployeeList empList;
	EmployeeLoader empLoader("employees.csv");
	empLoader.loadTo(&empList);
	
	if (dfu.updateFile("employees2.csv", &empList)) {
		cout << "Success!" << endl;
	}
	else {
		cout << "Failure!" << endl;
	}
	
	return 0;
}
