#include <bits/stdc++.h>
using namespace std;

// BankAccount Class (Encapsulation Example)
class BankAccount {
private:
    string ownerName;
    int accountNumber;
    double balance;
    int pin;
    vector<string> transactionHistory;

public:
    // Constructor
    BankAccount(string name, int accNumber, double initialBalance, int accPin) {
        ownerName = name;
        accountNumber = accNumber;
        balance = initialBalance;
        pin = accPin;
    }

    // Verify PIN
    bool verifyPin(int inputPin) {
        return inputPin == pin;
    }

    // Deposit Method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back("Deposited: " + to_string(amount));
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw Method
    void withdraw(double amount, int inputPin) {
        if (!verifyPin(inputPin)) {
            cout << "Invalid PIN!" << endl;
            return;
        }
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactionHistory.push_back("Withdrawn: " + to_string(amount));
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    // Getter Method for Balance
    double getBalance(int inputPin) {
        if (!verifyPin(inputPin)) {
            cout << "Invalid PIN!" << endl;
            return -1;
        }
        return balance;
    }

    // Display Account Information
    void displayAccountInfo(int inputPin) {
        if (!verifyPin(inputPin)) {
            cout << "Invalid PIN!" << endl;
            return;
        }
        cout << "\nAccount Information:" << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    // Display Transaction History
    void displayTransactionHistory(int inputPin) {
        if (!verifyPin(inputPin)) {
            cout << "Invalid PIN!" << endl;
            return;
        }
        cout << "\nTransaction History:" << endl;
        for (const string &transaction : transactionHistory) {
            cout << transaction << endl;
        }
    }
};

// Main Function
int main() {
    // Creating a BankAccount object
    BankAccount myAccount("John Doe", 123456, 500.0, 4321);

    int pin;
    cout << "Enter PIN to access account: ";
    cin >> pin;

    myAccount.displayAccountInfo(pin);

    // Performing transactions
    myAccount.deposit(200.0);
    myAccount.withdraw(100.0, pin);
    myAccount.withdraw(700.0, pin); // Should show an error

    // Checking balance
    cout << "Final Balance: " << myAccount.getBalance(pin) << endl;

    // Displaying transaction history
    myAccount.displayTransactionHistory(pin);

    return 0;
}
