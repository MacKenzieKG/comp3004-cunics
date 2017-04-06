#ifndef DEFS_H
#define DEFS_H

#include <string>

typedef enum { FULL_TIME, PART_TIME, NO_TIME }   RoleTime;
const std::string RoleTimeStrings[3] = {"Full-time","Part-time","NO_TIME"};
typedef enum { STAFF, FACULTY, TA, RA, NO_TYPE } RoleType;
const std::string RoleTypeStrings[5] = {"Staff","Faculty","TA","RA","NO_TYPE"};
typedef enum { CONTINUING, TERM, FAIL }       EmployeeType;
const std::string EmployeeTypeStrings[3] = {"Continuing","Term","FAIL"};

#define MAX_ROLE  3
#define MAX_STR 64

#endif
