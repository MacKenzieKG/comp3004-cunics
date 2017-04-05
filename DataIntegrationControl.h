// DataIntegrationControl.h 

#ifndef DIT_CONTROL_H
#define DIT_CONTROL_H

using namespace std;

#include <ifstream>
#include <string>

#include "Date.h"
#include "Employee.h"

class DataIntegrationControl
{
	public:
		DataIntegrationControl();
		//...
	
	private:
		void parseFile(string filename);
		ifstream* filestream;
		//...
};

#endif
