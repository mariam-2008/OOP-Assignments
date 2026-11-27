#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    // Example from lab sheet: rate = 100, hours = 52 -> overtime = 12, weekly salary = 11800
    Employee emp1(101, "Ali Ahmed", "Software Engineer", 100, 52);

    cout << "=== Employee 1 ===" << endl;
    cout << "ID: " << emp1.getEmployeeId() << endl;
    cout << "Name: " << emp1.getName() << endl;
    cout << "Designation: " << emp1.getDesignation() << endl;
    cout << "Weekly Working Hours Limit: " << emp1.getWeeklyWorkingHours() << endl;
    cout << "Overtime Hours: " << emp1.calculateOverTime() << endl;
    cout << "Weekly Salary: " << emp1.calculateWeeklySalary() << endl;
    cout << "Hours after weekly reset: " << emp1.getNumberOfHoursWorked() << endl;

    cout << "\n=== Employee 2 (Pointer & Default Constructor) ===" << endl;
    Employee* empPtr = new Employee();
    empPtr->setEmployeeId(102);
    empPtr->setName("Noor Hassan");
    empPtr->setDesignation("AI Developer");
    empPtr->setHourlyPayRate(80);
    empPtr->setNumberOfHoursWorked(40);

    cout << "ID: " << empPtr->getEmployeeId() << endl;
    cout << "Name: " << empPtr->getName() << endl;
    cout << "Designation: " << empPtr->getDesignation() << endl;
    cout << "Overtime Hours: " << empPtr->calculateOverTime() << endl;
    cout << "Monthly Salary (4 weeks at current hours): " << empPtr->calculateMonthlySalary() << endl;

    delete empPtr;
    empPtr = nullptr;

    return 0;
}
