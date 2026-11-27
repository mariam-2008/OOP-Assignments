#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string Name;
    int idNumber;
    string Department;
    string Position;

public:
    // Constructor accepting Name, idNumber, Department, and Position
    Employee(string empName, int empId, string empDept, string empPos) {
        Name = empName;
        idNumber = empId;
        Department = empDept;
        Position = empPos;
    }

    // Constructor accepting Name and idNumber; Department and Position assigned ""
    Employee(string empName, int empId) {
        Name = empName;
        idNumber = empId;
        Department = "";
        Position = "";
    }

    // Default constructor assigning "" to strings and 0 to idNumber
    Employee() {
        Name = "";
        idNumber = 0;
        Department = "";
        Position = "";
    }

    // Mutator functions (setters)
    void setName(string empName) {
        Name = empName;
    }

    void setIdNumber(int empId) {
        idNumber = empId;
    }

    void setDepartment(string empDept) {
        Department = empDept;
    }

    void setPosition(string empPos) {
        Position = empPos;
    }

    // Accessor functions (getters)
    string getName() const {
        return Name;
    }

    int getIdNumber() const {
        return idNumber;
    }

    string getDepartment() const {
        return Department;
    }

    string getPosition() const {
        return Position;
    }
};

int main() {
    // Creating five Employee objects holding the table data
    Employee emp1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee emp2("Mark Jones", 39119, "IT", "Programmer");
    Employee emp3("Jay Rogers", 81447, "Manufacturing", "Engineer");
    Employee emp4("Lionel Messi", 52362, "HR", "Manager");
    Employee emp5("Roger Federer", 54124, "Finance", "Auditor");

    Employee team[5] = {emp1, emp2, emp3, emp4, emp5};

    cout << "Name\t\tID Number\tDepartment\tPosition\n";
    cout << "------------------------------------------------------------------\n";
    for (int i = 0; i < 5; i++) {
        cout << team[i].getName() << "\t"
             << team[i].getIdNumber() << "\t\t"
             << team[i].getDepartment() << "\t\t"
             << team[i].getPosition() << endl;
    }

    return 0;
}
