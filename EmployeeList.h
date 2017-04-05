#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

#include "Employee.h"
#include <vector>

using namespace std;

class EmployeeList {
	public:
		int addEmployee(Employee*);
		Employee* getEmployee(int);
		Employee* getEmployeeByID(int);
		
		Employee* operator[](int);
	private:
        vector<Employee*>* employeeVector;
};

#endif
