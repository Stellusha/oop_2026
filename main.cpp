#include <iostream>
#include <string>
#include <limits>
#include "Bank.h"
using namespace std;

// ─────────────────────────────────────────────
//  Helper functions
// ─────────────────────────────────────────────

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
        cout << "  Amount (eu.): ";
        cin >> amount;
        if (cin.fail() || amount <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  [!] Please enter a valid positive amount.\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return amount;
        }
    }
}

int readInt()
{
    int n;
    while (true)
    {
        cin >> n;
        if (cin.fail() || n <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  [!] Please enter a valid positive number.\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return n;
        }
    }
}

// ─────────────────────────────────────────────
//  Login — asks for username + 4-digit PIN
// ─────────────────────────────────────────────
bool login(Account &acc)
{
    const int MAX_ATTEMPTS = 3;
    header("LOGIN");

    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++)
    {
        string inputName, inputPin;

        cout << "\n  Username: \n";
        getline(cin, inputName);
        cout << "  PIN (4 digits): \n";
        getline(cin, inputPin);

        if (inputPin.length() != 4)
        {
            cout << "  [!] PIN must be exactly 4 digits. (" << attempt << "/" << MAX_ATTEMPTS << ")\n";
            continue;
        }

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
            cout << "  [!] PIN must contain only digits. (" << attempt << "/" << MAX_ATTEMPTS << ")\n";
            continue;
        }

        if (inputName == acc.getOwner() && acc.checkPin(inputPin))
        {
            cout << "\n  [OK] Welcome, " << acc.getOwner() << "!\n";
            return true;
        }
        cout << "  [X] Wrong username or PIN. (" << attempt << "/" << MAX_ATTEMPTS << ")\n";
    }

    cout << "\n  [!!] Access blocked after 3 failed attempts.\n";
    return false;
}

// ─────────────────────────────────────────────
//  Stocks menu
// ─────────────────────────────────────────────
void stocksMenu(Account &acc)
{
    int choice;
    do
    {
        header("STOCKS — " + acc.getOwner());
        cout << "  Portfolio     : " << acc.getStocks() << " pcs.\n";
        cout << "  Main account  : " << acc.getBalance() << " eu.\n";
        separator();
        cout << "  1. Buy stocks\n";
        cout << "  2. Sell stocks\n";
        cout << "  0. Back\n";
        separator();
        cout << "  Choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n";
        if (choice == 1)
        {
            separator();
            cout << "  Price per stock (eu.): ";
            double price = readAmount();
            cout << "  Quantity: ";
            int qty = readInt();
            acc.buyStocks(price, qty);
            separator();
        }
        else if (choice == 2)
        {
            separator();
            cout << "  Price per stock (eu.): ";
            double price = readAmount();
            cout << "  Quantity: ";
            int qty = readInt();
            acc.sellStocks(price, qty);
            separator();
        }
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Transfer menu
// ─────────────────────────────────────────────
void transferMenu(Account &acc, Bank &bank)
{
    int choice;
    do
    {
        header("TRANSFER — " + acc.getOwner());
        cout << "  Main account  : " << acc.getBalance() << " eu.\n";
        cout << "  Savings       : " << acc.getSavings() << " eu.\n";
        separator();
        cout << "  1. Main account  ->  Savings (internal)\n";
        cout << "  2. Savings       ->  Main account (internal)\n";
        cout << "  3. Transfer to another account\n";
        cout << "  0. Back\n";
        separator();
        cout << "  Choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n";
        if (choice == 1)
        {
            separator();
            acc.transferToSavings(readAmount());
            separator();
        }
        else if (choice == 2)
        {
            separator();
            acc.transferToMain(readAmount());
            separator();
        }
        else if (choice == 3)
        {
            separator();
            cout << "  Enter recipient name: ";
            string targetName;
            getline(cin, targetName);

            if (targetName == acc.getOwner())
            {
                cout << "  [!] Cannot transfer to yourself. Use internal transfer instead.\n";
            }
            else
            {
                Account *target = bank.findByOwner(targetName);
                if (target == nullptr)
                {
                    cout << "  [!] Account with that name was not found.\n";
                }
                else
                {
                    acc.transferTo(*target, readAmount());
                }
            }
            separator();
        }
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Savings account menu
// ─────────────────────────────────────────────
void savingsMenu(SavingsAccount &acc, Bank &bank)
{
    int choice;
    do
    {
        header("SAVINGS ACCOUNT — " + acc.getOwner());
        cout << "  1. View balance\n";
        cout << "  2. Deposit\n";
        cout << "  3. Withdraw\n";
        cout << "  4. Apply interest\n";
        cout << "  5. Transfer\n";
        cout << "  6. Stocks\n";
        cout << "  0. Logout\n";
        separator();
        cout << "  Choice: ";
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
        case 5:
            transferMenu(acc, bank);
            break;
        case 6:
            stocksMenu(acc);
            break;
        case 0:
            cout << "  Logging out...\n";
            break;
        default:
            cout << "  [!] Invalid choice.\n";
        }
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Business account menu
// ─────────────────────────────────────────────
void businessMenu(BusinessAccount &acc, Bank &bank)
{
    int choice;
    do
    {
        header("BUSINESS ACCOUNT — " + acc.getOwner());
        cout << "  1. View balance\n";
        cout << "  2. Deposit\n";
        cout << "  3. Withdraw (+ fee)\n";
        cout << "  4. Transfer\n";
        cout << "  5. Stocks\n";
        cout << "  0. Logout\n";
        separator();
        cout << "  Choice: ";
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
            transferMenu(acc, bank);
            break;
        case 5:
            stocksMenu(acc);
            break;
        case 0:
            cout << "  Logging out...\n";
            break;
        default:
            cout << "  [!] Invalid choice.\n";
        }
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  MAIN MENU
// ─────────────────────────────────────────────
int main()
{
    Bank bank;

    int choice;
    do
    {
        header("BANKING SYSTEM — MAIN MENU");
        cout << "  1. Savings account   (" << bank.savings.getOwner() << ")\n";
        cout << "  2. Business account  (" << bank.business.getOwner() << ")\n";
        cout << "  0. Exit\n";
        separator();
        cout << "  Choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n";
        switch (choice)
        {
        case 1:
            if (login(bank.savings))
                savingsMenu(bank.savings, bank);
            break;
        case 2:
            if (login(bank.business))
                businessMenu(bank.business, bank);
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