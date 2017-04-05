#include "EmployeeLoader.h"

using namespace std;

EmployeeLoader::EmployeeLoader(char* sourceFileName){
    inFile.open(sourceFileName, ifstream::in);
}

int EmployeeLoader::loadTo(EmployeeList* list){
    string parsedLine[2] = {"",""};
	while(parsedLine[1] != "FILE" && !(inFile.eof())){
    readAndParse(parsedLine);
		
		Employee* newEmp = 0;
		
		if(parsedLine[0] == "Type"){
			if(parsedLine[1] == "TermEmployee")
				newEmp = new TermEmployee();
			else if(parsedLine[1] == "ContinuingEmployee")
				newEmp = new ContinuingEmployee();
		}
		
    readAndParse(parsedLine);

    istringstream ss(parsedLine[1]);
    int q;
    ss >> q;

    if(parsedLine[0] == "EmployeeID"){
        newEmp->setIDNumber(q);
		}
		
    readAndParse(parsedLine);
		
		if(parsedLine[0] == "FirstName"){
      newEmp->setFirstName(parsedLine[1]);
		}
    
    readAndParse(parsedLine);
		
		if(parsedLine[0] == "LastName"){
      newEmp->setLastName(parsedLine[1]);
		}
		
    readAndParse(parsedLine);
		
		while(parsedLine[0] != "END"){
			Role* newRole = new Role();
			if(parsedLine[0] == "Role"){
        if(parsedLine[1] == "Faculty") {
            newRole->setRoleType(FACULTY);
        }
        else if (parsedLine[1] == "Staff"){
            newRole->setRoleType(STAFF);
        }
        else if (parsedLine[1] == "TA"){
            newRole->setRoleType(TA);
        }
        else if (parsedLine[1] == "RA"){
            newRole->setRoleType(RA);
				}
			}
			
      readAndParse(parsedLine);
			
			if(parsedLine[0] == "RoleTime"){
				if(parsedLine[1] == "PART_TIME")
					newRole->setRoleTime(PART_TIME);
				else if (parsedLine[1] == "FULL_TIME")
					newRole->setRoleTime(FULL_TIME);
			}
			
			newEmp->addRole(newRole);
			
            readAndParse(parsedLine);
		}
		
		if(parsedLine[1] == "EMPLOYEE" || parsedLine[1] == "FILE"){
            list->addEmployee(newEmp);
		}
	}
    return NULL;
}

void EmployeeLoader::parseAttribute(string toParse, string parsed[2]){
	int currPos=0;
    parsed[0] = "";
    parsed[1] = "";
    for(int i=0;(unsigned)i<toParse.size();i++){
        if(toParse[i] == ':')
			currPos++;
		else
			parsed[currPos]+=toParse[i];
    }
}

void EmployeeLoader::readAndParse(string parse[2]){
	char* currLine = 0;
	
	if(inFile.good() && !inFile.eof()){
        inFile.getline(currLine,MAX_STR);
	}
	
    parseAttribute(currLine, parse);
}
