/* This is a file for testing the classes and compliling code
 * It was created by Nicholas Bright on March 31 2017
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Date.h"
#include "Role.h"
#include "Employee.h"
#include "ContinuingEmployee.h"
#include "TermEmployee.h"
#include "Paystub.h"
#include "EmployeeLoader.h"
#include "EmployeeList.h"
#include "EmployeeManager.h"

using namespace std;

class foo{
	public:
		virtual void func(){
			cout << "Hello world" << endl;
		}
};

class bar: public foo{
	public:
		void func(){
			cout << "Hello to the world" << endl;
		}
};

int main(int argc, char** argv){
  EmployeeLoader* employeeLoader = new EmployeeLoader("employees.csv");
  EmployeeList* employeeList = new EmployeeList();
  employeeLoader->loadTo(employeeList);
  for(int i=0;i<employeeList->size();i++){
    Employee* emp = employeeList->getEmployeeByIndex(i);
	cout << "Name: ------ " << emp->getName() << endl;
    cout << "ID: -------- " << emp->getIDNumber() << endl;
    cout << "Type: ------ ";
	if(emp->getEmployeeType() == TERM)
    	cout << "Term Employee";
    else if(emp->getEmployeeType() == CONTINUING)
    	cout << "Continuing Employee";
    cout << endl;
    cout << "Num roles: - " << emp->getSize() << endl;
    cout << "Salary: ---- " << fixed << setprecision(2) << "$" << emp->getSalary() << endl << endl;
  }
  cout << endl << endl << "TESTING ROLES" << endl << endl;
  for(int x=1;x<=10;x++){
	  Employee* first = employeeList->getEmployeeByID(x);
	  cout << "Name: " << first->getName() << endl;
	  cout << "ID: " << first->getIDNumber() << endl << endl;
	  for(int i=0;i<first->getSize();i++){
	  	Role* role = first->getRoles()[i];
		cout << "Type: ";
		if(role->getRoleType() == FACULTY)
			cout << "Faculty";
		else if(role->getRoleType() == STAFF)
			cout << "Staff";
		else if(role->getRoleType() == RA)
			cout << "RA";
		else if(role->getRoleType() == TA)
			cout << "TA";
		cout << endl << "Time: ";
		if(role->getRoleTime() == FULL_TIME)
			cout << "Full-time";
		else if(role->getRoleTime() == PART_TIME)
			cout << "Part-time";
		cout << endl << "Pay: " << role->getPay() << endl << endl;
	  }
  }
  EmployeeManager employeeManager;
  /*foo* a = new foo();
  foo* b = new bar();
  a->func();
  b->func();*/
  system("PAUSE");
  return 0;
}
