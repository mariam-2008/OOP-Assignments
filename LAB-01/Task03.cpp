
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[30];
    int count;

    cout << "Enter a string: ";
    cin.getline(str, 30);

    cout << "Enter substring length: ";
    cin >> count;

    int length = strlen(str);

    if (count < 0 || count > length)
    {
        cout << "Count is out of range.";
    }
    else
    {
        cout << "Substring: ";

        for (int i = 0; i < count; i++)
            cout << str[i];
    }

    return 0;
}
