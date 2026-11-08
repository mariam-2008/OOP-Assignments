
#include <iostream>
using namespace std;

int main()
{
    int n;
    bool diagonal = true;

    cout << "Enter matrix size: ";
    cin >> n;

    int matrix[100][100];

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];

            if (i != j && matrix[i][j] != 0)
                diagonal = false;
        }
    }

    if (diagonal)
        cout << "The matrix is diagonal.";
    else
        cout << "The matrix is not diagonal.";

    return 0;
}
