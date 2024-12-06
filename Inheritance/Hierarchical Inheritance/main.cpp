/**                         Documentation section
_________________________________________________________________________________________________________________
-----------------------------------------------------------------------------------------------------------------
@name :  Hierarchical Inheritance
@author : Omar Mohamed El Sayed Taha
@Link : ...........................



__________________________________________________________________________________________________________________
------------------------------------------------------------------------------------------------------------------
**/
#include <bits/stdc++.h>
#define Taha ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define el "\n"
#define sp " "



using namespace std;


/**
Hierarchical Inheritance :
 multiple derived classes inherit from a single base class.
**/
using namespace std;

// Base class
class Account {
protected:
    string accountHolder;
    double balance;

public:
    Account(string holder, double bal) : accountHolder(holder), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << ". New Balance: " << balance << endl;
    }

    void displayAccountInfo() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived class for savings account
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string holder, double bal, double rate)
        : Account(holder, bal), interestRate(rate) {}

    void calculateInterest() {
        double interest = balance * (interestRate / 100);
        cout << "Interest Amount: " << interest << endl;
    }
};

// Derived class for checking account
class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(string holder, double bal, double limit)
        : Account(holder, bal), overdraftLimit(limit) {}

    void withdraw(double amount) {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << "Withdrawn " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Withdrawal denied. Exceeds overdraft limit." << endl;
        }
    }
};

int main() {
    SavingsAccount savings("Alice", 5000.0, 3.5);
    CheckingAccount checking("Bob", 2000.0, 500.0);

    cout << "Savings Account:" << endl;
    savings.displayAccountInfo();
    savings.calculateInterest();
    savings.deposit(1000.0);

    cout << "\nChecking Account:" << endl;
    checking.displayAccountInfo();
    checking.withdraw(2500.0);
    checking.withdraw(3000.0);

    return 0;
}
