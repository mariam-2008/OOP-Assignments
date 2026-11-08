
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct InventoryItem
{
    int itemCode;
    string itemName;
    double cost;
    double sellingPrice;
};

InventoryItem insertItem()
{
    InventoryItem item;

    cout << "Enter item name: ";
    cin >> ws;
    getline(cin, item.itemName);

    cout << "Enter item cost: ";
    cin >> item.cost;

    item.itemCode = rand() % 9000 + 1000;
    item.sellingPrice = item.cost * 1.40;

    return item;
}

void displayStock(const InventoryItem* items)
{
    cout << "\nCode\tName\t\tCost\tSelling Price\n";

    for (int i = 0; i < 10; i++)
    {
        cout << items[i].itemCode << "\t"
             << items[i].itemName << "\t\t"
             << items[i].cost << "\t"
             << items[i].sellingPrice << endl;
    }
}

int main()
{
    srand(time(0));

    InventoryItem stock[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "\nItem " << i + 1 << endl;
        stock[i] = insertItem();
    }

    displayStock(stock);

    return 0;
}
