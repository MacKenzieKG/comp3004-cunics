#include "ContinuingEmployee.h"

ContinuingEmployee::ContinuingEmployee(){}

ContinuingEmployee::ContinuingEmployee(string fName, string lName, Role* role): Employee (fName, lName){
	addRole(role);
}

void ContinuingEmployee::startLeave(float percentage, Date sDate, Date eDate){
	onLeave = true;
	leavePercentage = percentage;
  leaveStartDate = sDate;
  leaveEndDate = eDate;
}

void ContinuingEmployee::offLeave(){
  onLeave = false;
}

bool ContinuingEmployee::approveRole(Role* role){
  if(role->getRoleTime() == FULL_TIME && size > 0)
  	return false;
  return true;
}
