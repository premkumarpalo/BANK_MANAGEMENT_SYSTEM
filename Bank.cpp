#include "account.h"
#include "transactions.h"

int main() {
    int choice, accNum;
    double amount;

    do {
        cout << "\nBank Management System";
        cout << "\n1. Create Account";
        cout << "\n2. View Accounts";
        cout << "\n3. Deposit Money";
        cout << "\n4. Withdraw Money";
        cout << "\n5. Remove Account";  // <-- Add menu option
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                depositMoney(accNum, amount);
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                withdrawMoney(accNum, amount);
                break;
            case 5:
                cout << "Enter Account Number to Remove: ";
                cin >> accNum;
                removeAccount(accNum);  // <-- Call removeAccount function
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
