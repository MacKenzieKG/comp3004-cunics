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
		
		Employee* operator[](int);
	private:
    	vector<Employee*>* employeeVector;
};

#endif
