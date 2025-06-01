#include <iostream>
using namespace std;

struct Account {
    int accNo;
    string name;
    double balance;
};

const int MAX = 100;
Account accounts[MAX];
int accountCount = 0;

void createAccount() {
    Account acc;
    cout << "Enter Account Number: ";
    cin >> acc.accNo;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, acc.name);
    cout << "Enter Initial Deposit: ";
    cin >> acc.balance;
    accounts[accountCount++] = acc;
    cout << "Account created successfully!\n";
}

void deposit() {
    int accNo;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNo;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accNo == accNo) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            accounts[i].balance += amount;
            cout << "Deposit successful.\n";
            return;
        }
    }
    cout << "Account not found.\n";
}

void withdraw() {
    int accNo;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNo;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accNo == accNo) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                cout << "Withdraw successful.\n";
            } else {
                cout << "Insufficient balance.\n";
            }
            return;
        }
    }
    cout << "Account not found.\n";
}

void checkBalance() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accNo == accNo) {
            cout << "Current Balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found.\n";
}

void searchAccount() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accNo == accNo) {
            cout << "Account Number: " << accounts[i].accNo << endl;
            cout << "Name: " << accounts[i].name << endl;
            cout << "Balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Search Account\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                searchAccount();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}

