
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

struct InventoryItem
{
    string itemCode;
    string itemName;
    double cost;
    double sellingPrice;
};

int codeNumber = 31203;

InventoryItem insertItem()
{
    InventoryItem item;

    cout << "Enter item name: ";
    cin >> ws;
    getline(cin, item.itemName);

    cout << "Enter item cost: ";
    cin >> item.cost;

    string prefix = item.itemName.substr(0, 3);

    for (int i = 0; i < prefix.length(); i++)
        prefix[i] = toupper(prefix[i]);

    item.itemCode = prefix + "_" + to_string(codeNumber++);

    item.sellingPrice = item.cost * 1.40;

    return item;
}

void displayStock(const InventoryItem* items)
{
    cout << "\nCode\t\tName\t\tCost\tSelling Price\n";

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
    InventoryItem stock[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "\nItem " << i + 1 << endl;
        stock[i] = insertItem();
    }

    displayStock(stock);

    return 0;
}
