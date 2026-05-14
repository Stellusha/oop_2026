#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "BusinessAccount.h"
using namespace std;

void separatir(string title)
{
    cout << "\n===================================\n";
    cout << "   " << title << "\n";
    cout << "\n===================================\n";
}

int main()
{
    separator("STANDART ACCOUNT");

    cout << "\n-- Information about account --\n";
    acc.display();

    cout << "\n-- Adding 500 eu. --\n";
    acc.deposit(500.0);

    cout << "\n-- Withdraw 200 eu. --\n";
    acc.withdraw(200.0);

    cout << "\n-- Try for withdraw 5000 eu. --\n";
    acc.withdraw(5000.0);

    cout << "\n-- Final balance --\n";
    acc.display();

    separator("SAVINGS ACCOUNT");

    cout << "\n-- Information about account --\n";
    savings.display();

    cout << "\n-- Adding 1000 eu. --\n";
    savings.deposit(1000.0);

    cout << "\n-- Lihva (5%) --\n";
    savings.applyINterest();

    cout << "\n-- Try for withdraw 300 eu. --\n";
    savings.withdraw(300.0);

    cout << "\n-- Final balance --\n";
    savings.display();

    separator("BUSINESS ACCOUNT");

    cout << "\n-- Information about account --\n";
    biz.display();

    cout << "\n-- Adding 2000 eu. --\n";
    biz.deposit(2000.0);

    cout << "\n-- Withdraw 1000 eu. (+ 10 eu. tax) --\n";
    biz.withdraw(1000.0);

    cout << "\n-- Trying to withdraw more money than what you have. --\n";
    biz.withdraw(9000.0);

    cout << "\n-- Final balance --\n";
    biz.display();

    separator("END OF PROGRAM");

    return 0;
}
