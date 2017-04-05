#include "cuNICS.h"

cuNICS::cuNICS(){
	EmployeeLoader employeeLoader("employeeInfo.txt");
	PayrollLoginLoader payrollLoginLoader("payrollLogin.txt");
	
	employeeList = new EmployeeList();
	payrollLogin = new map<string,string>;

	employeeLoader.loadTo(employeeList);
	payrollLoginLoader.loadTo(payrollLogin);
}