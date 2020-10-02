#include <iostream>
#include <string.h>
#include <list>
#include <conio.h>
using namespace std;
#define ul unsigned long long int
#define ADMIN_PIN 1614

class Account
{
private:
    ul acc_no;
    string name;
    ul balance;
    char type;
    char pin[4];
    void pin_security()
    {
        char a;
        for (int i = 0;;)
        {
            a = getch();
            if (a >= '0' && a <= '9')
            {
                pin[i] = a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1)
            {
                cout << "\b \b";
                --i;
            }
            if (i == 4)
            {
                pin[i] = '\0';
                cout << "\n";
                break;
            }
        }
    }

public:
    void create_account();
    int credit(int);
    void deposit(int);
    void show_account() const;
    void modify_account();
    bool Access_check(int);
    int get_acc_no() const;
    int get_balance() const;
    char get_acc_type() const;
};

void Account::create_account()
{
    char a;
    cout << "\n\t\t\t\tEnter the Account No. : ";
    cin >> acc_no;
    cout << "\n\t\t\t\tEnter the Account Pin : ";
    pin_security();
    cout << "\n\t\t\t\tEnter the Name of the Account holder : ";
    cin.ignore();
    getline(cin, name);
    cout << "\n\t\t\t\tEnter Type of the Account(C/S) : ";
    while (1)
    {
        a = getch();
        if ((a == 'c' || a == 'C') || (a == 's' || a == 'S'))
        {
            type = a;
            type = toupper(type);
            cout << type << "\n";
            break;
        }
    }
    cout << "\n\t\t\t\tEnter The Initial Balance : ";
    cin >> balance;
    cout << "\n\n\t\t\t\tAccount Created...";
}

void Account::show_account() const
{
    cout << "\n\t\t\tAccount No. : " << acc_no;
    cout << "\n\t\t\tAccount Holder Name : " << name;
    cout << "\n\t\t\tType of Account : ";
    if (type == 'c' || type == 'C')
    {
        cout << "Current";
    }
    else
    {
        cout << "Savings";
    }
    cout << "\n\t\t\tBalance Amount : " << balance;
}

void Account::modify_account()
{
    char a;
    cout << "\n\t\t\tAccount No. : " << acc_no << "\n";
    cout << "\n\t\t\tModify Account Pin : ";
    pin_security();
    cout << "\n\t\t\tModify Account Holder Name : ";
    cin.ignore();
    getline(cin, name);
    cout << "\n\t\t\tModify Type of Account(C/S) : ";
    while (1)
    {
        a = getch();
        if ((a == 'c' || a == 'C') || (a == 's' || a == 'S'))
        {
            type = a;
            type = toupper(type);
            cout << type;
            break;
        }
    }
}

void Account::deposit(int deposit_amount)
{
    balance += deposit_amount;
}

int Account::credit(int credit_amount)
{
    if (credit_amount <= balance)
    {
        balance -= credit_amount;
        return 0;
    }
    return 1;
}

bool Account::Access_check(int pass)
{
    if (pass == atoi(pin))
    {
        return true;
    }
    return false;
}

int Account::get_acc_no() const
{
    return acc_no;
}

int Account::get_balance() const
{
    return balance;
}

char Account::get_acc_type() const
{
    return type;
}

class manager
{
private:
    list<Account> Customers;
    list<Account>::iterator it;

public:
    void Add_account()
    {
        Account newAccount;
        newAccount.create_account();
        Customers.push_back(newAccount);
    }

    void Transaction(int type)
    {
        ul acc;
        ul amount;
        char pin[4];
        bool flag = true;
        cout << "\n\t\t\tEnter Account no. : ";
        cin >> acc;
        for (it = Customers.begin(); it != Customers.end(); it++)
        {
            if (it->get_acc_no() == acc)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "\n\t\t\tAccount Not Found";
            return;
        }
        else
        {
            cout << "\n\t\t\tEnter PIN : ";
            char a;
            for (int i = 0;;)
            {
                a = getch();
                if (a >= '0' && a <= '9')
                {
                    pin[i] = a;
                    ++i;
                    cout << "*";
                }
                if (a == '\b' && i >= 1)
                {
                    cout << "\b \b";
                    --i;
                }
                if (i == 4)
                {
                    pin[i] = '\0';
                    cout << "\n";
                    break;
                }
            }
            if (it->Access_check(atoi(pin)))
            {
                if (type == 1)
                {
                    cout << "\n\t\t\tEnter Amount to be deposited : ";
                    cin >> amount;
                    if (amount < 0)
                    {
                        cout << "\n\t\t\tInvalid Amount";
                    }
                    else
                    {
                        it->deposit(amount);
                    }
                }
                else
                {
                    cout << "\n\t\t\tEnter Amount to be credited : ";
                    cin >> amount;
                    if (amount < 0)
                    {
                        cout << "\n\t\t\tInvalid Amount";
                    }
                    else
                    {
                        if (amount > it->get_balance())
                        {
                            cout << "\n\t\t\tYou don't have enough credits";
                        }
                        else
                        {
                            it->credit(amount);
                        }
                    }
                }
                cout << "\n\t\t\tYour Balance is : " << it->get_balance();
            }
            else
            {
                cout << "\n\t\t\tWrong PIN";
                return;
            }
        }
    }

