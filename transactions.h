#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "file_operations.h"

void depositMoney(int accNum, double amount);
void withdrawMoney(int accNum, double amount);
void removeAccount(int accNum);
#endif // TRANSACTIONS_H
