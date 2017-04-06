OBJ = testmain.o DataFileUpdater.o Employee.o EmployeeList.o Role.o PaystubList.o Date.o EmployeeLoader.o

FileUpdateTest: $(OBJ)
	g++ -o FileUpdateTest $(OBJ)
	
testmain.o: testmain.cc
	g++ -c testmain.cc
	
DataFileUpdater.o: DataFileUpdater.cc DataFileUpdater.h defs.h
	g++ -c DataFileUpdater.cc
	
EmployeeList.o: EmployeeList.cc EmployeeList.h
	g++ -c EmployeeList.cc
	
Employee.o: Employee.cc Employee.h
	g++ -c Employee.cc
	
Role.o: Role.cc Role.h
	g++ -c Role.cc
	
PaystubList.o: PaystubList.cc PaystubList.h
	g++ -c PaystubList.cc
	
Date.o: Date.cc Date.h
	g++ -c Date.cc
	
EmployeeLoader.o: EmployeeLoader.cc EmployeeLoader.h
	g++ -c EmployeeLoader.cc
	
clean:
	rm -f *.o FileUpdateTest