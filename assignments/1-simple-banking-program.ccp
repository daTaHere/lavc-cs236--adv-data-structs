/*
    Lab Assignment -Simple Banking Program (Java Primer)
    This is a basic Banking Program in C++ inplace of java
    
    Features:
     - BankAccount Class 5 members 
        - two private fields 
         -three public methods
     - User input processing ( No input validation, No error handling)
     - Output formating set percison to two dec places 

     Created by :
     - Adam Huynh
     - CS 236 Fall Semester LAVC
     - 09/03/2026
     github repo:
     - https://github.com/daTaHere/lavc-cs236--adv-data-structs
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
    private:
        string name;
        double balance;

    public:
        // constructor
        BankAccount(const string& n, double bal) : name(n), balance(bal) {}

        // setters
        void deposit(double amount);
        void withdraw(double amount);

        // getters
        void displayBalance() const;
 };


// function definitions 
void BankAccount::deposit(double amount) {
    // <your code here>
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    // <your code here>
    if (amount <= balance)
        balance -= amount;
}

void BankAccount::displayBalance() const {
    // <your code here>
    cout << fixed << std::setprecision(2);  // formate output to 2 dec ie 500 --> 500.00
    cout << "\nAccount Summary: \n";
    cout << "Name: " << name << endl;
    cout << "Final Balance: " << balance << endl;
}

int main() {
    cout << "Enter your name:\n";
    string name;
    getline(cin, name);

    cout << "Enter starting balance:\n";
    double balance;
    cin >> balance;

    BankAccount account(name, balance);

    cout << "Enter deposit amount:\n";
    double depositAmount;
    cin >> depositAmount;

    // <your code here> call deposit method
    account.deposit(depositAmount);

    cout << "Enter withdrawal amount:\n";
    double withdrawAmount;
    cin >> withdrawAmount;

    // <your code here>call widthdraw method
    account.withdraw(withdrawAmount);

    account.displayBalance();

    return 0;
}
