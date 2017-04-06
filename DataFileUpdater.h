// DataFileUpdater.h 

#ifndef DATA_FILE_UPDATER_H
#define DATA_FILE_UPDATER_H

#include "defs.h"
#include "EmployeeList.h"
#include <string>

using namespace std;

class DataFileUpdater
{
	public:
		DataFileUpdater();
		~DataFileUpdater();
		
		// Write updated employee data to file (CSV format assumed!)
		bool updateFile(string filename, EmployeeList* empList);
		
	private:
		string roleTimeToString(RoleTime);
		string roleTypeToString(RoleType);
		string employeeTypeToString(EmployeeType);
};

#endif
