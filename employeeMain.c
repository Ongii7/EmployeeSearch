#include <string.h>
#include <stdlib.h>
#include "employee.h"
int main(void){
    //defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];    
    extern const int EmployeeTableEntries;     

    PtrToEmployee matchPtr;  //Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    //Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if (matchPtr != NULL)
        printf("Employee phone number 909-555-2134 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number is NOT found in the record\n");

    //Example not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-505-1234");
    if (matchPtr != NULL)
        printf("Employee phone number 909-555-2134 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);
    if (matchPtr != NULL)
        printf("Employee salary 7.80 is found in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary is NOT found in the record\n");

    //Example not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.90);
    if (matchPtr != NULL)
        printf("Employee salary 8.90 is found in record %d\n", matchPtr - EmployeeTable);
    else   
        printf("Employee salary is NOT found in the record\n");

    return EXIT_SUCCESS;
}