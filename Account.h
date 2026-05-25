#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account
{
protected:
    string owner;
    double balance;
    double savings;
    double stocks;
    string pin;

public:
    Account(string owner, double balance, string pin);

    bool checkPin(const string &inputPin) const;

    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void display() const;

    void buyStocks(double pricePerStock, int quantity);
    void sellStocks(double pricePerStocks, int quantity);

    Bool transferTo(Account &target, double amount);

    double getBalance() const;
    double getSavings() const;
    double getStocks() const;
    string getOwner() const;
};

#endif