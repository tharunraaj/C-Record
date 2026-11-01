#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

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

class InsufficientFundsException : public BankException
{
public:
    InsufficientFundsException()
        : BankException("Error: Insufficient balance for withdrawal.")
    {
    }
};

class InvalidAmountException : public BankException
{
public:
    InvalidAmountException()
        : BankException("Error: Amount must be greater than zero.")
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
        balance -= amount;
    }
    void display()
    {
        cout << "Account Holder: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

void runTest(int testNo, string name, double initial, double dep,
             double w1, double w2)
{
    cout << "===== Test Case " << testNo << " =====" << endl;

    BankAccount account(name, initial);
    cout << "Initial Account Details:" << endl;
    account.display();

    try
    {
        cout << "\nDepositing Rs. " << dep << "..." << endl;
        account.deposit(dep);
        cout << "Withdrawing Rs. " << w1 << "..." << endl;
        account.withdraw(w1);
        cout << "Withdrawing Rs. " << w2 << "..." << endl;
        account.withdraw(w2);
    }
    catch (const InsufficientFundsException &e)
    {
        cout << e.what() << endl;
    }
    catch (const InvalidAmountException &e)
    {
        cout << e.what() << endl;
    }
    catch (const BankException &e)
    {
        cout << "Bank Exception: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cout << "General Exception: " << e.what() << endl;
    }

    cout << "\nFinal Account Details:" << endl;
    account.display();
    cout << endl;
}

int main()
{
    runTest(1, "Meena", 8000, 500, 3000, 6000);
    runTest(2, "Ravi", 1200, -50, 300, 100);

    cout << "Program completed successfully." << endl;
    return 0;
}