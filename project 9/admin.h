#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
using namespace std;

// Function to handle admin login
bool adminLogin() {
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    
    
    if (username == "admin" && password == "password123") {
        cout << "Welcome Admin!\n";
        return true;
    }
    cout << "Invalid credentials. Try again.\n";
    return false;
}

#endif