#ifndef PAYSTUB_H
#define PAYSTUB_H

#include "Date.h"

class Paystub{
  public:
    Paystub();

    int getEmployeeID();
    void setEmployeeID(int);
    double getPayForPeriod();
    void setPayForPeriod(double);
    double getDeductions();
    void setDeductions(double);
    double setGrossIncome();
    void getGrossIncome(double);
    double getPayForYTD();
    void setPayForYTD(double);
    double getDeductionsYTD();
    void setDeductionsYTD(double);
    double getGrossIncomeYTD();
    void setGrossIncomeYTD(double);
    Date getFromDate();
    void setFromDate(Date);
    Date getToDate();
    void setToDate(Date);

    bool coversDate(Date);
    
  private:
    int employeeID;
    double payForPeriod, deductions, grossIncome, payForYTD, deductionsYTD, grossIncomeYTD;
    Date fromDate, toDate;
};

#endif
