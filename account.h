#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Account {
    string name;
    int accountNumber;
    double balance;
};

void createAccount();
void viewAccounts();

#endif // ACCOUNT_H
