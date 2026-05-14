#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account
{
protected:
    string owner;
    double balance;
    string pin;

public:
    Account(string owner, double balance, string pin);

    bool checkPin(const string &inputPin) const;

    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void display() const;

    double getBalance() const;
    string getOwner() const;
};

#endif