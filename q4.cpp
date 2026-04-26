#include <iostream>
#include <exception>
using namespace std;

class InsufficientFundsException : public exception {
public:
    const char* what() const throw() {
        return "Error: Insufficient funds to complete withdrawal!";
    }
};

class BankAccount {
    double balance;
public:
    BankAccount(double b) : balance(b) {}
    
    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFundsException();
        }
        balance -= amount;
        cout << "Withdrawal successful! New Balance: $" << balance << endl;
    }
    
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account(500);
    double amount;
    
    cout << "Current Balance: $" << account.getBalance() << endl;
    cout << "Enter withdrawal amount: $";
    cin >> amount;
    
    try {
        account.withdraw(amount);
    } catch (const exception& e) {
        cout << e.what() << endl;
        cout << "Current Balance: $" << account.getBalance() << endl;
    }
    
    return 0;
}
