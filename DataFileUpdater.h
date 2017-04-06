// DataFileUpdater.h 

#ifndef DATA_FILE_UPDATER_H
#define DATA_FILE_UPDATER_H

//#include "DataTransaction.h"
#include "EmployeeList.h"
#include <ofstream>
#include <string>

using namespace std;

class DataFileUpdater
{
	public:
		DataFileUpdater(EmployeeList* empList, string filename);
		~DataFileUpdater();
		
		bool updateFile();
		
	private:
		EmployeeList* updatedList;
		string outFileName;
		ofstream* outFile;
};

#endif
