#include "BAnk.h"
#include <iostream>
using namespace std;

Bank::Bank()
    : savings("Maria Petrova", 2000.0, 0.05, "1234"),
      business("Firm EOOD", 500.0, 10.0, "5678")
{
}

Account *Bank::findByOwner(const string &name)
{
    if (saving.getOwner() == name)
        return &savings;
    if (business.getOwner() == name)
        return &business;
    return nullptr;
}

void Bank::displayAll() const
{
    cout << "\n--- Savings Account ---\n";
    savings.display();
    cout << "\n--- Business Account --\n";
    business.display();
}
