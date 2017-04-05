#ifndef TA_H
#define TA_H

#include "defs.h"
#include "Role.h"
#include <string>


class Ta:public Role{

	public:
		Ta();
		Ta(float);

        float getRolePay();
        void setRolePay(float);
        void givePercentageRaise(float);
        void giveRaise(float);
        static float pay;
	

};

#endif
