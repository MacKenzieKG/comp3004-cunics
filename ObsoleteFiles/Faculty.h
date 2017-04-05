#ifndef FACULTY_H
#define FACULTY_H

#include "defs.h"
#include "Role.h"

class Faculty:public Role{

	public:
    	Faculty();
		Faculty(float);

        float getRolePay();
        void setRolePay(float);
        void givePercentageRaise(float);
        void giveRaise(float);
        static float pay;
	protected:

	
};



#endif
