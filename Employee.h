using namespace std;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "defs.h"
#include "Role.h"
#include "PaystubList.h"

#include <iostream>

using namespace std;

class EmployeeLoader;

class Employee{
  friend EmployeeLoader;
	public:
		Employee();
		Employee (string, string, Date);
    	Employee (string, string, int); //Use this constructor when loading from the files

    	string getName();
		void setName(string,string);
		string getFirstName();
		void setFirstName(string);
		string getLastName();
		void setLastName(string);
		Date getStartDate();
		void setStartDate(Date);
		EmployeeType getEmployeeType();
    
    	int getIDNumber();
    
		int addRole(Role*);
    	int removeRole(Role*);
    	int removeRole(RoleType);
    
		virtual double getSalary();
		Role* findRole(RoleType,RoleTime);
		
		Role** getRoles();
		int getSize();
	protected:
        
		int IDNumber;
        static int nextIDNum;
		string firstName,lastName;
		Role* roles[64];
		int size;
		
		EmployeeType employeeType;
		Date startDate;
    
		void setIDNumber(int); //Will update the next ID num
    	virtual bool approveRole(Role*) = 0; //The two types of employee approve roles differently
};

#endif