    void display_account()
    {
        ul acc;
        char pin[4];
        bool flag = true;
        cout << "\n\t\t\tEnter Account no. : ";
        cin >> acc;
        for (it = Customers.begin(); it != Customers.end(); it++)
        {
            if (it->get_acc_no() == acc)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "\n\t\t\tAccount Not Found";
            return;
        }
        else
        {
            cout << "\n\t\t\tEnter PIN : ";
            char a;
            for (int i = 0;;)
            {
                a = getch();
                if (a >= '0' && a <= '9')
                {
                    pin[i] = a;
                    ++i;
                    cout << "*";
                }
                if (a == '\b' && i >= 1)
                {
                    cout << "\b \b";
                    --i;
                }
                if (i == 4)
                {
                    pin[i] = '\0';
                    cout << "\n";
                    break;
                }
            }
            if (it->Access_check(atoi(pin)))
            {
                it->show_account();
            }
            else
            {
                cout << "\n\t\t\tWrong PIN";
                return;
            }
        }
    }

    void display_all()
    {
        char pin[4];
        bool flag = true;
        cout << "\n\t\t\tEnter Admin PIN to view : ";
        char a;
        for (int i = 0;;)
        {
            a = getch();
            if (a >= '0' && a <= '9')
            {
                pin[i] = a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1)
            {
                cout << "\b \b";
                --i;
            }
            if (i == 4)
            {
                pin[i] = '\0';
                cout << "\n";
                break;
            }
        }
        if (atoi(pin) == ADMIN_PIN)
        {
            for (it = Customers.begin(); it != Customers.end(); it++)
            {
                flag = false;
                it->show_account();
                cout << "\n";
            }
            if (flag)
            {
                cout << "\n\t\t\tNo Customers Yet!";
            }
        }
        else
        {
            cout << "\n\t\t\tWrong Admin PIN";
        }
    }

