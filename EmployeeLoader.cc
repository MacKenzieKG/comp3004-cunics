#include "EmployeeLoader.h"

using namespace std;

EmployeeLoader::EmployeeLoader(char* sourceFileName){
  inFile.open(sourceFileName, ifstream::in);
}

void EmployeeLoader::loadTo(EmployeeList* list){
  char line[2000];
  char* res;
  char lastEmployee[256];
  char lastField[256];

  lastEmployee[0] = '\0';
  lastField[0] = '\0';

  while(!(inFile.eof())){
    res = fgets(line, 2000, inFile);

    if(res == NULL)
      break;

    tokenizer(line);

    Employee* newEmp = 0;
		
    if(strcmp(tokenizedLine[TYPE], "Term") == 0)
      newEmp = new TermEmployee();
	
    else if(strcmp(tokenizedLine[TYPE], "Continuing") == 0)
      newEmp = new ContinuingEmployee();
   
  //This check is for if it's the same employee number as last time; not sure if it works so it's commented out for now  
  //  if(strcmp(tokenizedLine[EID], lastEmployee) != 0) {
      newEmp->setIDNumber(tokenizedLine[EID]);
      newEmp->setFirstName(tokenizedLine[FIRST_NAME]);
      newEmp->setLastNAme(tokenizedLine[LAST_NAME]);
   // }

    Role* newRole = new Role();
    if(strcmp(tokenizedLine[ROLE], "Faculty")	== 0)
      newRole->setRoleType(FACULTY);

    if(strcmp(tokenizedLine[ROLE], "Staff") == 0)
      newRole->setRoleType(STAFF);

    if(strcmp(tokenizedLine[ROLE], "RA") == 0)
      newRole->setRoleType(RA);

    if(strcmp(tokenizedLine[ROLE], "TA") == 0)
      newRole->setRoleType(TA);

    if(strcmp(tokenizedLine[TIME], "Part-time") == 0)
      newRole->setRoleTime(PART_TIME);

    if(strcmp(tokenizedLine[TIME], "Full-time") == 0)
      newRole->setRoleTime(FULL_TIME);			
			
    newEmp->addRole(newRole);
			
    list->addEmployee(newEmp);
    

    strcpy(lastField, tokenizedLine[END_DATE]);
    strcpy(lastEmployee, tokenizedLine[EID]);
  }
}


int EmployeeLoader::tokenizer(char line[2000]) {
  char* t = ",\n";

  int n = 0;
  int numRead = 0;

  char* token = strtok(line, t);
  strcpy(tokenizedLine[numRead++], token);

  int tot = 0;
  while (token != NULL) {
    token - strtok(NULL, t);

    if(token == NULL) {
      return numRead;
    }

    strcpy(tokenizedLine[numRead++], token);
  }

  return numRead;
}
