#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(string owner, double balance, double interestRate, string pin)
    : Account(owner, balance, pin)
{
    this->interestRate = interestRate;
}

void SavingsAccount::applyInterest()
{
    double interest = balance * interestRate;
    balance += interest;
    cout << "  [%] Interest added: " << interest << " eu. (" << interestRate * 100 << "%)  New balance: " << balance << " eu.\n";
}

void SavingsAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "  [!] Amount must be positive.\n";
        return;
    }
    if (amount > balance)
    {
        cout << "  [!] Not enough money! Balance: " << balance << " eu.\n";
        return;
    }
    balance -= amount;
    cout << "  [-] Taken " << amount << " eu.  Main account: " << balance << " eu.\n";
}

void SavingsAccount::display() const
{
    cout << "  Owner         : " << owner << "\n";
    cout << "  Account type  : Savings\n";
    cout << "  Main account  : " << balance << " eu.\n";
    cout << "  Savings       : " << savings << " eu.\n";
    cout << "  Stocks        : " << stocks << " pcs.\n";
    cout << "  Interest rate : " << interestRate * 100 << "%\n";
}