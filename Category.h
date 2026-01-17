//
// Created by hatem on 1/15/2026.
//

#ifndef OOP_PROJECT_HATEM_MAHMOUD_CATEGORY_H
#define OOP_PROJECT_HATEM_MAHMOUD_CATEGORY_H

#include <string>
#include <iostream>

using namespace std;

class Category {
private:
    string Name;
    int Limit;
    int CurrentSpending;

public:
    Category *Next;
    Category *Prev;

    Category() {
        Next = nullptr;
        Prev = nullptr;
        Limit = 0;
        CurrentSpending = 0;
    }

    void setName(string name) {
        this->Name = name;
    }

    string getName() {
        return this->Name;
    }

    void setLimit(int limit) {
        this->Limit = limit;
    }

    int getLimit() {
        return this->Limit;
    }

    void addSpending(int amount) {
        this->CurrentSpending += amount;
    }

    int getCurrentSpending() {
        return this->CurrentSpending;
    }
    void setSpending(int amount) {
        this->CurrentSpending = amount;
    }
};

#endif //OOP_PROJECT_HATEM_MAHMOUD_CATEGORY_H