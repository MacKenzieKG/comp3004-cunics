#include "PaystubList.h"

PaystubList::PaystubList(){
  paystubVector = new vector<Paystub*>();
  employeeID = -1;
}

int PaystubList::getEmployeeID(){return employeeID;}
void PaystubList::setEmployeeID(int newID){employeeID = newID;}

int PaystubList::addPaystub(Paystub* paystub){
  if(paystubVector->size() == 0){
    paystubVector->push_back(paystub);
    employeeID = paystub->getEmployeeID();
    return 1;
  }
  else{
    for(vector<Paystub*>::iterator it = paystubVector->begin(); it != paystubVector->end(); ++it){
      if(paystub->getFromDate() > (*it)->getToDate()){
        it++;
        paystubVector->insert(it,paystub);
        return 1;
      }
    }
    paystubVector->push_back(paystub);
    return 1;
  }
  return -1;
}

vector<Paystub*>* PaystubList::getInnerVector(){
  return paystubVector;
}

Paystub* PaystubList::getPaystubForDate(Date* date){
  if(paystubVector->size() == 0)
    return NULL;
  for(vector<Paystub*>::iterator it = paystubVector->begin(); it != paystubVector->end(); ++it){
    if((*it)->coversDate(*date)){
      return (*it);
    }
  }
  return NULL; //No paystub for this date
}

Paystub* PaystubList::operator[](int n){
  if(paystubVector->size() >= n)
    return NULL;
  return paystubVector->at(n);
}
