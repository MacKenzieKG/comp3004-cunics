#include "EmployeeManager.h"

EmployeeManager::EmployeeManager(){
	EmployeeLoader employeeLoader("employees.csv");
	
	employeeList = new EmployeeList();
	payrollLogin = new map<string,string>;

	employeeLoader.loadTo(employeeList);
}

Employee* EmployeeManager::getEmployeeByIndex(int index){
  return employeeList->getEmployeeByIndex(index);
}

Employee* EmployeeManager::getEmployeeByID(int ID){
  return employeeList->getEmployeeByID(ID);
}

Employee* EmployeeManager::getEmployeeByName(std::string fName, std::string lName){
  return employeeList->getEmployeeByName(fName,lName);
}

int EmployeeManager::addNewEmployee(string empType, string fName, string lName, string startDate, string endDate, string roleType, string roleTime, string rolePay){
	Role* role = new Role();
	
	if(roleType == "Faculty")
		role->setRoleType(FACULTY);
	else if(roleType == "Staff")
		role->setRoleType(STAFF);
	else if(roleType == "TA")
		role->setRoleType(TA);
	else
		role->setRoleType(RA);
	
	if(roleTime == "Full-time")
		role->setRoleTime(FULL_TIME);
	else
		role->setRoleTime(PART_TIME);
	
	istringstream ss(rolePay);
    double pay;
    ss >> pay;
    role->setPay(pay);
	
	int day, month, year;
	string hold = "" + startDate[0]+startDate[1]+startDate[2]+startDate[3];
	ss.str(hold);
	ss >> day;
	hold = startDate[5]+startDate[6];
	ss.str(hold);
	ss >> month;
	hold = startDate[8]+startDate[9];
	ss.str(hold);
	ss >> year;
	Date sDate(day,month,year);
	
	Date eDate;
	if(endDate[0] != '-'){
		hold = endDate[0]+endDate[1]+endDate[2]+endDate[3];
		ss.str(hold);
		ss >> day;
		hold = endDate[5]+endDate[6];
		ss.str(hold);
		ss >> month;
		hold = endDate[8]+endDate[9];
		ss.str(hold);
		ss >> year;
		eDate.setDate(day,month,year);
	}
	
	Employee* newEmp;
	if(empType == "Continuing")
		newEmp = new ContinuingEmployee(fName,lName,sDate,role);
	else {
		newEmp = new TermEmployee(fName,lName,sDate,eDate,role);
	}
    employeeList->addEmployee(newEmp);
}

int EmployeeManager::removeEmployee(string empID){
	istringstream ss(empID);
	int ID;
	ss >> ID;
	employeeList->removeEmployee(ID);
}
