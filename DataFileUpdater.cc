// DataFileUpdater.cc

#include "DataFileUpdater.h"
#include "Date.h"
#include "defs.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

DataFileUpdater::DataFileUpdater() {}
DataFileUpdater::~DataFileUpdater() {}

// ** NOTE ** 
// File format is assumed to be CSV
bool DataFileUpdater::updateFile(string filename, EmployeeList* empList)
{
	if (!empList || empList->size() < 1) {
		// error handling here ...
		return false;
	}
	
	// Create output stream and open file 
	// Second parameter is a behaviour flag; 'trunc' means that if the file 	
	// already exists, its contents will be deleted and replaced with new data 
	ofstream outFile(filename, ios::trunc);
	
	// Make sure file is actually open before trying anything
	if (!outFile.is_open()) {
		// error handling here ...
		return false;
	}
	
	for (int i=0; i < empList->size(); ++i) {
		Employee* employee = empList->getEmployee(i);
		stringstream entry;
		
		// Need to deal with multiple roles
		vector<Role*> roles;
		for (int j=0; j < MAX_ROLE; ++j) {
			Role* r = employee->getRoles()[j];
			if (r != 0) {
				roles.push_back(r);
			}
		}
		
		for (int k=0; k < roles.size(); ++k) {
			string fname = k==0 ? employee->getFirstName() : "";
			string lname = k==0 ? employee->getLastName() : "";
			
			Role* r = roles.at(k);
			RoleType rType = r->getRoleType();
			RoleTime rTime = r->getRoleTime();
			EmployeeType eType = employee->getEmployeeType();
			
			entry << employee->getIDNumber() << "," << fname << "," << lname 
			      << "," << roleTypeToString(rType) << "," 
					<< roleTimeToString(rTime) << "," 
					<< employeeTypeToString(eType) << ","
					<< employee->getStartDate() << "," << employee->getEndDate() 
					<< "," << r->getPay() << "\n";
		}
		
		outFile << entry.str();
	}
	
	outFile.close();
	return true;
}

string DataFileUpdater::roleTimeToString(RoleTime rt)
{
	switch (rt) {
		case FULL_TIME:
			return "Full-time";
		case PART_TIME:
			return "Part-time";
		default:
			return "";
	}
}

string DataFileUpdater::roleTypeToString(RoleType rt)
{
	switch (rt) {
		case STAFF:
			return "Staff";
		case FACULTY:
			return "Faculty";
		case TA:
			return "TA";
		case RA:
			return "RA";
		default:
			return "";
	}
}

string DataFileUpdater::employeeTypeToString(EmployeeType et)
{
	switch (et) {
		case CONTINUING:
			return "Continuing";
		case TERM:
			return "Term";
		default:
			return "";
	}
}
