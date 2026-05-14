#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(string owner, double balance, double interestRate, string pin) : Account(owner, balance, pin)
{
    this->interestRate = interestRate;
}

void SavingsAccount::applyInterest()
{
    double interest = balance * interestRate;
    balance += interest;
    cout << " [%] Interest: " << interest << "eu. (" << interestRate * 100 << "%)\n";
    cout << "New balance: " << balance << " eu.\n";
}

void SavingsAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "[!] Need more money!\n";
        return;
    }
    if (amount > balance)
    {
        cout << " [!] Not enought balance! Savings Account: " << balance << "eu.\n";
        return;
    }
    balance -= amount;
    cout << " [-] Taken " << amount << "eu. from Savings Account.\n";
    cout << " New balance: " << balance << " eu.\n";
}

void SavingsAccount::display() const
{
    cout << " Owner        : " << owner << "\n";
    cout << " Type account : Savings\n";
    cout << " Balance      : " << balance << "eu.\n";
    cout << " Interest        :" << interestRate * 100 << "%\n";
}