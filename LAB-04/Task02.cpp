#include <iostream>
using namespace std;

class Counter {
private:
    int i; // an integer to hold the value of a counter

public:
    // initialize counter to zero
    Counter() {
        i = 0;
    }

    // initialize counter with given parameter value
    Counter(int a_val) {
        i = a_val;
    }

    // destructor should display message "Object is destroyed"
    ~Counter() {
        cout << "Object is destroyed" << endl;
    }

    // set counter value to given parameter value
    void setCounter(int a_intgr) {
        i = a_intgr;
    }

    // reset the counter to 0
    void reset() {
        i = 0;
    }

    // return the counter value
    int getCounter() const {
        return i;
    }

    // increment counter by 1
    void increment() {
        i++;
    }

    // increment counter by parameter value
    void increment(int a_val) {
        i += a_val;
    }

    // decrement counter by 1
    void decrement() {
        i--;
    }

    // decrement counter by parameter value
    void decrement(int a_val) {
        i -= a_val;
    }
};

// separate function to print all numbers in a user defined range
void printRange(int start, int end) {
    if (start <= end) {
        for (Counter c(start); c.getCounter() <= end; c.increment()) {
            cout << c.getCounter() << " ";
        }
    } else {
        for (Counter c(start); c.getCounter() >= end; c.decrement()) {
            cout << c.getCounter() << " ";
        }
    }
    cout << endl;
}

int main() {
    int length, width;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;

    // print a rectangle of the given size using Counter object in loops
    for (Counter row; row.getCounter() < length; row.increment()) {
        for (Counter col; col.getCounter() < width; col.increment()) {
            cout << "* ";
        }
        cout << endl;
    }

    int startVal, endVal;
    cout << "Enter range start: ";
    cin >> startVal;
    cout << "Enter range end: ";
    cin >> endVal;

    // call the separate function to demonstrate its working
    printRange(startVal, endVal);

    return 0;
}
