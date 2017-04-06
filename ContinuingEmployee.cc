#include "ContinuingEmployee.h"

ContinuingEmployee::ContinuingEmployee(){employeeType = CONTINUING;}

ContinuingEmployee::ContinuingEmployee(string fName, string lName, Date sDate, Role* role): Employee (fName, lName, sDate){
	employeeType = CONTINUING;
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
  return true;
}
