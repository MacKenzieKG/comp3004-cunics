#include "Date.h"

Date::Date(){
  day = 1;
  month = 1;
  year = 1;
}

Date::Date(int aDay, int aMonth, int aYear){
  day = aDay;
  month = aMonth;
  year = aYear;
}


void Date::setDate(int aDay, int aMonth, int aYear){day = aDay; month = aMonth; year = aYear;}
string Date::getDate(){return ("" + day + '/' + month + '/' + year);}
void Date::setDay(int aDay){day = aDay;}
int Date::getDay(){return day;}
void Date::setMonth(int aMonth){month = aMonth;}
int Date::getMonth(){return month;}
void Date::setYear(int aYear){year = aYear;}
int Date::getYear(){return year;}