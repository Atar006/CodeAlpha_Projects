// CodeAlpha Internship - Task 4: Banking System
// Intern: Atar Ali
// Description: Simple banking system with deposit, withdraw, transfer and transaction history

#include <iostream>
#include <string>
using namespace std;

// max number of accounts and transactions
const int MAX_ACCOUNTS    = 10;
const int MAX_TRANSACTIONS = 50;

// account data
string accountNames[MAX_ACCOUNTS];
int    accountIDs  [MAX_ACCOUNTS];
float  balances    [MAX_ACCOUNTS];
int    accountCount = 0;
int    nextID       = 1001;

// transaction log
string transactionLog[MAX_TRANSACTIONS];
int    transactionCount = 0;

// helper to find account index by ID
int findAccount(int id) {
    for (int i = 0; i < accountCount; i++) {
        if (accountIDs[i] == id) return i;
    }
    return -1; // not found
}

void logTransaction(string message) {
    if (transactionCount < MAX_TRANSACTIONS) {
        transactionLog[transactionCount] = message;
        transactionCount++;
    }
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        cout << "Cannot create more accounts (limit reached)." << endl;
        return;
    }

    cout << "\n--- Create Account ---" << endl;

    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, accountNames[accountCount]);

    float initialDeposit;
    cout << "Initial deposit amount: $";
    cin >> initialDeposit;

    if (initialDeposit < 0) {
        cout << "Deposit amount cannot be negative." << endl;
        return;
    }

    accountIDs[accountCount] = nextID;
    balances  [accountCount] = initialDeposit;

    cout << "Account created successfully!" << endl;
    cout << "Account ID   : " << nextID << endl;
    cout << "Account Name : " << accountNames[accountCount] << endl;
    cout << "Balance      : $" << initialDeposit << endl;

    logTransaction("Account created for " + accountNames[accountCount] +
                   " | ID: " + to_string(nextID) +
                   " | Opening balance: $" + to_string(initialDeposit));

    accountCount++;
    nextID++;
}

void deposit() {
    cout << "\n--- Deposit ---" << endl;

    int id;
    cout << "Enter account ID: ";
    cin >> id;

    int index = findAccount(id);
    if (index == -1) {
        cout << "Account not found." << endl;
        return;
    }

    float amount;
    cout << "Enter deposit amount: $";
    cin >> amount;

    if (amount <= 0) {
        cout << "Amount must be greater than zero." << endl;
        return;
    }

    balances[index] += amount;

    cout << "Deposit successful!" << endl;
    cout << "New balance: $" << balances[index] << endl;

    logTransaction("Deposit | Account: " + to_string(id) +
                   " (" + accountNames[index] + ")" +
                   " | Amount: $" + to_string(amount) +
                   " | Balance: $" + to_string(balances[index]));
}

void withdraw() {
    cout << "\n--- Withdraw ---" << endl;

    int id;
    cout << "Enter account ID: ";
    cin >> id;

    int index = findAccount(id);
    if (index == -1) {
        cout << "Account not found." << endl;
        return;
    }

    float amount;
    cout << "Enter withdrawal amount: $";
    cin >> amount;

    if (amount <= 0) {
        cout << "Amount must be greater than zero." << endl;
        return;
    }

    if (amount > balances[index]) {
        cout << "Insufficient funds. Current balance: $" << balances[index] << endl;
        return;
    }

    balances[index] -= amount;

    cout << "Withdrawal successful!" << endl;
    cout << "New balance: $" << balances[index] << endl;

    logTransaction("Withdrawal | Account: " + to_string(id) +
                   " (" + accountNames[index] + ")" +
                   " | Amount: $" + to_string(amount) +
                   " | Balance: $" + to_string(balances[index]));
}

void transfer() {
    cout << "\n--- Transfer ---" << endl;

    int fromID, toID;
    cout << "From account ID: ";
    cin >> fromID;
    cout << "To account ID  : ";
    cin >> toID;

    int fromIndex = findAccount(fromID);
    int toIndex   = findAccount(toID);

    if (fromIndex == -1) { cout << "Source account not found."      << endl; return; }
    if (toIndex   == -1) { cout << "Destination account not found." << endl; return; }
    if (fromID    == toID){ cout << "Cannot transfer to same account." << endl; return; }

    float amount;
    cout << "Transfer amount: $";
    cin >> amount;

    if (amount <= 0) {
        cout << "Amount must be greater than zero." << endl;
        return;
    }

    if (amount > balances[fromIndex]) {
        cout << "Insufficient funds. Current balance: $" << balances[fromIndex] << endl;
        return;
    }

    balances[fromIndex] -= amount;
    balances[toIndex]   += amount;

    cout << "Transfer successful!" << endl;
    cout << accountNames[fromIndex] << " new balance: $" << balances[fromIndex] << endl;
    cout << accountNames[toIndex]   << " new balance: $" << balances[toIndex]   << endl;

    logTransaction("Transfer | From: " + to_string(fromID) +
                   " (" + accountNames[fromIndex] + ")" +
                   " -> To: " + to_string(toID) +
                   " (" + accountNames[toIndex] + ")" +
                   " | Amount: $" + to_string(amount));
}

void viewAccount() {
    cout << "\n--- Account Details ---" << endl;

    int id;
    cout << "Enter account ID: ";
    cin >> id;

    int index = findAccount(id);
    if (index == -1) {
        cout << "Account not found." << endl;
        return;
    }

    cout << "----------------------------" << endl;
    cout << "Account ID   : " << accountIDs[index] << endl;
    cout << "Name         : " << accountNames[index] << endl;
    cout << "Balance      : $" << balances[index] << endl;
    cout << "----------------------------" << endl;
}

void viewAllAccounts() {
    if (accountCount == 0) {
        cout << "No accounts found." << endl;
        return;
    }

    cout << "\n--- All Accounts ---" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < accountCount; i++) {
        cout << "ID: " << accountIDs[i]
             << " | Name: " << accountNames[i]
             << " | Balance: $" << balances[i] << endl;
    }
    cout << "----------------------------" << endl;
}

void viewTransactionHistory() {
    if (transactionCount == 0) {
        cout << "No transactions recorded." << endl;
        return;
    }

    cout << "\n--- Transaction History ---" << endl;
    for (int i = 0; i < transactionCount; i++) {
        cout << i + 1 << ". " << transactionLog[i] << endl;
    }
    cout << "----------------------------" << endl;
}

int main() {

    cout << "============================" << endl;
    cout << "      Banking System" << endl;
    cout << "============================" << endl;

    int choice;

    do {
        cout << "\n1. Create Account"         << endl;
        cout << "2. Deposit"                  << endl;
        cout << "3. Withdraw"                 << endl;
        cout << "4. Transfer"                 << endl;
        cout << "5. View Account"             << endl;
        cout << "6. View All Accounts"        << endl;
        cout << "7. Transaction History"      << endl;
        cout << "8. Exit"                     << endl;
        cout << "Choose: ";
        cin  >> choice;

        if      (choice == 1) createAccount();
        else if (choice == 2) deposit();
        else if (choice == 3) withdraw();
        else if (choice == 4) transfer();
        else if (choice == 5) viewAccount();
        else if (choice == 6) viewAllAccounts();
        else if (choice == 7) viewTransactionHistory();
        else if (choice == 8) cout << "Goodbye!" << endl;
        else                  cout << "Invalid option." << endl;

    } while (choice != 8);

    return 0;
}
