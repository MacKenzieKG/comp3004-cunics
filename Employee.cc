#include "Employee.h"

int Employee::nextIDNum = 0;

Employee::Employee(){
	firstName = "";
	lastName = "";
	IDNumber = 0;
	size = 0;
}

Employee::Employee(string fName, string lName, Date sDate){
	firstName = fName;
	lastName = lName;
	IDNumber = nextIDNum++;
	startDate = sDate;
	size = 0;
}

Employee::Employee(string fName, string lName, int empNum){
	firstName = fName;
	lastName = lName;
	IDNumber = nextIDNum++;
	size = 0;
    setIDNumber(empNum);
}

string Employee::getName(){return firstName + " " + lastName;}
void Employee::setName(string fName, string lName){	firstName = fName;lastName = lName;}
string Employee::getFirstName(){return firstName;}
void Employee::setFirstName(string fName){firstName = fName;}
string Employee::getLastName(){return lastName;}
void Employee::setLastName(string lName){lastName = lName;}
int Employee::getIDNumber(){return IDNumber;}
Date Employee::getStartDate(){return startDate;}
void Employee::setStartDate(Date newStart){startDate = newStart;}
EmployeeType Employee::getEmployeeType(){return employeeType;}

int Employee::addRole(Role* role){
  if(!approveRole(role))
	  return -1;

  roles[size] = role;
  size+=1;
  return 1;
}

int Employee::removeRole(Role* role){
  if(size <= 1)
    return -1;

  for(int i=0;i<size;i++){
    if(roles[i] == role){
      for(int x=i+1;x<size;x++){
        roles[i] = roles[x];
        i++;
      }
      size--;
      return 1;
    }
  }
  return -1;
}

int Employee::removeRole(RoleType roleType){
  if(size <= 1)
    return -1;

  for(int i=0;i<size;i++){
    if(roles[i]->getRoleType() == roleType){
      for(int x=i+1;x<size;x++){
        roles[i] = roles[x];
        i++;
      }
      size++;
      return 1;
    }
  }
  return -1;
}

double Employee::getSalary(){
  double total = 0.0;
  for(int i = 0; i < size; i++){
    total += roles[i]->getPay();
  }
  return total;
}

void Employee::setIDNumber(int empNum){
	IDNumber = empNum;
	if(empNum > nextIDNum){
		nextIDNum = empNum+1;
	}
}

Role** Employee::getRoles(){return roles;}
int Employee::getSize(){return size;}
