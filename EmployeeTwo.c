#include <string.h>
#include "Employee.h"

static PtrToEmployee searchEmployeeTable(PtrtoConstEmployee ptr, int tableSize, const void *targetPtr, int (*functionPtr)(const void *, PtrtoConstEmployee))
{
    PtrtoConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++)
    {
        if((*functionPtr)(targetPtr, ptr) == 0)
        {
            return (PtrToEmployee) ptr;
        }
    }
    return NULL;
}

static int compareEmployeeNumber(const void *targetPtr, PtrtoConstEmployee tableValuePtr)
{
    return * (long *) targetPtr != tableValuePtr->number;
}
static int compareEmployeeName(const void *targetPtr, PtrtoConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr->name);
}
static int compareEmployeePhoneNumber(const void *targetPtr, PtrtoConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr->phone);
}
static int compareEmployeeSalary(const void *targetPtr, PtrtoConstEmployee tableValuePtr)
{
    return * (double *) targetPtr != tableValuePtr->number;
}

PtrToEmployee searchEmployeeByNumber(PtrtoConstEmployee ptr, int size, long number)
{
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}
PtrToEmployee searchEmployeeByName(PtrtoConstEmployee ptr, int size, char* name)
{
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}
PtrToEmployee searchEmployeeByPhoneNumber(PtrtoConstEmployee ptr, int size, char* phone)
{
    return searchEmployee(ptr, size, phone, compareEmployeePhoneNumber);
}
PtrToEmployee searchEmployeeBySalary(PtrtoConstEmployee ptr, int size, double salary)
{
    return searchEmployeeTable(ptr, size, &salary, compareEmployeeSalary);
}