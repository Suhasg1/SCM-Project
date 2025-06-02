#include <iostream>
using namespace std;

struct Account {
    int accNo;
    string name;
    double balance;
    string transactions[100];
    int txnCount = 0;
    double loanAmount = 0;
    string lockerPassword = "";
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

void applyLoan() {
    int accNo;
    double loan;
    cout << "Enter Account Number: ";
    cin >> accNo;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accNo == accNo) {
            cout << "Enter loan amount to apply: ";
            cin >> loan;
            accounts[i].loanAmount += loan;
            accounts[i].balance += loan;
            accounts[i].transactions[accounts[i].txnCount++] = "Loan credited Rs. " + to_string(loan);
            cout << "Loan approved and added to balance.\n";
            return;
        }
    }
    cout << "Account not found.\n";
}

// ======== Member 3: Safe Locker Feature ========
void accessLocker() {
    int accNo;
    string pass;
    cout << "Enter Account Number: ";
    cin >> accNo;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accNo == accNo) {
            int choice;
            cout << "1. Set Locker Password\n2. View Locker Password\nChoose: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Set a password for your locker: ";
                cin.ignore();
                getline(cin, accounts[i].lockerPassword);
                cout << "Locker password saved successfully.\n";
            } else if (choice == 2) {
                cout << "Enter your locker password to view: ";
                cin.ignore();
                getline(cin, pass);
                if (pass == accounts[i].lockerPassword) {
                    cout << "Locker Access Granted: Your password is \"" << pass << "\"\n";
                } else {
                    cout << "Incorrect locker password.\n";
                }
            } else {
                cout << "Invalid choice.\n";
            }
            return;
        }
    }
    cout << "Account not found.\n";
}
// ==============================================

void menu() {
    int choice;
    do {
        cout << "\n==== Bank Menu ====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Mini Statement\n";
        cout << "6. Apply for Loan\n";
        cout << "7. Access Safe Locker\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: showMiniStatement(); break;
            case 6: applyLoan(); break;
            case 7: accessLocker(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 8);
}

int main() {
    menu();
    return 0;
}