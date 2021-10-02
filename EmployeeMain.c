#include <string.h>
#include <stdlib.h>
#include "Employee.h"

int main(void)
{
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * phoneNumberToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries[];

    PtrToEmployee matchPtr;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTable, 1045);

    if(matchPtr != NULL)
    {
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee ID is NOT found in the record\n");
    }

    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if(matchPtr != NULL)
    {
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee Tony Bobcat is NOT found in the record\n");
    }

    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if(matchPtr != NULL)
    {
        printf("Employee Phone Number is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee Phone Number is NOT in record %d\n", matchPtr - EmployeeTable);
    }

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);
    if(matchPtr != NULL)
    {
        printf("Employee Salary is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee Salary is NOT in record %d\n", matchPtr - EmployeeTable);
    }
    return EXIT_SUCCESS;
}