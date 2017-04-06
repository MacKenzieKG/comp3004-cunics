// DataFileUpdater.cc

#include "DataFileUpdater.h"

using namespace std;

DataFileUpdater::DataFileUpdater(EmployeeList* empList, string filename)
{
	updatedList = empList;
	outFileName = filename;	
	
	//...
}

DataFileUpdater::~DataFileUpdater() {}

bool DataFileUpdater::updateFile()
{
	//...
	return true;
}
