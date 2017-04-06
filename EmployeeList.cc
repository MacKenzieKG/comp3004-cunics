#include "EmployeeList.h"

EmployeeList::EmployeeList(){
	employeeVector = new vector<Employee*>();
}

int EmployeeList::addEmployee(Employee* emp){
	if(employeeVector->size() == 0){
      employeeVector->push_back(emp);
	  return 1;
    }
	else {
      for(vector<Employee*>::iterator it = employeeVector->begin(); it != employeeVector->end(); ++it){
        if((*it)->getIDNumber() > emp->getIDNumber()){
          //it++;
          employeeVector->insert(it, emp);
		  return 1;
		}
        else if((*it)->getIDNumber() == emp->getIDNumber()){
		  return -1; //Employee is already in list, employeeID must be unique
		}
	  }
	  employeeVector->push_back(emp);
	  return 1;
	}
	return -1; //Should never be reached
}

Employee* EmployeeList::getEmployeeByIndex(int n){
	return employeeVector->at(n);
}

Employee* EmployeeList::getEmployeeByID(int ID){
  if(employeeVector->size() == 0)
    return NULL; //Invalid, list is empty
  for(vector<Employee*>::iterator it = employeeVector->begin(); it != employeeVector->end(); ++it){
    if((*it)->getIDNumber() == ID)
      return (*it);
	}
  return NULL; //ID not found
}

Employee* EmployeeList::getEmployeeByName(string fName, string lName){
  if(employeeVector->size()  == 0){
    return NULL;
  }
  else{
    for(vector<Employee*>::iterator it = employeeVector->begin(); it !=employeeVector->end(); ++it){
      if((*it)->getFirstName() == fName && (*it)->getLastName() == lName){
        return (*it);
      }
    }
  }
  return NULL;
}

int EmployeeList::size(){
	return employeeVector->size();
}

int EmployeeList::removeEmployee(int ID){
	if(employeeVector->size() == 0)
		return -1;
	for(vector<Employee*>::iterator it = employeeVector->begin();it != employeeVector->end(); ++it){
		if((*it)->getIDNumber() == ID){
			employeeVector->erase(it);
			return 1;
		}
	}
	return -1; //Employee not in list
}

Employee* EmployeeList::operator[](int n){
  if(employeeVector->size() >= n)
    return NULL;
	return getEmployeeByIndex(n);
}
