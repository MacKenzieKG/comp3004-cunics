#ifndef DATE_H
#define DATE_H

#include <string>
#include <cstdlib>

using namespace std;

class Date{
  public:
    Date();
    Date(int,int,int);
    
    void setDate(int,int,int);
    string getDate();
    void setDay(int);
    int getDay();
    void setMonth(int);
    int getMonth();
    void setYear(int);
    int getYear();
  private:
    int day, month, year;
};

#endif