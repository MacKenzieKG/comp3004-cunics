#include "Paystub.h"

Paystub::Paystub(){
  employeeID = 0;
  payForPeriod = grossIncome = payForYTD = deductionsYTD = grossIncomeYTD = 0.0;
}

int Paystub::getEmployeeID(){return employeeID;}
void Paystub::setEmployeeID(int newID){employeeID = newID;}
double Paystub::getPayForPeriod(){return payForPeriod;}
void Paystub::setPayForPeriod(double newPayForPeriod){payForPeriod = newPayForPeriod;}
double Paystub::getDeductions(){return deductions;}
void Paystub::setDeductions(double newDeductions){deductions = newDeductions;}
double Paystub::setGrossIncome(){return grossIncome;}
void Paystub::getGrossIncome(double newGrossIncome){grossIncome = newGrossIncome;}
double Paystub::getPayForYTD(){return payForYTD;}
void Paystub::setPayForYTD(double newPayForYTD){payForYTD = newPayForYTD;}
double Paystub::getDeductionsYTD(){return deductionsYTD;}
void Paystub::setDeductionsYTD(double newDeductionsYTD){deductionsYTD = newDeductionsYTD;}
double Paystub::getGrossIncomeYTD(){return grossIncomeYTD;}
void Paystub::setGrossIncomeYTD(double newGrossIncomeYTD){grossIncomeYTD = newGrossIncomeYTD;}
Date Paystub::getFromDate(){return fromDate;}
void Paystub::setFromDate(Date newFromDate){fromDate = newFromDate;}
Date Paystub::getToDate(){return toDate;}
void Paystub::setToDate(Date newToDate){toDate = newToDate;}

bool Paystub::coversDate(Date date){
  return (toDate >= date && date >= fromDate);
}
