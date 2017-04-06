#include "TermEmployee.h"

TermEmployee::TermEmployee(){employeeType = TERM;}

TermEmployee::TermEmployee(string fName, string lName, Date sDate, Date eDate, Role* role):Employee (fName, lName, sDate){
	endDate = eDate;
    employeeType = TERM;
  	addRole(role);
}

Date TermEmployee::getEndDate(){return endDate;}
void TermEmployee::setEndDate(Date newEnd){endDate = newEnd;}

bool TermEmployee::approveRole(Role* role){
  /*if(role->getRoleType() != FACULTY){
    if(role->getRoleTime() != PART_TIME){
      for(int i=0; i<size; i++){
        if(roles[i]->getRoleType() == role->getRoleType())
          return false;
      }
      return true;
    }
  }
  return false;*/
  return true;
}
