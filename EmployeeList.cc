#include "EmployeeList.h"

int EmployeeList::addEmployee(Employee* emp){
	if(employeeVector->size() == 0)
        employeeVector->push_back(emp);
	else {
        for(vector<Employee*>::iterator it = employeeVector->begin(); it != employeeVector->end(); ++it){
            if((*it)->getIDNumber() > emp->getIDNumber()){
                it++;
                employeeVector->insert(it, emp);
				return 1;
			}
            else if((*it)->getIDNumber() == emp->getIDNumber())
				return -1; //Employee is already in list, employeeID must be unique
		}
		employeeVector->push_back(emp);
		return 1;
	}
	return 0; //Should never be reached
}

Employee* EmployeeList::getEmployee(int n){
	return employeeVector->at(n);
}

Employee* EmployeeList::getEmployeeByID(int ID){
    if(employeeVector->size() == (unsigned)0)
        return NULL; //Invalid, list is empty
	else{
        for(vector<Employee*>::iterator it = employeeVector->begin(); it != employeeVector->end(); ++it){
            if((*it)->getIDNumber() == ID)
                return (*it);
		}
	}
    return NULL; //ID not found
}

Employee* EmployeeList::operator[](int n){
	return getEmployee(n);
}
