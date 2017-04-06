#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <string>
#include <map>
#include "EmployeeLoader.h"
#include "Role.h"

using namespace std;

class EmployeeManager {
	public:
		EmployeeManager();

	    Employee* getEmployeeByIndex(int);
	    Employee* getEmployeeByID(int);
	    Employee* getEmployeeByName(std::string,std::string);
		
		int addNewEmployee(string,string,string,string,string,string,string,string);
		//int giveRoleRaise(string,string,string)
		int removeEmployee(string);
	private:
		EmployeeList* employeeList;
		map<std::string,std::string>* payrollLogin;
};

#endif
