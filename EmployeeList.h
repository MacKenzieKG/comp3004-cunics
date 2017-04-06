#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

#include "Employee.h"
#include <vector>

using namespace std;

class EmployeeList {
	public:
		EmployeeList();
		
		int addEmployee(Employee*);
		Employee* getEmployeeByIndex(int);
		Employee* getEmployeeByID(int);
    	Employee* getEmployeeByName(string,string);		
		int size();
		int removeEmployee(int);
		void giveRoleRaiseAmount(RoleType, RoleTime, double);
		void giveRoleRaisePercent(RoleType, RoleTime, double);
		
		Employee* operator[](int);
	private:
    	vector<Employee*>* employeeVector;
};

#endif
