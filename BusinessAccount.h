#ifndef BUSINESS_ACCOUNT_H
#define BUSINESS_ACCOUNT_H

#include "Account.h"

class BusinessAccount : public Account
{
private:
    double fee;

public:
    BusinessAccount(string owner, double balance, double fee, string pin);

    void withdraw(double amount) override;
    void display() const override;
};

#endif
