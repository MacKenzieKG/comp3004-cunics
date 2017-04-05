#include "PayrollLoginLoader.h"

PayrollLoginLoader::PayrollLoginLoader(char* sourceFileName){
    inFile.open(sourceFileName, ifstream::in);
}

int PayrollLoginLoader::loadTo(map<string,string>* loginMap){
    string parsedLine[2];
    readAndParse(parsedLine);
	while(parsedLine[1] != "FILE" && !(inFile.eof())){
		loginMap->insert(pair<string,string>(parsedLine[0],parsedLine[1]));
	}
}

void PayrollLoginLoader::parseAttribute(string toParse, string parsed[2]){
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

void PayrollLoginLoader::readAndParse(string parse[2]){
    char* currLine = 0;

    if(inFile.good() && !inFile.eof()){
        inFile.getline(currLine,MAX_STR);
    }

    parseAttribute(currLine, parse);
}
