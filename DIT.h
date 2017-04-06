#ifndef DIT_H
#define DIT_H

#define OPERATION 0
#define EID 1
#define FIRST_NAME 2
#define LAST_NAME 3
#define ROLE 4
#define HOURS 5
#define TYPE 6
#define START_DATE 7
#define END_DATE 8
#define NEW_HOURS 9
#define NEW_ROLE 10
#define NEW_SALARY 11
#define LEAVE_STATUS 12
#define LEAVE_START 13
#define PERCENT_PAY 14
#define LEAVE_END 15

using namespace std;

class DIT{
  public:
    DIT(char*);
    void loadTo(EmployeeList*);

  private:
    ifstream inFile;
    string tokenizedLine[16];

    void tokenizer(string);
    int toInt(string);
    double toDouble(string);
    void cleanTokenizedLine();
    RoleTime toRoleTime(string);
    RoleType toRoleType(string);
};

#endif
