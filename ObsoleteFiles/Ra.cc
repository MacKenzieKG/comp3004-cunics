#include "Ra.h"

float Ra::pay = 0;

Ra::Ra(){}

Ra::Ra(float p):Role(PART_TIME,"Ra"){

	pay=p;


}

void Ra::setRolePay(float rolePay){
	pay = rolePay;
}

float Ra::getRolePay(){
	return pay;
}

void Ra::givePercentageRaise(float raise){
	pay += pay * raise;
}

void Ra::giveRaise(float raise){
	pay += raise;
}
