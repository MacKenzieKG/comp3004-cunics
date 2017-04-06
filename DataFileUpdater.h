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
		
		// use updated employee data to write new file 
		bool updateFile(string filename, EmployeeList* empList);
		
	private:
		//string outFileName;
};

#endif
