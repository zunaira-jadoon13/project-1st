#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Structure to store menu items
struct MenuItem {
    string name;  
    float price; 
};

/*Function to load menu from file
* without this load menu we cannot 
* open save item in menu
*/

void loadMenu(vector<MenuItem>& menu) {
    ifstream file("menu.txt"); 
    menu.clear(); 

    string name;
    float price;

    // Read items from the file and add them to the menu
    while (file >> name >> price) {
        menu.push_back({ name, price });
    }
    file.close(); 
}

// Function to save menu to file
void saveMenu(const vector<MenuItem>& menu) {
    ofstream file("menu.txt"); 

    // Write each item to the file
    for (size_t i = 0; i < menu.size(); ++i) { // Loop through the menu
        file << menu[i].name << " " << menu[i].price << endl; // Write each item to the file
    }

    file.close(); // Close the file
}

// Function to display the menu
void viewMenu(const vector<MenuItem>& menu) {
    if (menu.empty()) {
        cout << "The menu is empty.\n";
        return;
    }

    cout << "Menu:" << endl;
    for (int i = 0; i < menu.size(); ++i) { 
        cout << menu[i].name << " -Rs" << menu[i].price << endl; 
    }
}

// Function to search for a menu item
void searchMenu(const vector<MenuItem>& menu) {
    string name;
    cout << "Enter item name to search: ";
    cin >> name; 

    // Search for the item
    for (int i = 0; i < menu.size(); ++i) {
        if (menu[i].name == name) { 
            cout << "Item found: " << menu[i].name << " -Rs" << menu[i].price << endl;
            return; 
        }
    }
    cout << "Item not found.\n";
}

// Function to add a menu item
void addMenuItem(vector<MenuItem>& menu) {
    string name;
    float price;
    cout << "Enter item name: ";
    cin >> name; 

    cout << "Enter item price: ";
    cin >> price;

    menu.push_back({ name, price });
    saveMenu(menu); 
    cout << "Item added successfully.\n";
}

// Function to remove a menu item
void removeMenuItem(vector<MenuItem>& menu) {
    string name;
    cout << "Enter item name to remove: ";
    cin >> name; 

    
    for (int i = 0; i < menu.size(); ++i) {
        if (menu[i].name == name) { 
            menu.erase(menu.begin() + i);
            saveMenu(menu); 
            cout << "Item removed successfully.\n";
            return; 
        }
    }
    cout << "Item not found.\n";
}
// Function to order items and generate a receipt
void orderItems(const vector<MenuItem>& menu) {
    if (menu.empty()) {
        cout << "The menu is empty. Cannot place an order.\n";
        return;
    }

    vector<MenuItem> order;
    string name;
    int quantity;
    char choice;
    float total = 0;

    do {
        cout << "Enter item name to order: ";
        cin >> name;

        bool found = false;
        for (const auto& item : menu) {
            if (item.name == name) {
                cout << "Enter quantity: ";
                cin >> quantity;
                order.push_back({ item.name, item.price * quantity });
                total += item.price * quantity;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Item not found.\n";
        }

        cout << "Do you want to order another item? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Generate receipt
    cout << "\nReceipt:\n";
    cout << "\n";
    cout << left << setw(20) << "Item" << right << setw(10) << "Price" << endl;
    cout << "----------------------------------\n";
    for (const auto& item : order) {
        cout << left << setw(20) << item.name << right << "Rs" << setw(9) << fixed << setprecision(2) << item.price << endl;
    }
    cout << "----------------------------------\n";
    cout << left << setw(20) << "Total" << right << "Rs" << setw(9) << fixed << setprecision(2) << total << endl;
}

#endif
