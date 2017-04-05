#include "RoleLoader.h"

RoleLoader::RoleLoader(char* sourceFileName){
    inFile.open(sourceFileName, ifstream::in);
}

int RoleLoader::loadTo(Role** roles){
    string parsedLine[2];
    readAndParse(parsedLine);
	int i=0;
	while(parsedLine[1] != "FILE" && !(inFile.eof())){
		Role* newRole;

        if(parsedLine[0] == "Role"){
            if(parsedLine[1] == "Faculty") {
                newRole = new Faculty();
            }
            else if (parsedLine[1] == "Staff"){
                newRole = new Staff();
            }
            else if (parsedLine[1] == "TA"){
                newRole = new Ta();
            }
            else if (parsedLine[1] == "RA"){
                newRole = new Ra();
            }
        }
		
        readAndParse(parsedLine);
		
		if(parsedLine[0] == "RoleTime"){
			if(parsedLine[1] == "PART_TIME")
				newRole->setRoleTime(PART_TIME);
			else if (parsedLine[1] == "FULL_TIME")
				newRole->setRoleTime(FULL_TIME);
		}
		
        readAndParse(parsedLine);
		
        istringstream ss(parsedLine[1]);
        int q;
        ss >> q;

        if(parsedLine[0] == "Salary"){
            newRole->setRolePay(q);
		}
		
		roles[i] = newRole;
		i++;
	}
    return 0;
}

void RoleLoader::parseAttribute(string toParse, string parsed[2]){
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

void RoleLoader::readAndParse(string parse[2]){
    char* currLine = 0;

    if(inFile.good() && !inFile.eof()){
        inFile.getline(currLine,MAX_STR);
    }

    parseAttribute(currLine, parse);
}
