#include <iostream>
#include <cmath>
using namespace std;

class Account {
public:
    string customer_name;
    int account_number;
    string account_type;
    double balance;

    // create account
    void create_account(string customer_name, int account_number, string account_type, double balance) {
        this->customer_name = customer_name;
        this->account_number = account_number;
        this->account_type = account_type;
        this->balance = balance;
    }

    // show balance
    void showBalance() {
        cout << "Your Balance is " << balance << endl;
    }

    //  show account details
    void showDetails() {
        cout << "Customer Name: " << customer_name 
             << "\nAccount Number: " << account_number 
             << "\nAccount Type: " << account_type 
             << "\nBalance: " << balance << endl;
    }

    // deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << amount << " is credited successfully.\n";
        } else {
            cout << "Amount must be greater than 0.\n";
        }
    }
};

class CurAcct : virtual public Account {
public:
    // withdraw money
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance for withdrawal!" << endl;
        }
    }
};

class SavAcct : virtual public Account {
private:
    double interest_rate;
public:
    // set interest rate
    void setInterestRate(double rate) {
        interest_rate = rate;
    }

    // interest calculation
    void interestAmount(int years) {
        double interest = balance * pow(1 + interest_rate / 100, years) - balance;
        balance += interest;
        cout << "Interest Added: " << interest << endl;
    }

    //withdraw money
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Not enough balance for withdrawal" << endl;
        }
    }
};

int main() {
    SavAcct S1;
    CurAcct C1;

    int choice;
    string customer_name;
    int account_number;
    string account_type;
    double balance;
    double amount;
    double interest_rate;
    int years;

    while (true) {
        cout << "\nOPTIONS - \n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Current Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Check Balance\n";
        cout << "6. Show Account Details\n";
        cout << "7. Add Interest (Savings Account)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> customer_name;
                cout << "Enter account number: ";
                cin >> account_number;
                cout << "Enter initial balance: ";
                cin >> balance;
                S1.create_account(customer_name, account_number, "Savings", balance);
                cout << "Enter interest rate (in %): ";
                cin >> interest_rate;
                S1.setInterestRate(interest_rate);
                cout << "Savings account created \n";
                break;

            case 2:
                cout << "Enter customer name: ";
                cin >> customer_name;
                cout << "Enter account number: ";
                cin >> account_number;
                cout << "Enter initial balance: ";
                cin >> balance;
                C1.create_account(customer_name, account_number, "Current", balance);
                cout << "Current account created\n";
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> account_number;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                if (S1.account_number == account_number) {
                    S1.deposit(amount);
                } else if (C1.account_number == account_number) {
                    C1.deposit(amount);
                } else {
                    cout << "Account not found!\n";
                }
                break;

            case 4:
                cout << "Enter account number: ";
                cin >> account_number;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (S1.account_number == account_number) {
                    S1.withdraw(amount);
                } else if (C1.account_number == account_number) {
                    C1.withdraw(amount);
                } else {
                    cout << "no account exist \n";
                }
                break;

            case 5:
                cout << "Enter account number: ";
                cin >> account_number;
                if (S1.account_number == account_number) {
                    S1.showBalance();
                } else if (C1.account_number == account_number) {
                    C1.showBalance();
                } else {
                    cout << "no account\n";
                }
                break;

            case 6:
                cout << "Enter account number: ";
                cin >> account_number;
                if (S1.account_number == account_number) {
                    S1.showDetails();
                } else if (C1.account_number == account_number) {
                    C1.showDetails();
                } else {
                    cout << "Account not found!\n";
                }
                break;

            case 7:
                cout << "Enter account number: ";
                cin >> account_number;
                if (S1.account_number == account_number) {
                    cout << "Enter number of years: ";
                    cin >> years;
                    S1.interestAmount(years);
                } else {
                    cout << "This option is available only for savings accounts\n";
                }
                break;

            case 8:
                cout << "Exit\n";
                return 0;

            default:
                cout << "Invalid choice\n";
                break;
        }
    }
    return 0;
}
