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
	    ContinuingEmployee(string, string, Date, Role*);
		
		double getLeavePercent();
		void setLeavePercent(double);
		
		double getSalary();
		
	    void startLeave(double, Date, Date);
	    void offLeave();
		
	protected:
		double leavePercentage;
		bool onLeave;
    	Date leaveStartDate, leaveEndDate;
    
    	bool approveRole(Role*);
};

#endif
