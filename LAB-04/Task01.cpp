#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ==========================================
// 1. Date Class Definition
// ==========================================
class Date {
private:
    int month;
    int day;
    int year;

    // Helper function to convert month number to month name
    string getMonthName() const {
        const string months[12] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        if (month >= 1 && month <= 12) {
            return months[month - 1];
        }
        return "InvalidMonth";
    }

public:
    // Default constructor
    Date() {
        month = 1;
        day = 1;
        year = 2000;
    }

    // Mutator functions (Setters) with input validation
    void setMonth(int m) {
        if (m < 1 || m > 12) {
            cout << "Invalid month (" << m << "). Month must be between 1 and 12.\n";
            return;
        }
        month = m;
    }

    void setDay(int d) {
        if (d < 1 || d > 31) {
            cout << "Invalid day (" << d << "). Day must be between 1 and 31.\n";
            return;
        }
        day = d;
    }

    void setYear(int y) {
        year = y;
    }

    // Print format 1: 12/25/2012
    void printSlashFormat() const {
        cout << month << "/" << day << "/" << year << endl;
    }

    // Print format 2: December 25, 2012
    void printMonthDayYear() const {
        cout << getMonthName() << " " << day << ", " << year << endl;
    }

    // Print format 3: 25 December 2012
    void printDayMonthYear() const {
        cout << day << " " << getMonthName() << " " << year << endl;
    }
};

// ==========================================
// 2. Employee Class Definition
// ==========================================
class Employee {
private:
    string name;
    int idNumber;
    string department;
    string position;

public:
    // Constructor 1: Accepts all four values
    Employee(string empName, int empId, string empDept, string empPos) {
        name = empName;
        idNumber = empId;
        department = empDept;
        position = empPos;
    }

    // Constructor 2: Accepts name and ID number; department and position set to ""
    Employee(string empName, int empId) {
        name = empName;
        idNumber = empId;
        department = "";
        position = "";
    }

    // Constructor 3: Default constructor
    Employee() {
        name = "";
        idNumber = 0;
        department = "";
        position = "";
    }

    // Mutator functions (Setters)
    void setName(string empName) { name = empName; }
    void setIdNumber(int empId) { idNumber = empId; }
    void setDepartment(string empDept) { department = empDept; }
    void setPosition(string empPos) { position = empPos; }

    // Accessor functions (Getters)
    string getName() const { return name; }
    int getIdNumber() const { return idNumber; }
    string getDepartment() const { return department; }
    string getPosition() const { return position; }

    // Helper function to display employee details
    void displayEmployee() const {
        cout << left
             << setw(18) << name
             << setw(12) << idNumber
             << setw(16) << department
             << setw(18) << position << endl;
    }
};

// ==========================================
// Main Program
// ==========================================
int main() {
    // --- Part 1: Demonstrating Date Class ---
    cout << "==============================\n";
    cout << "      PART 1: DATE CLASS      \n";
    cout << "==============================\n";

    Date d1;
    d1.setMonth(12);
    d1.setDay(25);
    d1.setYear(2012);

    cout << "Valid Date Formats:\n";
    d1.printSlashFormat();
    d1.printMonthDayYear();
    d1.printDayMonthYear();

    cout << "\nTesting Input Validation:\n";
    d1.setDay(35);
    d1.setDay(0);
    d1.setMonth(13);
    d1.setMonth(0);

    // --- Part 2: Demonstrating Employee Class ---
    cout << "\n==============================\n";
    cout << "    PART 2: EMPLOYEE CLASS    \n";
    cout << "==============================\n";

    Employee emp1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee emp2("Mark Jones", 39119, "IT", "Programmer");
    Employee emp3("Jay Rogers", 81447, "Manufacturing", "Engineer");
    Employee emp4("Lionel Messi", 52362, "HR", "Manager");
    Employee emp5("Roger Federer", 54124, "Finance", "Auditor");

    cout << left
         << setw(18) << "Name"
         << setw(12) << "ID Number"
         << setw(16) << "Department"
         << setw(18) << "Position" << endl;
    cout << string(64, '-') << endl;

    emp1.displayEmployee();
    emp2.displayEmployee();
    emp3.displayEmployee();
    emp4.displayEmployee();
    emp5.displayEmployee();

    return 0;
}
