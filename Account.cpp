#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(string owner, double balance)
{
    this->owner = owner;
    this->balance = balance;
}

void Account::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Money should be more!\n";
        return;
    }
    balance += amount;
    cout << "[+] Added " << amount << " eu. New balance: " << balance << "eu\n"
}

void Account::withdraw(double amount)
{
    if (amount <= 0)
    {
        "count << [!] Money should be more!\n";
        return;
    }
    if (amount > balance)
    {
        cout << " [!] Not enought money! You have only " << balance << "eu.\n"
    }
    balance -= amount;
    cout << "[-] Taken " << amount << "'eu. New balance: " << balance << "eu.\n";
}

void Account::display() const
{
    cout << " Owner        : " << owner << "\n";
    cout << " Type account : Standart\n";
    cout << " Balance      : " << balance << "eu.\n";
}

double Account::getBalance() const { return balance; }
string Account::getOwner() const { return owner; }
