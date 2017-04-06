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
		
		// use private data members (set by constructor) 
		// to write new data file 
		bool updateFile();
		
	private:
		EmployeeList* updatedList;
		string outFileName;
		ofstream* outFile;
};

#endif
