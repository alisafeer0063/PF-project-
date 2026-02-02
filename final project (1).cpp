#include <iostream>
#include <string>

using namespace std;

const int MAX_ENTRIES = 100;

struct FinanceEntry {
    string date;
    string category;
    double amount;
    bool isIncome; // true for income, false for expense
};

FinanceEntry entries[MAX_ENTRIES];
int entryCount = 0;
double savingsGoal = 0;

double calculateBalance() {
    double balance = 0;
    for (int i = 0; i < entryCount; i++) {
        balance += (entries[i].isIncome ? entries[i].amount : -entries[i].amount);
    }
    return balance;
}

void addEntry(bool isIncome) {
    if (entryCount >= MAX_ENTRIES) {
        cout << "Entry limit reached!" << endl;
        return;
    }
    
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> entries[entryCount].date;
    cout << "Enter category: ";
    cin >> entries[entryCount].category;
    cout << "Enter amount: ";
    cin >> entries[entryCount].amount;
    entries[entryCount].isIncome = isIncome;
    entryCount++;
    
    cout << (isIncome ? "Income" : "Expense") << " added successfully!\n";
}

void setSavingsGoal() {
    cout << "Enter savings goal: ";
    cin >> savingsGoal;
    cout << "Savings goal set successfully!\n";
}

void displaySummary() {
    cout << "\n--- Financial Summary ---\n";
    double totalIncome = 0, totalExpenses = 0;
    
    for (int i = 0; i < entryCount; i++) {
        cout << entries[i].date << " - " << entries[i].category << ": "
             << (entries[i].isIncome ? "+" : "-") << entries[i].amount << " PKR\n";
        if (entries[i].isIncome)
            totalIncome += entries[i].amount;
        else
            totalExpenses += entries[i].amount;
    }
    
    double balance = calculateBalance();
    cout << "\nTotal Income: " << totalIncome << " PKR\n";
    cout << "Total Expenses: " << totalExpenses << " PKR\n";
    cout << "Balance: " << balance << " PKR\n";
    cout << "Savings Goal: " << savingsGoal << " PKR\n";
    cout << "Remaining Savings Goal: " << (savingsGoal - balance) << " PKR\n";
}

int main() {
    int choice;
    
    do {
        cout << "\n--- Personal Finance Manager ---\n";
        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. Set Savings Goal\n";
        cout << "4. Display Summary\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addEntry(true); break;
            case 2: addEntry(false); break;
            case 3: setSavingsGoal(); break;
            case 4: displaySummary(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}