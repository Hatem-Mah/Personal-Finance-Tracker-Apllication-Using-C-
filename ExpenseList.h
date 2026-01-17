//
// Created by hatem on 1/15/2026.
//

#ifndef OOP_PROJECT_HATEM_MAHMOUD_EXPENSELIST_H
#define OOP_PROJECT_HATEM_MAHMOUD_EXPENSELIST_H

#include <iostream>
#include <string>
#include "Expense.h"
#include "CategoryList.h" // Include CategoryList to link expenses to budgets

using namespace std;

class ExpenseList {

private:
    Expense *Head;
    Expense *Tail;
    int size;

public:
    ExpenseList() {
        Head = nullptr;
        Tail = nullptr;
        size = 0;
    }

    int GetSize() {
        return size;
    }

    void AddExpense(CategoryList &catList) {

        Expense *newExpense = new Expense();

        int amount;
        string category;
        int year;
        int month;
        int day;

        cout << "Please enter expense amount: " << endl;
        cin >> amount;

        while (!(newExpense->setAmount(amount))) {
            cout << "Please enter a valid expense amount: " << endl;
            cin >> amount;
        }

        cout << "Please enter expense category: " << endl;
        cin >> category;

        while (!(newExpense->setCategory(category))) {
            cout << "Please enter a valid expense category: " << endl;
            cin >> category;
        }

        cout << "Please enter expense date: (format '(YYYY MM DD)')" << endl;
        cin >> year >> month >> day;

        while (!(newExpense->setDate(year, month, day))) {
            cout << "Please enter a valid expense date: " << endl;
            cin >> year >> month >> day;
        }

        if (Head == nullptr && Tail == nullptr) {
            Head = newExpense;
            Tail = newExpense;
        } else {
            Head->Next = newExpense;
            newExpense->Prev = Head;
            Head = newExpense;
        }

        cout << "Expense entry is added successfully" << endl;

        // Link to Budget Tracking (FR8)
        catList.TrackSpending(category, amount);

        cout << endl;
        size++;
    }

    void DisplayAllExpense() {
        if (size == 0) {
            cout << "No expense entries yet to display" << endl;
            return;
        }
        cout << "--- All Expense Entries ---" << endl;

        Expense *currentExpense = Tail;

        int amount;
        string category;
        string date;
        int counter = 1;

        while (currentExpense != nullptr) {
            amount = currentExpense->getAmount();
            category = currentExpense->getCategory();
            date = currentExpense->getDate();

            cout << counter << ". " << amount << " " << category << " " << date << endl;

            counter++;
            currentExpense = currentExpense->Next;
        }
    }

    void UpdateExpense(int order) {
        if (order > size || order < 1) {
            cout << "No Expense with such order" << endl;
            return;
        }

        Expense *selectedExpense = Tail;

        int counter = 1;
        int newAmount;
        string newCategory;
        int newYear;
        int newMonth;
        int newDay;

        while (counter != order) {
            selectedExpense = selectedExpense->Next;
            counter++;
        }

        int oldAmount = selectedExpense->getAmount();
        string oldCategory = selectedExpense->getCategory();
        string oldDate = selectedExpense->getDate();

        cout << order << ". " << oldAmount << " " << oldCategory << " " << oldDate << endl;

        cout << "Please enter new expense amount: " << endl;
        cin >> newAmount;
        if (!selectedExpense->setAmount(newAmount)) {
            cout << "Invalid expense amount, amount will remain the same" << endl;
        }

        cout << "Please enter new expense category: " << endl;
        cin >> newCategory;
        if (!selectedExpense->setCategory(newCategory)) {
            cout << "Invalid expense category, category will remain the same" << endl;
        }

        cout << "Please enter new expense Date: " << endl;
        cin >> newYear >> newMonth >> newDay;
        if (!selectedExpense->setDate(newYear, newMonth, newDay)) {
            cout << "Invalid expense date, date will remain the same" << endl;
        }

        cout << "Expense entry is updated successfully" << endl << endl;
    }

    void RemoveExpense(int order) {
        if (order > size || order < 1) {
            cout << "No Expense with such order" << endl;
            return;
        }

        Expense *selectedExpense = Tail;
        int counter = 1;

        while (counter != order) {
            selectedExpense = selectedExpense->Next;
            counter++;
        }

        if (selectedExpense == Head && selectedExpense == Tail) {
            Head = Tail = nullptr;
        } else if (selectedExpense == Head) {
            Head = Head->Prev;
            Head->Next = nullptr;
        } else if (selectedExpense == Tail) {
            Tail = Tail->Next;
            Tail->Prev = nullptr;
        } else {
            selectedExpense->Prev->Next = selectedExpense->Next;
            selectedExpense->Next->Prev = selectedExpense->Prev;
        }

        delete selectedExpense;
        size--;

        cout << "Expense entry is deleted successfully" << endl << endl;
    }

    int calculateTotalForCategory(string catName) {
        int total = 0;
        Expense *current = Tail;
        while (current != nullptr) {
            if (current->getCategory() == catName) {
                total += current->getAmount();
            }
            current = current->Next;
        }
        return total;
    }

    int calculateTotalExpense() {
        int total = 0;
        Expense *current = Tail;
        while (current != nullptr) {
            total += current->getAmount();
            current = current->Next;
        }
        return total;
    }

    void DisplayExpensesByCategory(string targetCat) {
        if (size == 0) {
            cout << "No expense entries to search." << endl;
            return;
        }

        cout << "--- Expense Report (Category: " << targetCat << ") ---" << endl;

        Expense *current = Tail;
        bool found = false;
        int counter = 1;

        while (current != nullptr) {
            if (current->getCategory() == targetCat) {
                 cout << counter << ". " << current->getAmount() << " " << current->getCategory() << " " << current->getDate() << endl;
                 found = true;
                 counter++;
            }
            current = current->Next;
        }

        if (!found) {
            cout << "No expenses found for this category." << endl;
        }
        cout << endl;
    }

    void DisplayExpensesByPeriod(int sY, int sM, int sD, int eY, int eM, int eD) {
        if (size == 0) {
            cout << "No expense entries to search." << endl;
            return;
        }

        cout << "--- Expense Report (" << sY<<"-"<<sM<<"-"<<sD << " to " << eY<<"-"<<eM<<"-"<<eD << ") ---" << endl;

        long startVal = sY * 10000 + sM * 100 + sD;
        long endVal = eY * 10000 + eM * 100 + eD;

        Expense *current = Tail;
        bool found = false;
        int counter = 1;

        while (current != nullptr) {
            int entryY = current->getYear();
            int entryM = current->getMonth();
            int entryD = current->getDay();
            long entryVal = entryY * 10000 + entryM * 100 + entryD;

            if (entryVal >= startVal && entryVal <= endVal) {
                cout << counter << ". " << current->getAmount() << " " << current->getCategory() << " " << current->getDate() << endl;
                found = true;
                counter++;
            }
            current = current->Next;
        }

        if (!found) {
            cout << "No expense entries found in this period." << endl;
        }
        cout << endl;
    }

};

#endif //OOP_PROJECT_HATEM_MAHMOUD_EXPENSELIST_H