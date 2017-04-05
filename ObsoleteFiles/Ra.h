#ifndef RA_H
#define RA_H

#include "defs.h"
#include "Role.h"
#include <string>

class Ra:public Role{

	public:
        Ra();
		Ra(float);
        
        float getRolePay();
        void setRolePay(float);
        void givePercentageRaise(float);
        void giveRaise(float);
        static float pay;
	


};

#endif
