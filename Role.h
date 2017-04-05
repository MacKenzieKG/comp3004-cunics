#ifndef ROLE_H
#define ROLE_H

using namespace std;
#include "defs.h"
#include <string>


class Role{

	public:
    Role();
		Role (RoleTime, RoleType);
    Role (RoleTime, RoleType, float);
    
		float getPay();
		void setPay(float);
    
		RoleTime getRoleTime();
    void setRoleTime(RoleTime);
    
    RoleType getRoleType();
    void setRoleType(RoleType);
    
		void givePercentageRaise(float);
		void giveRaise(float);

	protected:
    float pay;
		RoleTime roleTime;
    RoleType roleType;
};

#endif
