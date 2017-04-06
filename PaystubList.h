#ifndef PAYSTUBLIST
#define PAYSTUBLIST

#include <vector>
#include "Paystub.h"

using namespace std;

class PaystubList {
  public:
    PaystubList();
    
    int getEmployeeID();
    void setEmployeeID(int);
    
    int addPaystub(Paystub*);
    vector<Paystub*>* getInnerVector();
    Paystub* getPaystubForDate(Date*);

    Paystub* operator[](int);
  private:
    int employeeID;

    vector<Paystub*>* paystubVector;
};

#endif
