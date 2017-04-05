#ifndef CONTINUINGEMPLOYEE_H
#define CONTINUINGEMPLOYEE_H

using namespace std;
#include "defs.h"
#include "Employee.h"
#include "Date.h"
#include <string>

class ContinuingEmployee: public Employee{
	public:
		ContinuingEmployee();
	    ContinuingEmployee(string, string, Role*);
		
	    void startLeave(float, Date, Date);
	    void offLeave();

    
		
	protected:
		float leavePercentage;
		bool onLeave;
    	Date leaveStartDate, leaveEndDate;
    
    	bool approveRole(Role*);
};

#endif
