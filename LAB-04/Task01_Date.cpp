#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

    string getMonthName(int m) const {
        string months[] = {
            "", "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        if (m >= 1 && m <= 12) {
            return months[m];
        }
        return "";
    }

public:
    // Default constructor
    Date() {
        month = 1;
        day = 1;
        year = 2000;
    }

    // Mutator functions with input validation
    void setMonth(int m) {
        if (m < 1 || m > 12) {
            cout << "Error: Invalid month! Value rejected.\n";
            return;
        }
        month = m;
    }

    void setDay(int d) {
        if (d < 1 || d > 31) {
            cout << "Error: Invalid day! Value rejected.\n";
            return;
        }
        day = d;
    }

    void setYear(int y) {
        year = y;
    }

    // Three print formats
    void printNumeric() const {
        cout << month << "/" << day << "/" << year << endl;
    }

    void printMonthDayYear() const {
        cout << getMonthName(month) << " " << day << ", " << year << endl;
    }

    void printDayMonthYear() const {
        cout << day << " " << getMonthName(month) << " " << year << endl;
    }
};

int main() {
    Date dateObj;

    dateObj.setMonth(12);
    dateObj.setDay(25);
    dateObj.setYear(2012);

    dateObj.printNumeric();
    dateObj.printMonthDayYear();
    dateObj.printDayMonthYear();

    // Input validation test
    dateObj.setMonth(15); // Rejected
    dateObj.setDay(35);   // Rejected

    return 0;
}
