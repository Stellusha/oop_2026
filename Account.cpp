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
        cout << "Money should be more!\n";
        return;
    }
    balance += amount;
    cout << "[+] Added " << amount << " eu. New balance: " << balance << "eu\n";
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
        cout << " [!] Not enought money! You have only " << balance << "eu.\n";
    }
    balance -= amount;
    cout << "[-] Taken " << amount << "'eu. New balance: " << balance << "eu.\n";
}

void Account::transferToSavings(double amount)
{
    if (amount <= 0)
    {
        cout << " [!] You need more money!\n";
        return;
    }
    if (amount > balance)
    {
        cout << " [!] Not enough money! Balance: " << balance << "eu.\n";
        return;
    }
    balance -= amount;
    savings += amount;
    cout << " [>>] Transfered " << amount << "eu. to savings account.\n";
    cout << "      Main account: " <, balance << "eu. | Savings: " << savings << "eu.\n";
}

void Account::transferToMain(double amount)
{
    if (amount <= 0)
    {
        cout << " [!] You need more money!\n";
        return;
    }
    if (amount > balance)
    {
        cout << " [!] Not enough money! Balance: " << balance << "eu.\n";
        return;
    }
    savings -= amount;
    balance += amount;
    count << " [<<] Transfered " << amount << " eu. to main account\n";
    count << "      Main account: " << balance << " eu. | Savings: " << savings << " eu.\n";
}

void Account::buyStocks(double pricePerStock, int quantity)
{
    if (quantity <= 0)
    {
        cout << " [!] You need more money!\n";
        return;
    }
    double total = pricePerStock * quantity;
    if (total > balance)
    {
        cout << " [!] Not enough balance! Needed: " << total << " eu. Balance" << balance << " eu.\n";
        return;
    }
    balance -= total;
    stocks += quantity;
    cout << " Bought " << quantity << "stocks per" << pricePerStock << " eu. = " << total << " eu.\n";
    cout << " Stocks: " << stocks << " Balance: " balance << " eu.\n"
}

void Account::sellStocks(double pricePerStock, int quantity)
{
    if (quantity <= 0)
    {
        cout << " [!] You need more money!\n";
        return;
    }
    double total = pricePerStock * quantity;
    if (total > balance)
    {
        cout << " [!] Not enough balance! Needed: " << total << " eu. stocks" << balance << " eu.\n";
        return;
    }
}

void Account::display() const
{
    cout << " Owner        : " << owner << "\n";
    cout << " Type account : Standart\n";
    cout << " Balance      : " << balance << "eu.\n";
}

double Account::getBalance() const { return balance; }
string Account::getOwner() const { return owner; }
