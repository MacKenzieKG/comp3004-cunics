using namespace std;
#include "Faculty.h"


float Faculty::pay = 0;

Faculty::Faculty():Role(FULL_TIME,"Faculty"){
}

Faculty::Faculty(float p):Role(FULL_TIME,"Faculty"){

	pay=p;


}

float Faculty::getRolePay(){

	return pay;
}

void Faculty::setRolePay(float rolePay){
	pay = rolePay;
}

void Faculty::givePercentageRaise(float raise){
    pay += getRolePay() * raise;
}

void Faculty::giveRaise(float raise){
	pay += raise;
}
