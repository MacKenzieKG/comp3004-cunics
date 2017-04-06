#include "Date.h"

Date::Date(){
  day = 1;
  month = 1;
  year = 1970;
}

Date::Date(string str){
	string temp = "" + str[0] + str[1] + str[2] + str[3];
	istringstream ss(temp);
	ss >> year;
	temp = "" + str[5] + str[6];
	ss.str(temp);
	ss >> month;
	temp = "" + str[8] + str[9];
	ss.str(temp);
	ss >> day;
}

Date::Date(int aDay, int aMonth, int aYear){
  day = aDay;
  month = aMonth;
  year = aYear;
}


void Date::setDate(int aDay, int aMonth, int aYear){day = aDay; month = aMonth; year = aYear;}
string Date::getDate(){return "TODO";}
void Date::setDay(int aDay){day = aDay;}
int Date::getDay(){return day;}
void Date::setMonth(int aMonth){month = aMonth;}
int Date::getMonth(){return month;}
void Date::setYear(int aYear){year = aYear;}
int Date::getYear(){return year;}

Date& Date::operator=(Date from){
  day = from.day;
  month = from.month;
  year = from.year;
  return *this;
}

bool Date::operator==(Date from){
  return (day == from.day && month == from.month && year == from.year);
}

bool Date::operator>(Date from){
  if(year > from.year){
    return true;
  }
  else if(year < from.year){
    return false;
  }
  else {
    if(month > from.month)
      return true;
    else if(month < from.month)
      return false;
    else{
      if(day > from.day)
        return true;
      return false;
    }
  }
}

bool Date::operator<(Date from){
  if(*this == from)
    return false;
  else
    return !(*this > from);
}

bool Date::operator<=(Date from){
  return (*(this) == from || (*this) < from);
}

bool Date::operator>=(Date from){
  return (*(this) == from || (*this) > from);
}

ostream& Date::operator<<(ostream& os){
	os << "" << year << "/" << month << "/" << day;
	return os;
}

int Date::weeksSince(Date date){
  return 0;
}

int Date::convertToDays(){
  return 0;
}
