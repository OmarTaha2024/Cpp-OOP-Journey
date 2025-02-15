#include <iostream>
using namespace std;

// BankAccount Class (Encapsulation Example)
class BankAccount {
private:
    string ownerName;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int accNumber, double initialBalance) {
        ownerName = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    // Deposit Method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw Method
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    // Getter Method for Balance
    double getBalance() {
        return balance;
    }

    // Display Account Information
    void displayAccountInfo() {
        cout << "\nAccount Information:" << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Main Function
int main() {
    // Creating a BankAccount object
    BankAccount myAccount("John Doe", 123456, 500.0);

    // Displaying account info
    myAccount.displayAccountInfo();

    // Performing transactions
    myAccount.deposit(200.0);
    myAccount.withdraw(100.0);
    myAccount.withdraw(700.0); // Should show an error

    // Checking balance
    cout << "Final Balance: " << myAccount.getBalance() << endl;

    return 0;
}
