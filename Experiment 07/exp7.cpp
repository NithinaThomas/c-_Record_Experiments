#include <iostream>
#include <exception>
#include <string>
using namespace std;

// Base custom exception class
class BankException : public exception
{
protected:
    string message;

public:
    BankException(string msg)
    {
        message = msg;
    }

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

// Derived exception class
class InsufficientFundsException : public BankException
{
public:
    InsufficientFundsException()
        : BankException("Error: Insufficient balance for withdrawal.")
    {
    }
};

// Derived exception class
class InvalidAmountException : public BankException
{
public:
    InvalidAmountException()
        : BankException("Error: Amount must be greater than zero.")
    {
    }
};

// Derived exception class
class MinimumBalanceException : public BankException
{
public:
    MinimumBalanceException()
        : BankException("Error: Minimum balance of Rs. 1000 must be maintained.")
    {
    }
};

class BankAccount
{
private:
    string name;
    double balance;

public:
    BankAccount(string n, double b)
    {
        name = n;
        balance = b;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException();

        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException();

        if (amount > balance)
            throw InsufficientFundsException();

        if ((balance - amount) < 1000)
            throw MinimumBalanceException();

        balance -= amount;
    }

    void display()
    {
        cout << "Account Holder: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main()
{
    BankAccount account("Priya", 10000);

    cout << "Initial Account Details:" << endl;
    account.display();

    try
    {
        cout << "\nDepositing Rs. 3000..." << endl;
        account.deposit(3000);

        cout << "Withdrawing Rs. 2000..." << endl;
        account.withdraw(2000);

        cout << "Withdrawing Rs. 4000..." << endl;
        account.withdraw(4000);
    }
    catch (const InsufficientFundsException& e)
    {
        cout << e.what() << endl;
    }
    catch (const MinimumBalanceException& e)
    {
        cout << e.what() << endl;
    }
    catch (const InvalidAmountException& e)
    {
        cout << e.what() << endl;
    }

    cout << "\nFinal Account Details:" << endl;
    account.display();

    return 0;
}