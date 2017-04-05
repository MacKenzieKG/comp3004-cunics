#ifndef CUNICS_H
#define CUNICS_H

#include "PayrollLoginLoader.h"
#include "EmployeeLoader.h"
#include "Role.h"

class cuNICS {
	public:
		cuNICS();
	private:
		EmployeeList* employeeList;
        map<string,string>* payrollLogin;
};

#endif
