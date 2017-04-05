#include "Role.h"

Role::Role(){}

Role::Role(RoleTime time, RoleType type){
	roleTime = time;
	roleType = type;
  pay = 0.0;
}

Role::Role(RoleTime time, RoleType type, float initialPay){
	roleTime = time;
	roleType = type;
  pay = initialPay;
}

float Role::getPay(){return pay;}
void Role::setPay(float newPay){pay = newPay;}

RoleTime Role::getRoleTime(){return roleTime;}
void Role::setRoleTime(RoleTime aRoleTime){roleTime = aRoleTime;}

RoleType Role::getRoleType(){return roleType;}
void Role::setRoleType(RoleType aRoleType){roleType = aRoleType;}

void Role::givePercentageRaise(float raise){pay += pay * raise;}
void Role::giveRaise(float raise){pay += raise;}