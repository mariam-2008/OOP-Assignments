
#include <iostream>
#include <iomanip>
using namespace std;

struct FeetInches
{
    int feet;
    int inches;
};

struct RoomDimension
{
    FeetInches length;
    FeetInches width;
};

double computeTheCarpetingCost(const RoomDimension& room)
{
    double length = room.length.feet +
                    room.length.inches / 12.0;

    double width = room.width.feet +
                   room.width.inches / 12.0;

    return length * width * 18;
}

int main()
{
    int n;

    cout << "Enter number of rooms: ";
    cin >> n;

    RoomDimension* rooms = new RoomDimension[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nRoom " << i + 1 << endl;

        cout << "Enter length (feet inches): ";
        cin >> rooms[i].length.feet
            >> rooms[i].length.inches;

        cout << "Enter width (feet inches): ";
        cin >> rooms[i].width.feet
            >> rooms[i].width.inches;
    }

    int choice;

    cout << "\n1. Total carpeting cost";
    cout << "\n2. Cost for each room";
    cout << "\nEnter your choice: ";
    cin >> choice;

    double total = 0;

    if (choice == 1)
    {
        for (int i = 0; i < n; i++)
            total += computeTheCarpetingCost(rooms[i]);

        cout << fixed << setprecision(2);
        cout << "Total cost = Rs. " << total;
    }
    else if (choice == 2)
    {
        for (int i = 0; i < n; i++)
        {
            double cost = computeTheCarpetingCost(rooms[i]);

            cout << "Room " << i + 1
                 << " cost = Rs. " << cost << endl;

            total += cost;
        }

        cout << "Total cost = Rs. " << total;
    }
    else
    {
        cout << "Invalid choice.";
    }

    delete[] rooms;

    return 0;
}
