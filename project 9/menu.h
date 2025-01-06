#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
        cout << menu[i].name << " - $" << menu[i].price << endl; 
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
            cout << "Item found: " << menu[i].name << " - $" << menu[i].price << endl;
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

#endif