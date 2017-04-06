#include "DIT.h"

using namespace std;

DIT::DIT(char* sourceFileName) {
  inFile.open(sourceFileName, ifstream::in);
}

void DIT::loadTo(EmployeeList* list) {
  string line;
  char* res;
  string lastOperation;
  string lastField;

  int count = 1;

  lastOperation = "";
  getline(inFile, line);

  Employee* newEmp = 0;
  Role* newRole = 0;

  while(!(inFile.eof())) {
    getline(inFile, line);
    tokenizer(line);

    if(tokenizedLine[OPERATION] != lastOperation) {
      if(tokenizedLine[OPERATION] == "addEmployee") {
        if(tokenizedLine[TYPE] == "Term") {
          newRole = new Role(tokenizedLine[HOURS], tokenizedLine[TYPE]);
          newEmp = new TermEmployee(tokenizedLine[FIRST_NAME], 
                       tokenizedLine[LAST_NAME], tokenizedLine[START_DATE], 
                       tokenizedLine[END_DATE], newRole);
        }
      
        if(tokenizedLine[TYPE] == "Continuing") {
          newRole = new Role(tokenizedLine[HOURS], tokenizedLine[TYPE]);
          newEmp = new ContinuingEmployee(tokenizedLine[FIRST_NAME], 
                       tokenizedLine[LAST_NAME], tokenizedLine[START_DATE], 
                       newRole);
        }
      } 

      if(tokenizedLine[OPERATION] == "updateBasicInfo") {
        int empID = toInt(tokenizedLine[EID]);
        Employee* emp = list->getEmployeeByID(empID);

        if(tokenizedLine[FIRST_NAME] != "")
          emp->setFirstName(tokenizedLine[FIRST_NAME]);

        if(tokenizedLine[LAST_NAME] != "")
          emp->setLastName(tokenizedLine[LAST_NAME]);
      }

      if(tokenizedLine[OPERATION] == "updatePayInfo") {
        int empID = toInt(tokenizedLine[EID]);
        Employee* emp = list->getEmployeeByID(empID);
        RoleType role;
        RoleType newRole;
        RoleTime time;
        RoleTime newTime;
        

        if(tokenizedLine[ROLE] == "TA")
          role = TA;
 
        if(tokenizedLine[ROLE] == "RA")
          role = RA;

        if(tokenizedLine[ROLE] == "Faculty")
          role = FACULTY;

        if(tokenizedLine[ROLE] == "Staff")
          role = STAFF;

        if(tokenizedLine[TIME] == "Part-time")
          time = PART_TIME;

        if(tokenizedLine[TIME] == "Full-time")
          time = FULL_TIME;

        Role* empRole = emp->findRole(role, time);
        
        if(tokenizedLine[NEW_HOURS] != "") {
          if(tokenizedLine[NEW_HOURS] == "Part-time")
            newTime = PART_TIME;

          if(tokenizedLine[NEW_HOURS] == "Full-time")
            newTime = FULL_TIME;

          empRole->setRoleTime(newTime);
        }

        if(tokenizedLine[NEW_ROLE] != "") {
          if(tokenizedLine[NEW_ROLE] == "Staff")
            newRole = STAFF;

          if(tokenizedLine[NEW_ROLE] == "Faculty")
            newRole = FACULTY;

          if(tokenizedLine[NEW_ROLE] == "TA")
            newRole = TA;

          if(tokenizedLine[NEW_ROLE] == "RA")
            newRole = TA;

          empRole->setRoleType(newRole);
        }
      }

      if(tokenizedLine[OPERATION] == "applyRaise") {
       double change = toDouble(tokenizedLine[NEW_SALARY]);
       RoleTime hours;
       RoleType role;

       if(tokenizedLine[HOURS] == "Full-time")
         hours = FULL_TIME;

       if(tokenizedLine[HOURS] == "Part-time")
         hours = PART_TIME;

       if(tokenizedLine[ROLE] == "RA")
         role = RA;

       if(tokenizedLine[ROLE] == "TA")
         role = TA;

       if(tokenizedLine[ROLE] == "Faculty")
         role = FACULTY;

       if(tokenizedLine[ROLE] == "Staff")
         role = STAFF;

       list->giveRoleRaisePercent(role, hours, change);
      }

      if(tokenizedLine[OPERATION] == "goOnLeave") {
        int empID = toInt(tokenizedLine[EID]);
        double payChange = toDouble(tokenizedLine[PERCENT_PAY]);
        ContinuingEmployee* emp = (ContinuingEmployee*)list->getEmployeeByID(empID);

        emp->startLeave(payChange, tokenizedLine[LEAVE_START], tokenizedLine[LEAVE_END]);
      }

      if(tokenizedLine[OPERATION] == "goOffLeave") {
        int empID = toInt(tokenizedLine[EID]);
        ContinuingEmployee* emp = (ContinuingEmployee*)list->getEmployeeByID(empID);
        emp->offLeave();
      }

      if(tokenizedLine[OPERATION] == "addRole") {
        newRole = new Role(tokenizedLine[HOURS], tokenizedLine[TYPE]);
        int empID = toInt(tokenizedLine[EID]);
        Employee* emp = list->getEmployeeByID(empID);

        emp->addRole(newRole);
      }

    }

    lastField = tokenizedLine[LEAVE_END];
    lastOperation = tokenizedLine[OPERATION];
  }
}

void DIT::tokenizer(string line) {
  char end = '\n';
  char delim = ',';

  cleanTokenizedLine();

  int i = 0;

  for(int n = 0; n < line.length(); n++) {
    if(line[n] != delim)
      tokenizedLine[i] += line[n];
    else
      i++;
  }
}

int DIT::toInt(string str) {
  istringstream ss(str);
  int q;
  ss >> q;
  return q;
}

double DIT::toDouble(string str) {
  istringstream ss(str);
  double q;
  ss >> q;
  return q;
}

void DIT::cleanTokenizedLine() {
  for(int i = 0; i < 16; i++) {
    tokenizedLine[i] = "";
  }
}
