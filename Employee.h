using namespace std;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "defs.h"
#include "Role.h"
class EmployeeLoader;

class Employee{
  friend EmployeeLoader;
	public:
		Employee();
		Employee (string, string, Role*);
    Employee (string, string, Role*, int); //Use this constructor when loading from the files

    string getName();
		void setName(string,string);
    
		string getFirstName();
		void setFirstName(string);
    
		string getLastName();
		void setLastName(string);
    
    int getIDNumber();
    
		int addRole(Role*);
    
		float getSalary();
	
	protected:
    int size;
		int IDNumber;
    static int nextIDNum;
		string firstName,lastName;
		Role* roles[3];
    
		void setIDNumber(int); //Will update the next ID num
    virtual bool approveRole(Role*) = 0; //The two types of employee approve roles differently
};

#endif
