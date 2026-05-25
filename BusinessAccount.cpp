#include "BusinessAccount.h"
#include <iostream>
using namespace std;

BusinessAccount::BusinessAccount(string owner, double balance, double fee, string pin) : Account(owner, balance, pin)
{
    this->fee = fee;
}

void BusinessAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << " [!] You need more money!\n";
        return;
    }
    double total = amount + fee;
    if (total > balance)
    {
        cout << " [!] You need more money!\n";
        cout << "Needed: " << amount << "eu. + tax: " << fee << " eu. = " << total << "eu.\n";
        cout << "Balance: " << balance << " eu.\n";
        return;
    }
    balance -= total;
    cout << " [-] Taken" << amount << " eu. (tx: " << fee << " eu.)\n";
    cout << "New balance: " << balance << " eu.\n";
}

void BusinessAccount::display() const
{
    cout << "  Owner         : " << owner << "\n";
    cout << "  Account type  : Business\n";
    cout << "  Main account  : " << balance << " eu.\n";
    cout << "  Savings       : " << savings << " eu.\n";
    cout << "  Stocks        : " << stocks << " pcs.\n";
    cout << "  Withdraw fee  : " << fee << " eu.\n";
}
