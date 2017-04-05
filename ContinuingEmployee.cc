#include "ContinuingEmployee.h"

ContinuingEmployee::ContinuingEmployee(){}

ContinuingEmployee::ContinuingEmployee(string fName, string lName, Role* role): Employee (fName, lName, role){}

void ContinuingEmployee::setLeave(float percentage){

	if (onLeave==true)
		onLeave=false;
	else
		onLeave=true;	

	leavePercentage= percentage;
}

bool ContinuingEmployee::approveRole(Role* role){
  if(role->getRoleTime() != FULL_TIME)
    if(size == 0)
      return true;
  return false;
}