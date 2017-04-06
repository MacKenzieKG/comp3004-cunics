#include "ContinuingEmployee.h"

ContinuingEmployee::ContinuingEmployee(){employeeType = CONTINUING;leavePercentage = 0.5;onLeave=false;}

ContinuingEmployee::ContinuingEmployee(string fName, string lName, Date sDate, Role* role): Employee (fName, lName, sDate){
	employeeType = CONTINUING;
	addRole(role);
}

double ContinuingEmployee::getLeavePercent(){return leavePercentage;}
void ContinuingEmployee::setLeavePercent(double newLeave){leavePercentage = newLeave;}

double ContinuingEmployee::getSalary(){
  double total = 0.0;
  for(int i = 0; i < size; i++){
    total += roles[i]->getPay();
  }
  if(onLeave)
  	total = total * leavePercentage;
  return total;
}

void ContinuingEmployee::startLeave(double percentage, Date sDate, Date eDate){
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
