// DataFileUpdater.h 

#ifndef DATA_FILE_UPDATER_H
#define DATA_FILE_UPDATER_H

#include "EmployeeList.h"
#include <string>

using namespace std;

class DataFileUpdater
{
	public:
		DataFileUpdater();
		~DataFileUpdater();
		
		// write updated employee data to file 
		bool updateFile(string filename, EmployeeList* empList);
		
	private:
		//string outFileName;
};

#endif
