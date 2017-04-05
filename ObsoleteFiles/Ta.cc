#include "Ta.h"

float Ta::pay = 0;

Ta::Ta(){}

Ta::Ta(float p):Role(PART_TIME,"Ta"){

	pay=p;


}

float Ta::getRolePay(){
	return pay;
}

void Ta::setRolePay(float rolePay){
	pay = rolePay;
}

void Ta::givePercentageRaise(float raise){
	pay += pay * raise;
}

void Ta::giveRaise(float raise){
	pay += raise;
}
