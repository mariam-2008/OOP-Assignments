#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:
    int EmployeeId;
    string name;
    string designation;
    int hourlyPayRate;
    int numberOfHoursWorked;
    const int WEEKLY_WORKING_HOURS;

public:
    // Default constructor
    Employee();

    // Parameterized constructor
    Employee(int id, string empName, string empDesignation, int payRate, int hoursWorked, int weeklyHours = 40);

    // Destructor
    ~Employee();

    // Mutators (setters)
    void setEmployeeId(int id);
    void setName(string empName);
    void setDesignation(string empDesignation);
    void setHourlyPayRate(int payRate);
    void setNumberOfHoursWorked(int hoursWorked);

    // Accessors (getters)
    int getEmployeeId() const;
    string getName() const;
    string getDesignation() const;
    int getHourlyPayRate() const;
    int getNumberOfHoursWorked() const;
    int getWeeklyWorkingHours() const;

    // Member functions
    int calculateMonthlySalary();
    int calculateWeeklySalary(); // reset the counter to 0.
    int calculateOverTime() const; // return the counter value.
};

#endif
