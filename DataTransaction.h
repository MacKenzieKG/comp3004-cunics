// DataTransaction.h 

#ifndef DIT_TRANSACTION_H
#define DIT_TRANSACTION_H

using namespace std;

#include <ifstream>
#include <string>

#include "Date.h"
#include "Employee.h"

//enum TransactionType { ADD_EMPLOYEE, UPDATE_BASIC_INFO, UPDATE_PAY_INFO };

class DataTransaction
{
	public:
		DataTransaction();
		~DataTransaction();
		
		bool apply();
		//...
	
	protected:
		//...
	
	private:
		//...
};

#endif