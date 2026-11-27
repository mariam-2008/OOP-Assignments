#include <iostream>
using namespace std;

class Box {
private:
    int length;
    int width;
    int height;

public:
    // Default constructor
    Box() : length(0), width(0), height(0) {}

    // Parameterized constructor
    Box(int l, int w, int h) : length(l), width(w), height(h) {}

    // Destructor
    ~Box() {
        // Optional message to trace object destruction
    }

    // Setters
    void setLength(int l) { length = l; }
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }

    // Getters
    int getLength() const { return length; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    // Compute and return volume
    int getVolume() {
        return length * width * height;
    }
};

// Global function to sort Box array in ascending order by volume
void sortArray(Box* boxArray, const int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (boxArray[j].getVolume() > boxArray[j + 1].getVolume()) {
                Box temp = boxArray[j];
                boxArray[j] = boxArray[j + 1];
                boxArray[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter number of boxes: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid array size." << endl;
        return 0;
    }

    // Dynamic array of Box objects
    Box* boxArray = new Box[size];

    for (int i = 0; i < size; i++) {
        int l, w, h;
        cout << "\nBox " << (i + 1) << ":" << endl;
        cout << "Enter length: ";
        cin >> l;
        cout << "Enter width: ";
        cin >> w;
        cout << "Enter height: ";
        cin >> h;

        boxArray[i].setLength(l);
        boxArray[i].setWidth(w);
        boxArray[i].setHeight(h);
    }

    // Sort boxes by volume in ascending order
    sortArray(boxArray, size);

    cout << "\nBoxes sorted by volume (ascending):" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Box " << (i + 1)
             << " -> Length: " << boxArray[i].getLength()
             << ", Width: " << boxArray[i].getWidth()
             << ", Height: " << boxArray[i].getHeight()
             << ", Volume: " << boxArray[i].getVolume() << endl;
    }

    // Free dynamically allocated memory
    delete[] boxArray;

    return 0;
}
