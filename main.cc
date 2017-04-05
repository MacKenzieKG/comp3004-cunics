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

using namespace std;

int main(int argc, char** argv){
  Date* today = new Date();
  Role* role1 = new Role(PART_TIME, TA, 12038.51);
  Role* role2 = new Role(PART_TIME, RA, 1325.32);
  Role* role3 = new Role(PART_TIME, TA, 7.01);
  Employee* employee = new ContinuingEmployee("Nicholas", "Bright", role1);
  employee->addRole(role2);
  Paystub* paystub = new Paystub();
  cout << "Today is " << today->getYear() << "/" << today->getMonth() << "/" << today->getDay() << endl;
  cout << "Name: " << employee->getFirstName() << " " << employee->getLastName() << endl;
  cout << "Salary: " << fixed << setprecision(2) << employee->getSalary() << endl;
  cout << "ID: " << employee->getIDNumber() << endl;
  cout << "Send help" << endl;
  string test = "Nineteen characters";
  cout << "Test: " << test << endl;
  cout << "Length: " << test.length() << endl;
  system("PAUSE");
  return 0;
}
