//
// Created by hatem on 1/15/2026.
//

#ifndef OOP_PROJECT_HATEM_MAHMOUD_CATEGORYLIST_H
#define OOP_PROJECT_HATEM_MAHMOUD_CATEGORYLIST_H

#include "Category.h"
#include <iostream>
#include <string>

using namespace std;

class CategoryList {
private:
    Category *Head;
    Category *Tail;
    int size;

public:
    CategoryList() {
        Head = nullptr;
        Tail = nullptr;
        size = 0;
    }

    void AddCategory(string name, int currentTotal) {
        Category *newCategory = new Category();

        newCategory->setName(name);

        newCategory->setSpending(currentTotal);

        int limit;
        bool validLimit = false;

        do {
            cout << "Enter Budget Limit for " << name << ": " << endl;
            cin >> limit;

            if (limit < currentTotal) {
                cout << "Error: Budget limit (" << limit << ") cannot be lower than current expenses (" << currentTotal << ")." << endl;
                cout << "Please try again and add a budget higher than the total expenses." << endl;
            } else {
                validLimit = true;
            }

        } while (!validLimit);

        newCategory->setLimit(limit);

        if (Head == nullptr && Tail == nullptr) {
            Head = newCategory;
            Tail = newCategory;
        } else {
            Head->Next = newCategory;
            newCategory->Prev = Head;
            Head = newCategory;
        }

        size++;
        cout << "Budget category set successfully!" << endl << endl;
    }

    void DisplayBudgets() {
        if (size == 0) {
            cout << "No budgets set yet." << endl;
            return;
        }

        Category *current = Tail;
        cout << "--- Budget Status ---" << endl;
        while (current != nullptr) {
            cout << "Category: " << current->getName()
                 << " | Limit: " << current->getLimit()
                 << " | Spent: " << current->getCurrentSpending() << endl;
            current = current->Next;
        }
        cout << endl;
    }

    void TrackSpending(string categoryName, int amount) {
        Category *current = Tail;
        while (current != nullptr) {
            if (current->getName() == categoryName) {
                current->addSpending(amount);

                int spent = current->getCurrentSpending();
                int limit = current->getLimit();

                if (spent > limit) {
                    cout << "!!! ALERT: You have EXCEEDED your budget for " << categoryName << " !!!" << endl;
                    cout << "Overspent by: " << (spent - limit) << endl;
                }
                else if (spent >= (limit * 0.9)) { // Notify if 90% of budget is used
                    cout << "!!! WARNING: You are close to your budget limit for " << categoryName << " !!!" << endl;
                    cout << "Remaining: " << (limit - spent) << endl;
                }
                return;
            }
            current = current->Next;
        }
    }
};

#endif //OOP_PROJECT_HATEM_MAHMOUD_CATEGORYLIST_H