#include <iostream>
#include <stdlib.h>
using namespace std;
#define ll long long int

class Employee
{
private:
    string Name;
    double Salary;

public:
    ll ID;
    Employee()
    {
        Name = "Not Provided";
        ID = 0000;
        Salary = 00.00;
    }
    bool operator==(Employee Emp)
    {
        if (Salary == Emp.Salary)
            return true;
        else
            return false;
    }
    friend ostream &operator<<(ostream &output, const Employee &Emp)
    {
        output << "Name : " << Emp.Name << "\nID : " << Emp.ID << "\nSalary : " << Emp.Salary << "\n";
        return output;
    }
    friend istream &operator>>(istream &input, Employee &Emp)
    {
        cout << "Enter Name: ";
        getline(input, Emp.Name);
        cout << "Enter ID: ";
        input >> Emp.ID;
        cout << "Enter Salary: ";
        input >> Emp.Salary;
        return input;
    }
};

int main()
{
    system("cls");
    int total_Emp;
    cout << "Enter no. of Employees: ";
    cin >> total_Emp;
    Employee Emp[total_Emp];
    for (int i = 0; i < total_Emp; i++)
    {
        cin.ignore();
        cin >> Emp[i];
        cout << "\n";
    }
    cout << "Employees are arranged in group of similar salaries:\n";
    for (int i = 0; i < total_Emp; i++)
    {
        bool flag = false;
        for (int k = 0; k < i; k++)
        {
            if (Emp[k] == Emp[i])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            continue;
        }
        cout << Emp[i];
        for (int j = i + 1; j < total_Emp; j++)
        {
            if (Emp[i] == Emp[j])
            {
                cout << Emp[j];
            }
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}