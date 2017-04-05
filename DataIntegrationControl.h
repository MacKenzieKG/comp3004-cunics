// DataIntegrationControl.h 

#ifndef DIT_CONTROL_H
#define DIT_CONTROL_H

using namespace std;

#include <ifstream>
#include <string>
#include <vector>

#include "DataTransaction.h"

class DataIntegrationControl
{
	public:
		DataIntegrationControl();
		~DataIntegrationControl();
		
		bool loadFile(string filename);
		//...
	
	private:
		ifstream* filestream;
		
		vector<DataTransaction*> transactions;
		//...
};

#endif
