#include "file_operations.h"

// Function to update the account file after transactions
void updateAccountFile(vector<Account>& accounts) {
    ofstream outFile("bank_accounts.txt", ios::trunc);
    for (const auto& acc : accounts) {
        outFile << acc.name << "," << acc.accountNumber << "," << acc.balance << endl;
    }
    outFile.close();
}
