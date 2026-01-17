//
// Created by hatem on 1/15/2026.
//

#ifndef OOP_PROJECT_HATEM_MAHMOUD_EXPENSE_H
#define OOP_PROJECT_HATEM_MAHMOUD_EXPENSE_H


#include <string>
#include "Entry.h"
using namespace std;


class Expense : public Entry {
private:
    string Category;

public:
    Expense *Next;
    Expense *Prev;

    Expense() {
        Next = nullptr;
        Prev = nullptr;
    }
    int setCategory(string Category) {
        this->Category = Category;
        return 1;
    }

    string getCategory() {
        return this->Category;
    }
};


#endif //OOP_PROJECT_HATEM_MAHMOUD_EXPENSE_H