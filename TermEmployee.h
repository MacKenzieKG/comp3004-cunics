#ifndef TERMEMPLOYEE_H
#define TERMEMPLOYEE_H

using namespace std;

#include <string>
#include "defs.h"
#include "Employee.h"
#include "Date.h"

class TermEmployee: public Employee{

	public:
    TermEmployee();
		TermEmployee(string, string, Date, Date, Role*);
		
	protected:
		Date startDate;
		Date endDate;
    
    bool approveRole(Role*);
};

#endif
