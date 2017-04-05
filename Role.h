#ifndef ROLE_H
#define ROLE_H

using namespace std;
#include "defs.h"
#include <string>


class Role{

	public:
    	Role();
	 	Role (RoleTime, RoleType);
    	Role (RoleTime, RoleType, double);
    
		double getPay();
		void setPay(double);
    
		RoleTime getRoleTime();
    	void setRoleTime(RoleTime);
    
	    RoleType getRoleType();
	    void setRoleType(RoleType);
    
		void givePercentageRaise(double);
		void giveRaise(double);

	protected:
    	double pay;
		RoleTime roleTime;
    	RoleType roleType;
};

#endif
