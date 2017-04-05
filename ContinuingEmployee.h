#ifndef CONTINUINGEMPLOYEE_H
#define CONTINUINGEMPLOYEE_H

using namespace std;
#include "defs.h"
#include "Employee.h"
#include <string>

class ContinuingEmployee: public Employee{
	public:
		ContinuingEmployee();
    ContinuingEmployee(string, string, Role*);

    void setLeave(float);
		
	protected:
		float leavePercentage;
		bool onLeave;
    
    bool approveRole(Role*);
};

#endif
