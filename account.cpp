#include "account.h"

const string FILE_NAME = "bank_accounts.txt";

// Function to create a new account
void createAccount() {
    Account acc;
    cout << "Enter Account Holder's Name: ";
    cin.ignore();
    getline(cin, acc.name);
    cout << "Enter Account Number: ";
    cin >> acc.accountNumber;
    cout << "Enter Initial Balance: ";
    cin >> acc.balance;

    ofstream file(FILE_NAME, ios::app);
    if (file.is_open()) {
        file << acc.name << "," << acc.accountNumber << "," << acc.balance << endl;
        file.close();
        cout << "Account created successfully!\n";
    } else {
        cout << "Error opening file!\n";
    }
}

// Function to view all accounts
void viewAccounts() {
    ifstream file(FILE_NAME);
    if (!file.is_open()) {
        cout << "No accounts found!\n";
        return;
    }

    string line;
    cout << "\nBank Accounts:\n";
    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        if (pos1 == string::npos || pos2 == string::npos) continue;

        string name = line.substr(0, pos1);
        int accountNumber = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        double balance = stod(line.substr(pos2 + 1));

        cout << "Name: " << name << " | Account Number: " << accountNumber << " | Balance: $" << balance << endl;
    }
    file.close();
}
