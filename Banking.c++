#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int pin;
    double balance;

public:
    // Constructor to initialize the account
    BankAccount(string name, int p, double initialBalance) {
        accountHolder = name;
        pin = p;
        balance = initialBalance;
    }

    // Function to authenticate using the PIN
    bool authenticate(int inputPin) {
        return inputPin == pin;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! Your new balance is: $" << balance << endl;
        } else {
            cout << "Invalid amount for deposit." << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! Your new balance is: $" << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance for withdrawal." << endl;
        } else {
            cout << "Invalid amount for withdrawal." << endl;
        }
    }

    // Function to check balance
    void checkBalance() {
        cout << "Your current balance is: $" << balance << endl;
    }
};

int main() {
    // Initialize account
    BankAccount account("John Doe", 1234, 1000.0);

    int pinInput;
    cout << "Welcome to the Banking System!" << endl;
    cout << "Please enter your PIN: ";
    cin >> pinInput;

    // Authentication
    if (account.authenticate(pinInput)) {
        int choice;
        do {
            cout << "\n--- Menu ---" << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Check Balance" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    double depositAmount;
                    cout << "Enter amount to deposit: $";
                    cin >> depositAmount;
                    account.deposit(depositAmount);
                    break;
                }
                case 2: {
                    double withdrawAmount;
                    cout << "Enter amount to withdraw: $";
                    cin >> withdrawAmount;
                    account.withdraw(withdrawAmount);
                    break;
                }
                case 3:
                    account.checkBalance();
                    break;
                case 4:
                    cout << "Thank you for using the Banking System. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);
    } else {
        cout << "Authentication failed! Incorrect PIN." << endl;
    }

    return 0;
}
