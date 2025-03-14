#include "transactions.h"
#include "transactions.h"

// Function to remove an account
void removeAccount(int accNum) {
    ifstream file("bank_accounts.txt");
    vector<Account> accounts;
    Account acc;
    bool found = false;
    string line;

    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        if (pos1 == string::npos || pos2 == string::npos) continue;

        acc.name = line.substr(0, pos1);
        acc.accountNumber = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        acc.balance = stod(line.substr(pos2 + 1));

        if (acc.accountNumber == accNum) {
            found = true;  // Mark this account for removal
        } else {
            accounts.push_back(acc);
        }
    }
    file.close();

    if (!found) {
        cout << "Account not found!\n";
        return;
    }

    // Update the file with remaining accounts
    updateAccountFile(accounts);
    cout << "Account removed successfully!\n";
}

// Function to deposit money
void depositMoney(int accNum, double amount) {
    ifstream file("bank_accounts.txt");
    vector<Account> accounts;
    Account acc;
    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        if (pos1 == string::npos || pos2 == string::npos) continue;

        acc.name = line.substr(0, pos1);
        acc.accountNumber = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        acc.balance = stod(line.substr(pos2 + 1));

        if (acc.accountNumber == accNum) {
            acc.balance += amount;
            found = true;
        }
        accounts.push_back(acc);
    }
    file.close();

    if (!found) {
        cout << "Account not found!\n";
        return;
    }

    updateAccountFile(accounts);
    cout << "Deposit successful! New Balance: $" << acc.balance << endl;
}

// Function to withdraw money
void withdrawMoney(int accNum, double amount) {
    ifstream file("bank_accounts.txt");
    vector<Account> accounts;
    Account acc;
    bool found = false, insufficientFunds = false;
    string line;

    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        if (pos1 == string::npos || pos2 == string::npos) continue;

        acc.name = line.substr(0, pos1);
        acc.accountNumber = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        acc.balance = stod(line.substr(pos2 + 1));

        if (acc.accountNumber == accNum) {
            if (acc.balance >= amount) {
                acc.balance -= amount;
                found = true;
            } else {
                insufficientFunds = true;
            }
        }
        accounts.push_back(acc);
    }
    file.close();

    if (insufficientFunds) {
        cout << "Insufficient funds!\n";
        return;
    }

    if (!found) {
        cout << "Account not found!\n";
        return;
    }

    updateAccountFile(accounts);
    cout << "Withdrawal successful! New Balance: $" << acc.balance << endl;
}
