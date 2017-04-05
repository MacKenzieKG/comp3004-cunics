using namespace std;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "defs.h"
#include "Role.h"
#include "PaystubList.h"

class EmployeeLoader;

class Employee{
  friend EmployeeLoader;
	public:
		Employee();
		Employee (string, string);
    	Employee (string, string, int); //Use this constructor when loading from the files

    	string getName();
		void setName(string,string);
		string getFirstName();
		void setFirstName(string);
		string getLastName();
		void setLastName(string);
		Date getStartDate();
		void setStartDate(Date);
    
    	int getIDNumber();
    
		int addRole(Role*);
    	int removeRole(Role*);
    	int removeRole(RoleType);
    
		double getSalary();

        void generateNewPaystub();
	
	protected:
        int size;
		int IDNumber;
        static int nextIDNum;
		string firstName,lastName;
		Role* roles[3];
		EmployeeType employeeType;
		Date startDate;
    
		void setIDNumber(int); //Will update the next ID num
    	virtual bool approveRole(Role*) = 0; //The two types of employee approve roles differently
};

#endif
