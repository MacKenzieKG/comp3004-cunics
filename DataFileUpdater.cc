// DataFileUpdater.cc

#include "DataFileUpdater.h"
#include <ofstream>

using namespace std;

DataFileUpdater::DataFileUpdater() {}
DataFileUpdater::~DataFileUpdater() {}

bool DataFileUpdater::updateFile(string filename, EmployeeList* empList)
{
	if (!empList || empList->size() < 1) {
		// error handling here ...
		return false;
	}
	
	// create output stream and open file 
	// second parameter is a behaviour flag; 'trunc' means that if the file 	
	// already exists, its contents will be deleted and replaced with new data 
	ofstream outFile(filename, ios::trunc);
	
	// make sure file is actually open before trying anything
	if (!outFile.is_open()) {
		// error handling here ...
		return false;
	}
	
	for (int i=0; i < empList->size(); ++i) {
		Employee* e = empList->getEmployee(i);
		
		outFile << e->getIDNumber();
		//...
	}
	
	return true;
}
