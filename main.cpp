#include <iostream>
#include <string>
#include <limits>
#include "Account.h"
#include "SavingsAccount.h"
#include "BusinessAccount.h"
using namespace std;

void clearScreen()
{
    cout << "\n\n";
}

void separator()
{
    cout << "----------------------------------------\n";
}

void header(const string &title)
{
    cout << "\n========================================\n";
    cout << "   " << title << "\n";
    cout << "========================================\n";
}

double readAmount()
{
    double amount;
    while (true)
    {
        cout << " Enter  Sum: ";
        cin >> amount;
        if (cin.fail() || amount <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  [!] Enter positive sum.\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return amount;
        }
    }
}

bool login(Account &acc)
{
    const int MAX_ATTEMPTS = 3;

    header("Enter the system");

    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++)
    {
        string inputName, inputPin;

        cout << "\n  Username: ";
        getline(cin, inputName);

        cout << "  PIN (4 numbers)    : ";
        getline(cin, inputPin);

        // Проверка на дължина на PIN
        if (inputPin.length() != 4)
        {
            cout << "  [!] PIN needs to be 4 numbers. (" << attempt << "/" << MAX_ATTEMPTS << " tries)\n";
            continue;
        }

        // Проверка дали PIN съдържа само цифри
        bool onlyDigits = true;
        for (char c : inputPin)
        {
            if (c < '0' || c > '9')
            {
                onlyDigits = false;
                break;
            }
        }
        if (!onlyDigits)
        {
            cout << "  [!] PIN should be only numbers. (" << attempt << "/" << MAX_ATTEMPTS << " tries)\n";
            continue;
        }

        // Проверка: потребителско име И PIN
        if (inputName == acc.getOwner() && acc.checkPin(inputPin))
        {
            cout << "\n  [OK] Welcome, " << acc.getOwner() << "!\n";
            return true;
        }
        else
        {
            cout << "  [X] Wrong username or PIN. (" << attempt << "/" << MAX_ATTEMPTS << " tries)\n";
        }
    }

    cout << "\n  [!!] Too many tries. Access denied.\n";
    return false;
}

void savingsMenu(SavingsAccount &acc)
{
    int choice;
    do
    {
        header("Savings account — " + acc.getOwner());
        cout << "  1. See balance\n";
        cout << "  2. Add money\n";
        cout << "  3. Whitdraw money\n";
        cout << "  4. Add interest\n";
        cout << "  0. Exit\n";
        separator();
        cout << "  Choose: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n";
        switch (choice)
        {
        case 1:
            separator();
            acc.display();
            separator();
            break;
        case 2:
            separator();
            acc.deposit(readAmount());
            separator();
            break;
        case 3:
            separator();
            acc.withdraw(readAmount());
            separator();
            break;
        case 4:
            separator();
            acc.applyInterest();
            separator();
            break;
        case 0:
            cout << "  Exiting savings account...\n";
            break;
        default:
            cout << "  [!] Invalid choice.\n";
        }
    } while (choice != 0);
}

void businessMenu(BusinessAccount &acc)
{
    int choice;
    do
    {
        header("Business account — " + acc.getOwner());
        cout << "  1. See balance\n";
        cout << "  2. Add money\n";
        cout << "  3. Whitdraw money (+ tax)\n";
        cout << "  0. Exit\n";
        separator();
        cout << "  Choose: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n";
        switch (choice)
        {
        case 1:
            separator();
            acc.display();
            separator();
            break;
        case 2:
            separator();
            acc.deposit(readAmount());
            separator();
            break;
        case 3:
            separator();
            acc.withdraw(readAmount());
            separator();
            break;
        case 0:
            cout << "  Exiting business account...\n";
            break;
        default:
            cout << "  [!] Invalid choice.\n";
        }
    } while (choice != 0);
}

int main()
{

    // Създаване на акаунтите с PIN
    SavingsAccount savings("Doktor Ivanov", 2000.0, 0.05, "1234");
    BusinessAccount business("Firm EOOD", 5000.0, 10.0, "5678");

    int choice;
    do
    {
        header("Bank system MENU");
        cout << "  1. Savings account\n";
        cout << "  2. Business account\n";
        cout << "  0. Exit\n";
        separator();
        cout << "  Choose ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n";
        switch (choice)
        {

        case 1:
            if (login(savings))
                savingsMenu(savings);
            break;

        case 2:
            if (login(business))
                businessMenu(business);
            break;

        case 0:
            header("GOODBYE!");
            break;

        default:
            cout << "  [!] Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}