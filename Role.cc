#include "Role.h"

Role::Role(){}

Role::Role(RoleTime time, RoleType type){
	roleTime = time;
	roleType = type;
  pay = 0.0;
}

Role::Role(RoleTime time, RoleType type, double initialPay){
	roleTime = time;
	roleType = type;
  pay = initialPay;
}

double Role::getPay(){return pay;}
void Role::setPay(double newPay){pay = newPay;}

RoleTime Role::getRoleTime(){return roleTime;}
void Role::setRoleTime(RoleTime aRoleTime){roleTime = aRoleTime;}

RoleType Role::getRoleType(){return roleType;}
void Role::setRoleType(RoleType aRoleType){roleType = aRoleType;}

void Role::givePercentageRaise(double raise){pay += pay * raise;}
void Role::giveRaise(double raise){pay += raise;}