    void modify()
    {
        ul acc;
        char pin[4];
        char admin_pin[4];
        char choice;
        bool flag = true;
        cout << "\n\t\t\tEnter Admin PIN to continue: ";
        char a;
        for (int i = 0;;)
        {
            a = getch();
            if (a >= '0' && a <= '9')
            {
                admin_pin[i] = a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1)
            {
                cout << "\b \b";
                --i;
            }
            if (i == 4)
            {
                admin_pin[i] = '\0';
                cout << "\n";
                break;
            }
        }
        if (atoi(admin_pin) == ADMIN_PIN)
        {
            cout << "\n\t\t\tEnter Account no. : ";
            cin >> acc;
            for (it = Customers.begin(); it != Customers.end(); it++)
            {
                if (it->get_acc_no() == acc)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "\n\t\t\tAccount Not Found";
                return;
            }
            else
            {
                cout << "\n\t\t\tEnter PIN : ";
                char a;
                for (int i = 0;;)
                {
                    a = getch();
                    if (a >= '0' && a <= '9')
                    {
                        pin[i] = a;
                        ++i;
                        cout << "*";
                    }
                    if (a == '\b' && i >= 1)
                    {
                        cout << "\b \b";
                        --i;
                    }
                    if (i == 4)
                    {
                        pin[i] = '\0';
                        cout << "\n";
                        break;
                    }
                }
                if (it->Access_check(atoi(pin)))
                {
                    cout << "\n\t\t\tAre you sure you want to modify (Y/N): ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 'y':
                    case 'Y':
                        it->modify_account();
                        break;
                    case 'n':
                    case 'N':
                        cout << "\n\t\t\tAccount not modified";
                        break;

                    default:
                        cout << "\n\t\t\tInvalid Choice";
                        break;
                    }
                }
                else
                {
                    cout << "\n\t\t\tWrong PIN";
                    return;
                }
            }
        }
        else
        {
            cout << "\n\t\t\tWrong Admin PIN";
        }
    }

    void remove_account()
    {
        ul acc;
        char pin[4];
        char admin_pin[4];
        char choice;
        bool flag = true;
        cout << "\n\t\t\tEnter Admin PIN to continue: ";
        char a;
        for (int i = 0;;)
        {
            a = getch();
            if (a >= '0' && a <= '9')
            {
                admin_pin[i] = a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1)
            {
                cout << "\b \b";
                --i;
            }
            if (i == 4)
            {
                admin_pin[i] = '\0';
                cout << "\n";
                break;
            }
        }
        if (atoi(admin_pin) == ADMIN_PIN)
        {
            cout << "\n\t\t\tEnter Account no. : ";
            cin >> acc;
            for (it = Customers.begin(); it != Customers.end(); it++)
            {
                if (it->get_acc_no() == acc)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "\n\t\t\tAccount Not Found";
                return;
            }
            else
            {
                cout << "\n\t\t\tEnter PIN : ";
                char a;
                for (int i = 0;;)
                {
                    a = getch();
                    if (a >= '0' && a <= '9')
                    {
                        pin[i] = a;
                        ++i;
                        cout << "*";
                    }
                    if (a == '\b' && i >= 1)
                    {
                        cout << "\b \b";
                        --i;
                    }
                    if (i == 4)
                    {
                        pin[i] = '\0';
                        cout << "\n";
                        break;
                    }
                }
                if (it->Access_check(atoi(pin)))
                {
                    cout << "\n\t\t\tAre you sure you want to delete (Y/N): ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 'y':
                    case 'Y':
                        cout << "\n\t\t\tWe are working on your request for account deletion";
                        cout << "\n\t\t\tPlease Contact to your home branch if you want to cancel request";
                        if (it->get_balance() > 0)
                        {
                            cout << "\n\t\t\tOr to collect your remaining " << it->get_balance() << " balance";
                        }
                        Customers.erase(it);
                        break;
                    case 'n':
                    case 'N':
                        cout << "\n\t\t\tAccount not deleted";
                        break;

                    default:
                        cout << "\n\t\t\tInvalid Choice";
                        break;
                    }
                }
                else
                {
                    cout << "\n\t\t\tWrong PIN";
                    return;
                }
            }
        }
        else
        {
            cout << "\n\t\t\tWrong Admin PIN";
        }
    }
};

int main()
{
    char choice;
    manager admin;
    do
    {
        system("cls");
        cout << "\n\n\t\t\t\t======================\n";
        cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
        cout << "\n\t\t\t\t======================\n";

        cout << "\t\t\t\t    ::MAIN MENU::\n";
        cout << "\n\t\t\t\t1. NEW ACCOUNT";
        cout << "\n\t\t\t\t2. DEPOSIT AMOUNT";
        cout << "\n\t\t\t\t3. WITHDRAW AMOUNT";
        cout << "\n\t\t\t\t4. BALANCE ENQUIRY";
        cout << "\n\t\t\t\t5. ALL CUSTOMERS(ADMIN ONLY)";
        cout << "\n\t\t\t\t6. CLOSE AN ACCOUNT(ADMIN ONLY)";
        cout << "\n\t\t\t\t7. MODIFY AN ACCOUNT(ADMIN ONLY)";
        cout << "\n\t\t\t\t8. EXIT";
        cout << "\n\n\t\t\t\tSelect Your Option (1-8): ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            system("cls");
            cout << "\n\n\t\t\t\t======================\n";
            cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
            cout << "\n\t\t\t\t======================\n";
            admin.Add_account();
            cout << "\n\t\t\t\t";
            system("pause");
            break;
        case '2':
            admin.Transaction(1);
            cout << "\n\t\t\t";
            system("pause");
            break;
        case '3':
            admin.Transaction(2);
            cout << "\n\t\t\t";
            system("pause");
            break;
        case '4':
            admin.display_account();
            cout << "\n\t\t\t";
            system("pause");
            break;
        case '5':
            admin.display_all();
            cout << "\n\t\t\t";
            system("pause");
            break;
        case '6':
            admin.remove_account();
            cout << "\n\t\t\t";
            system("pause");
            break;
        case '7':
            admin.modify();
            cout << "\n\t\t\t";
            system("pause");
            break;
        case '8':
            system("cls");
            cout << "\n\t\t\tThanks for your Time";
            cout << "\n\t\t\tProgram Design By:- Ishan Shukla";
            cout << "\n\t\t\t";
            system("pause");
            break;
        default:
            cout << "\a";
        }
        cin.ignore();
    } while (choice != '8');
    return 0;
}