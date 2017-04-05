#include "Employee.h"

int Employee::nextIDNum = 100000;

Employee::Employee(){}

Employee::Employee(string fName, string lName, Role* role){
	firstName = fName;
	lastName = lName;
	IDNumber = nextIDNum++;
	size = 0;
	addRole(role);
}

Employee::Employee(string fName, string lName, Role* role, int empNum){
	firstName = fName;
	lastName = lName;
	IDNumber = nextIDNum++;
	size = 0;
	addRole(role);
  setIDNumber(empNum);
}

string Employee::getName(){
	return firstName + " " + lastName;
}

void Employee::setName(string fName, string lName){
	firstName = fName;
  lastName = lName;
}

string Employee::getFirstName(){
	return firstName;
}

void Employee::setFirstName(string fName){
	firstName = fName;
}

string Employee::getLastName(){
	return lastName;
}

void Employee::setLastName(string lName){
	lastName = lName;
}

int Employee::getIDNumber(){
    return IDNumber;
}

int Employee::addRole(Role* role){

  if(!approveRole(role))
	  return -1;

  roles[size++] = role;
  return 1;
}

float Employee::getSalary(){
  float total = 0.0;
  for(int i = 0; i < size; i++){
    total += roles[i]->getPay();
  }
  return total;
}

void Employee::setIDNumber(int empNum){
	IDNumber = empNum;
	if(empNum > nextIDNum)
		nextIDNum = empNum+1;
}
