#include "Bank.h"
#include <iostream>
using namespace std;

Bank::Bank()
    : savings("Maria Petrova", 2000.0, 0.05, "1234"),
      business("Company Ltd", 5000.0, 10.0, "5678")
{
}

Account *Bank::findByOwner(const string &name)
{
    if (savings.getOwner() == name)
        return &savings;
    if (business.getOwner() == name)
        return &business;
    return nullptr;
}

void Bank::displayAll() const
{
    cout << "\n--- Savings account ---\n";
    savings.display();
    cout << "\n--- Business account ---\n";
    business.display();
}