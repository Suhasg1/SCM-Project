#include <iostream>
using namespace std;

struct Account {
    int accNo;
    string name;
    double balance;
    string transactions[100];
    int txnCount = 0;
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
    acc.transactions[acc.txnCount++] = "Account Created with Rs. " + to_string(acc.balance);
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
            accounts[i].transactions[accounts[i].txnCount++] = "Deposited Rs. " + to_string(amount);
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
                accounts[i].transactions[accounts[i].txnCount++] = "Withdrawn Rs. " + to_string(amount);
                cout << "Withdrawal successful.\n";
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
            cout << "Account Holder: " << accounts[i].name << endl;
            cout << "Current Balance: Rs." << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found.\n";
}

void showMiniStatement() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accNo == accNo) {
            cout << "\nMini Statement for " << accounts[i].name << ":\n";
            int start = accounts[i].txnCount > 5 ? accounts[i].txnCount - 5 : 0;
            for (int j = start; j < accounts[i].txnCount; j++) {
                cout << accounts[i].transactions[j] << endl;
            }
            return;
        }
    }
    cout << "Account not found.\n";
}

void menu() {
    int choice;
    do {
        cout << "\n==== Bank Menu ====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Mini Statement\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: showMiniStatement(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
