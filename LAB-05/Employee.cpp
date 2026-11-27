#include "Employee.h"
#include <iostream>
using namespace std;

// Default constructor
Employee::Employee()
    : EmployeeId(0), name(""), designation(""), hourlyPayRate(0), numberOfHoursWorked(0), WEEKLY_WORKING_HOURS(40) {}

// Parameterized constructor
Employee::Employee(int id, string empName, string empDesignation, int payRate, int hoursWorked, int weeklyHours)
    : EmployeeId(id), name(empName), designation(empDesignation), hourlyPayRate(payRate), numberOfHoursWorked(hoursWorked), WEEKLY_WORKING_HOURS(weeklyHours) {}

// Destructor
Employee::~Employee() {}

// Mutators
void Employee::setEmployeeId(int id) {
    EmployeeId = id;
}

void Employee::setName(string empName) {
    name = empName;
}

void Employee::setDesignation(string empDesignation) {
    designation = empDesignation;
}

void Employee::setHourlyPayRate(int payRate) {
    if (payRate >= 0) {
        hourlyPayRate = payRate;
    }
}

void Employee::setNumberOfHoursWorked(int hoursWorked) {
    if (hoursWorked >= 0) {
        numberOfHoursWorked = hoursWorked;
    }
}

// Accessors
int Employee::getEmployeeId() const {
    return EmployeeId;
}

string Employee::getName() const {
    return name;
}

string Employee::getDesignation() const {
    return designation;
}

int Employee::getHourlyPayRate() const {
    return hourlyPayRate;
}

int Employee::getNumberOfHoursWorked() const {
    return numberOfHoursWorked;
}

int Employee::getWeeklyWorkingHours() const {
    return WEEKLY_WORKING_HOURS;
}

// Calculate overtime hours beyond WEEKLY_WORKING_HOURS (40)
int Employee::calculateOverTime() const {
    if (numberOfHoursWorked > WEEKLY_WORKING_HOURS) {
        return numberOfHoursWorked - WEEKLY_WORKING_HOURS;
    }
    return 0;
}

// Calculate weekly salary and reset the hours counter to 0
int Employee::calculateWeeklySalary() {
    int overtimeHours = calculateOverTime();
    int regularHours = numberOfHoursWorked - overtimeHours;

    int regularPay = regularHours * hourlyPayRate;
    int overtimePay = static_cast<int>(overtimeHours * (hourlyPayRate * 1.5));

    numberOfHoursWorked = 0; // reset the counter to 0

    return regularPay + overtimePay;
}

// Calculate monthly salary (4 weeks based on current hours)
int Employee::calculateMonthlySalary() {
    int weeklySalary = calculateWeeklySalary();
    return weeklySalary * 4;
}
