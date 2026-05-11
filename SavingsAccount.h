#ifndef SAVINGS_ACCOUnt_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(string owner, double balance, double interestRate);

    void applyInterest();
    void withdraw(double amount) override;
    void display() count override;
}

#endif