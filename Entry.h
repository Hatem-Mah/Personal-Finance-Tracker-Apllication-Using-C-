//
// Created by hatem on 1/15/2026.
//

#ifndef OOP_PROJECT_HATEM_MAHMOUD_ENTRY_H
#define OOP_PROJECT_HATEM_MAHMOUD_ENTRY_H

#include <string>

using namespace std;

class Entry {

private:
    int Amount;
    int Year;
    int Month;
    int Day;

    bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool isValidDate(int year, int month, int day) {

        if (year < 1900 || year > 2100) {
            return 0;
        }
        if (month < 1 || month > 12) {
            return 0;
        }

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (isLeap(year)) {
            daysInMonth[2] = 29;
        }

        if (day < 1 || day > daysInMonth[month]) {
            return 0;
        }

        return true;
    }

public:

    virtual ~Entry() {}

    int setAmount(int amount) {
        if (amount > 0) {
            this->Amount = amount;
            return 1;
        }
        return 0;
    }

    int setDate(int year, int month, int day) {
        if (isValidDate(year, month, day)) {
            this->Year = year;
            this->Month = month;
            this->Day = day;
            return 1;
        }
        return 0;
    }

    int getAmount() {
        return this->Amount;
    }

    string getDate() {
        string y_str = to_string(Year);
        string m_str = to_string(Month);
        string d_str = to_string(Day);

        return y_str + "-" + m_str + "-" + d_str;
    }

    int getYear() {
        return this->Year;
    }
    int getMonth() {
        return this->Month;
    }
    int getDay() {
        return this->Day;
    }
};


#endif //OOP_PROJECT_HATEM_MAHMOUD_ENTRY_H