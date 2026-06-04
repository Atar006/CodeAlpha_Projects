// CodeAlpha Internship - Task 2: Login and Registration System
// Intern: Atar Ali
// Description: Register a username and password, then login with them

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// check if username already exists in the file
bool usernameExists(string username) {
    ifstream file("users.txt");
    string storedUser, storedPass;

    while (file >> storedUser >> storedPass) {
        if (storedUser == username) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void registerUser() {
    cout << "\n--- Register ---" << endl;

    string username, password, confirmPassword;

    cout << "Enter username: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << "Username already taken. Try a different one." << endl;
        return;
    }

    cout << "Enter password (min 6 characters): ";
    cin >> password;

    if (password.length() < 6) {
        cout << "Password too short. Must be at least 6 characters." << endl;
        return;
    }

    cout << "Confirm password: ";
    cin >> confirmPassword;

    if (password != confirmPassword) {
        cout << "Passwords do not match." << endl;
        return;
    }

    // save to file
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful! You can now login." << endl;
}

void loginUser() {
    cout << "\n--- Login ---" << endl;

    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string storedUser, storedPass;
    bool found = false;

    while (file >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "Login successful! Welcome, " << username << "!" << endl;
    } else {
        cout << "Incorrect username or password." << endl;
    }
}

int main() {

    cout << "============================" << endl;
    cout << "  Login & Registration" << endl;
    cout << "============================" << endl;

    int choice;

    do {
        cout << "\n1. Register" << endl;
        cout << "2. Login"    << endl;
        cout << "3. Exit"     << endl;
        cout << "Choose: ";
        cin  >> choice;

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            loginUser();
        } else if (choice == 3) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid option." << endl;
        }

    } while (choice != 3);

    return 0;
}
