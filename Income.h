//
// Created by hatem on 1/14/2026.
//

#ifndef OOP_PROJECT_HATEM_MAHMOUD_INCOME_H
#define OOP_PROJECT_HATEM_MAHMOUD_INCOME_H

#include <string>
#include "Entry.h"
using namespace std;


class Income : public Entry {
    private:
        string Source;

    public:
        Income *Next;
        Income *Prev;

        Income() {
            Next = nullptr;
            Prev = nullptr;
        }
        int setSource(string source) {
            this->Source = source;
            return 1;
        }

        string getSource() {
            return this->Source;
        }
};


#endif //OOP_PROJECT_HATEM_MAHMOUD_INCOME_H