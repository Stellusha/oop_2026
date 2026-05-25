#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(string owner, double balance, string pin)
{
    this->owner = owner;
    this->balance = balance;
    this->savings = 0.0;
    this->stocks = 0.0;
    this->pin = pin;
}

bool Account::checkPin(const string &inputPin) const
{
    return inputPin == pin;
}

void Account::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "  [!] Amount must be positive.\n";
        return;
    }
    balance += amount;
    cout << "  [+] Added " << amount << " eu.  Main account: " << balance << " eu.\n";
}

void Account::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "  [!] Amount must be positive.\n";
        return;
    }
    if (amount > balance)
    {
        cout << "  [!] Not enough money! You have only " << balance << " eu.\n";
        return;
    }
    balance -= amount;
    cout << "  [-] Taken " << amount << " eu.  Main account: " << balance << " eu.\n";
}

void Account::transferToSavings(double amount)
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
    savings += amount;
    cout << "  [>>] Transferred " << amount << " eu. to savings account.\n";
    cout << "       Main account: " << balance << " eu.  |  Savings: " << savings << " eu.\n";
}

void Account::transferToMain(double amount)
{
    if (amount <= 0)
    {
        cout << "  [!] Amount must be positive.\n";
        return;
    }
    if (amount > savings)
    {
        cout << "  [!] Not enough in savings! Savings: " << savings << " eu.\n";
        return;
    }
    savings -= amount;
    balance += amount;
    cout << "  [<<] Transferred " << amount << " eu. to main account.\n";
    cout << "       Main account: " << balance << " eu.  |  Savings: " << savings << " eu.\n";
}

void Account::buyStocks(double pricePerStock, int quantity)
{
    if (quantity <= 0)
    {
        cout << "  [!] Quantity must be positive.\n";
        return;
    }
    double total = pricePerStock * quantity;
    if (total > balance)
    {
        cout << "  [!] Not enough balance! Needed: " << total << " eu.  Balance: " << balance << " eu.\n";
        return;
    }
    balance -= total;
    stocks += quantity;
    cout << "  [$] Bought " << quantity << " stocks at " << pricePerStock << " eu. = " << total << " eu.\n";
    cout << "      Stocks: " << stocks << " pcs.  Balance: " << balance << " eu.\n";
}

void Account::sellStocks(double pricePerStock, int quantity)
{
    if (quantity <= 0)
    {
        cout << "  [!] Quantity must be positive.\n";
        return;
    }
    if (quantity > stocks)
    {
        cout << "  [!] Not enough stocks! You have: " << stocks << " pcs.\n";
        return;
    }
    double total = pricePerStock * quantity;
    stocks -= quantity;
    balance += total;
    cout << "  [$] Sold " << quantity << " stocks at " << pricePerStock << " eu. = " << total << " eu.\n";
    cout << "      Stocks: " << stocks << " pcs.  Balance: " << balance << " eu.\n";
}

bool Account::transferTo(Account &target, double amount)
{
    if (amount <= 0)
    {
        cout << "  [!] Amount must be positive.\n";
        return false;
    }
    if (amount > balance)
    {
        cout << "  [!] Not enough money! Balance: " << balance << " eu.\n";
        return false;
    }
    balance -= amount;
    target.balance += amount;
    cout << "  [->] Transferred " << amount << " eu. to " << target.getOwner() << ".\n";
    cout << "       Your main account: " << balance << " eu.\n";
    return true;
}

void Account::display() const
{
    cout << "  Owner         : " << owner << "\n";
    cout << "  Account type  : Standard\n";
    cout << "  Main account  : " << balance << " eu.\n";
    cout << "  Savings       : " << savings << " eu.\n";
    cout << "  Stocks        : " << stocks << " pcs.\n";
}

double Account::getBalance() const { return balance; }
double Account::getSavings() const { return savings; }
double Account::getStocks() const { return stocks; }
string Account::getOwner() const { return owner; }