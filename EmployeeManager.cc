#include "EmployeeManager.h"

EmployeeManager::EmployeeManager(){
	EmployeeLoader employeeLoader("employees.csv");
	
	employeeList = new EmployeeList();
	paystubList = new vector<PaystubList*>();
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

int addNewEmployee(string empType, string fName, string lName, string roleType, string roleTime, string rolePay){
	Employee* newEmp;
	if(empType == "CONTINUING")
		newEmp = new ContinuingEmployee();
	else {
		newEmp = new TermEmployee();
	}
}

vector<Paystub*>* EmployeeManager::getPaystubsForDate(Date date){
	
}
