#ifndef DATE_H
#define DATE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

class Date{
  public:
    Date();
    Date(string);
    Date(int,int,int);
    
    void setDate(int,int,int);
    string getDate();
    void setDay(int);
    int getDay();
    void setMonth(int);
    int getMonth();
    void setYear(int);
    int getYear();
    
    Date& operator=(Date);
    bool operator==(Date);
    bool operator>(Date);
    bool operator<(Date);
    bool operator>=(Date);
    bool operator<=(Date);
    ostream& operator<<(ostream& os);

    int weeksSince(Date date);
    
  private:
    int day, month, year;

    int convertToDays();
};

#endif
