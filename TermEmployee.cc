#include "TermEmployee.h"

TermEmployee::TermEmployee(){}

TermEmployee::TermEmployee(string fName, string lName, Date sDate, Date eDate, Role* r):Employee (fName, lName, r){
	startDate = sDate ;
	endDate = eDate;
}

bool TermEmployee::approveRole(Role* role){
  if(role->getRoleType() != FACULTY){
    if(role->getRoleTime() != PART_TIME){
      for(int i=0; i<size; i++){
        if(roles[i]->getRoleType() == role->getRoleType())
          return false;
      }
      return true;
    }
  }
  return false;
}
