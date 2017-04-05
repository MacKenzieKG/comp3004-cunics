#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <string>
#include "PayrollLoginLoader.h"
#include "EmployeeLoader.h"
#include "Role.h"

class EmployeeManager {
	public:
		EmployeeManager();

	    Employee* getEmployeeByIndex(int);
	    Employee* getEmployeeByID(int);
	    Employee* getEmployeeByName(std::string,std::string);
		
		int addNewEmployee(string,string,string,string,string,string);
		
		vector<Paystub*>* getPaystubsForDate(Date);
		 
	private:
		EmployeeList* employeeList;
		vector<PaystubList*>* paystubList;
    	map<std::string,std::string>* payrollLogin;
};

#endif
