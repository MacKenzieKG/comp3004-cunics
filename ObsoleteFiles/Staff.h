#ifndef STAFF_H
#define STAFF_H

#include "defs.h"
#include "Role.h"
#include <string>

class Staff:public Role{

	public:
        Staff();
		Staff(RoleTime, float);

        float getRolePay();
        void setRolePay(float);
        void givePercentageRaise(float);
        void giveRaise(float);
        static float pay;
};

#endif
