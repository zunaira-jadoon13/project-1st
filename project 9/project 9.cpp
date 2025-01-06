#include "Admin.h"
#include "Menu.h"

int main() {
    vector<MenuItem> menu;
    loadMenu(menu);

    cout << "WELCOME TO OUR RESTAURANT\n";
    if (!adminLogin()) {
        return 0; // Exit if admin login fails
    }

    int choice;
    do {
        cout << "\n1. View Menu\n2. Search Menu\n3. Add Item\n4. Remove Item\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            viewMenu(menu);
            break;
        case 2:
            searchMenu(menu);
            break;
        case 3:
            addMenuItem(menu);
            break;
        case 4:
            removeMenuItem(menu);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}