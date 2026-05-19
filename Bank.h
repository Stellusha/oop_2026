#define BANK_H

#include "SavingsAccount.h"
#include "BusinessAccount.h"

class Bank
{
public:
    SavingsAccount savings;
    BusinessAccount business;

    Bank();

    Account *findByOwner(const string &name);

    void displayAll() const;
}

#endif
