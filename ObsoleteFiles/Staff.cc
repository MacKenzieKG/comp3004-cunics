#include "Staff.h"

float Staff::pay = 0;

Staff::Staff(){
}

Staff::Staff(RoleTime r,float p):Role(r,"Staff"){
    pay=p;
}

float Staff::getRolePay(){
	return pay;
}

void Staff::setRolePay(float rolePay){
	pay = rolePay;
}

void Staff::givePercentageRaise(float raise){
	pay += pay * raise;
}

void Staff::giveRaise(float raise){
	pay += raise;
}
