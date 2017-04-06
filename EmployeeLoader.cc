#include "EmployeeLoader.h"

using namespace std;

EmployeeLoader::EmployeeLoader(char* sourceFileName){
  inFile.open(sourceFileName, ifstream::in);
}

void EmployeeLoader::loadTo(EmployeeList* list){
  string line;
  char* res;
  string lastEmployee;
  string lastField;

  int count = 1;
  
  lastEmployee = "";
  getline(inFile,line);
  
  Employee* newEmp = 0;
  
  while(!(inFile.eof())){
	getline(inFile,line);
    tokenizer(line);
	
	if(tokenizedLine[EID] != lastEmployee){
		if(tokenizedLine[TYPE] == "Term")
	      newEmp = new TermEmployee();
	    else if(tokenizedLine[TYPE] == "Continuing")
	      newEmp = new ContinuingEmployee();
	    
	    newEmp->setIDNumber(toInt(tokenizedLine[EID]));
		newEmp->setFirstName(tokenizedLine[FIRST_NAME]);
	  	newEmp->setLastName(tokenizedLine[LAST_NAME]);
	}
	
    Role* newRole = new Role();
    if(tokenizedLine[ROLE] == "Faculty")
      newRole->setRoleType(FACULTY);

    if(tokenizedLine[ROLE] == "Staff")
      newRole->setRoleType(STAFF);

    if(tokenizedLine[ROLE], "RA")
      newRole->setRoleType(RA);

    if(tokenizedLine[ROLE] == "TA")
      newRole->setRoleType(TA);

    if(tokenizedLine[HOURS] == "Part-time")
      newRole->setRoleTime(PART_TIME);

    if(tokenizedLine[HOURS] == "Full-time")
      newRole->setRoleTime(FULL_TIME);			
	
	newRole->setPay(toDouble(tokenizedLine[SALARY]));
	
    newEmp->addRole(newRole);
	
    list->addEmployee(newEmp);
    

    lastField = tokenizedLine[END_DATE];
    lastEmployee = tokenizedLine[EID];
  }
}


void EmployeeLoader::tokenizer(string line) {
  char end = '\n';
  char delim = ',';
	
  cleanTokenizedLine();
  
  int i = 0;
  
  for(int n = 0; n < line.length(); n++){
  	if(line[n] != delim)
  		tokenizedLine[i] += line[n];
  	else
  		i++;
  }
}

int EmployeeLoader::toInt(string str){
	istringstream ss(str);
    int q;
    ss >> q;
    return q;
}

double EmployeeLoader::toDouble(string str){
	istringstream ss(str);
    double q;
    ss >> q;
    return q;
}

void EmployeeLoader::cleanTokenizedLine(){
	for(int i=0;i<16;i++){
		tokenizedLine[i] = "";
	}
}
