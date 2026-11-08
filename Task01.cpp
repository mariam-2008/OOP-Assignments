#include <iostream>
using namespace std;

int* resizeArray(int inArray[], const int size)
{
    int* newArray = new int[size * 2];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = inArray[i];
        newArray[i + size] = inArray[i] * 2;
    }

    return newArray;
}

int main()
{
    int size;

    cout << "Enter size of the array: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    int* inArray = new int[size];

    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> inArray[i];
    }

    int* newArray = resizeArray(inArray, size);

    cout << "Resized array: ";
    for (int i = 0; i < size * 2; i++)
    {
        cout << newArray[i];
        if (i < size * 2 - 1)
            cout << ", ";
    }

    cout << endl;

    delete[] inArray;
    delete[] newArray;

    return 0;
}
