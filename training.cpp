#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string owner;
    double balance;

public:
    BankAccount(string owner, double balance = 0) : owner(owner), balance(balance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "$" << amount << " deposited. New balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be positive" << endl;
        }
    }

    virtual void withdraw(double amount) {  // Virtual to allow overriding
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "$" << amount << " withdrawn. New balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount" << endl;
        }
    }

    void displayBalance() const {
        cout << owner << "'s account balance: $" << balance << endl;
    }
};


//step2

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string owner, double balance = 0, double interestRate = 0.02)
        : BankAccount(owner, balance), interestRate(interestRate) {}

    void applyInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "Interest of $" << interest << " applied. New balance: $" << balance << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string owner, double balance = 0, double overdraftLimit = 100)
        : BankAccount(owner, balance), overdraftLimit(overdraftLimit) {}

    void withdraw(double amount) override {  // Overriding withdraw for overdraft feature
        if (amount > 0 && amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "$" << amount << " withdrawn with overdraft. New balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or overdraft limit exceeded" << endl;
        }
    }
};


//step3

int main() {
    SavingsAccount savings("Alice", 190);
    CheckingAccount checking("Bob", 55);

    // Using deposit, withdraw, and displayBalance on both account types
    BankAccount* accounts[] = { &savings, &checking };

    for (BankAccount* account : accounts) {
        account->displayBalance();
        account->deposit(200);
        account->withdraw(100);
    }

    // Specific functionality for each account type
    savings.applyInterest();  // Only available in SavingsAccount
    checking.withdraw(700);   // Testing overdraft feature specific to CheckingAccount

    return 0;
}

