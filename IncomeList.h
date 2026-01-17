//
// Created by hatem on 1/14/2026.
//

#ifndef OOP_PROJECT_HATEM_MAHMOUD_INCOMELIST_H
#define OOP_PROJECT_HATEM_MAHMOUD_INCOMELIST_H

#include <chrono>
#include <iostream>
#include <string>

#include "Income.h"

using namespace std;

class IncomeList {

    private:
        Income *Head;
        Income *Tail;
        int size;

    public:
        IncomeList () {
            Head = nullptr;
            Tail = nullptr;
            size = 0;
        }

        int GetSize() {
            return size;
        }

        void AddIncome () {

            Income *newIncome = new Income ();

            int amount;
            string source;
            int year;
            int month;
            int day;

            cout << "Please enter income amount: "<< endl;
            cin >> amount;

            while (!(newIncome->setAmount(amount))) {
                cout << "Please enter a valid income amount: "<< endl;
                cin>>amount;
            }

            cout << "Please enter income source: "<< endl;
            cin >> source;

            while (!(newIncome->setSource(source))) {
                cout << "Please enter a valid income source: "<< endl;
                cin>>source;
            }

            cout << "Please enter income date: (format '(YYYY MM DD)')"<< endl;
            cin >> year >> month >> day;

            while (!(newIncome->setDate(year,month,day))) {
                cout << "Please enter a valid income date: "<< endl;
                cin >> year >> month >> day;
            }

            if (Head == nullptr && Tail == nullptr) {
                Head = newIncome;
                Tail = newIncome;
            }
            else {
                Head->Next=newIncome;
                newIncome->Prev=Head;
                Head=newIncome;
            }

            cout<< "Income entry is added successfully" << endl << endl;
            size++;
        }

        void DisplayAllIncome() {
            if (size ==0) {
                cout << "No income entries yet to display"<< endl;
                return;
            }
            cout << "--- All Income Entries ---" << endl;

            Income *currentIncome = Tail;

            int amount;
            string source;
            string date;
            int counter = 1;

            while (currentIncome != nullptr) {

                amount = currentIncome->getAmount();
                source = currentIncome->getSource();
                date = currentIncome->getDate();

                cout << counter << ". "<< amount << " " << source << " " << date << endl;

                counter++;

                currentIncome = currentIncome->Next;
            }
        }

        void UpdateIncome(int order) {

            if (order>size || order<1) {
                cout << "No Income with such order"<< endl;
                return;
            }

            Income *selectedIncome = Tail;

            int counter = 1;
            int newAmount;
            string newSource;
            int newYear;
            int newMonth;
            int newDay;

            while (counter != order) {
                selectedIncome = selectedIncome->Next;
                counter++;
            }

            int oldAmount = selectedIncome->getAmount();
            string oldSource = selectedIncome->getSource();
            string oldDate = selectedIncome->getDate();

            cout << order << ". "<< oldAmount << " " << oldSource << " " << oldDate << endl;


            cout << "Please enter new income amount: "<< endl;
            cin >> newAmount;
            if (!selectedIncome->setAmount(newAmount)) {
                cout << "Invalid income amount, amount will remain the same"<< endl;
            }

            cout << "Please enter new income source: "<< endl;
            cin >> newSource;
            if (!selectedIncome->setSource(newSource)) {
                    cout << "Invalid income source, source will remain the same"<< endl;
            }

            cout << "Please enter new income Date: " << endl;
            cin >> newYear >> newMonth >> newDay;
            if (!selectedIncome->setDate(newYear,newMonth,newDay)) {
                cout << "Invalid income date, date will remain the same"<< endl;
            }

            cout<< "Income entry is updated successfully" << endl << endl;
        }

        void RemoveIncome(int order) {

            if (order>size || order<1) {
                cout << "No Income with such order"<< endl;
                return;
            }

            Income *selectedIncome = Tail;

            int counter = 1;
            int newAmount;
            string newSource;
            string newDate;

            while (counter != order) {
                selectedIncome = selectedIncome->Next;
                counter++;
            }

            if (selectedIncome == Head && selectedIncome == Tail) {
                Head = Tail = nullptr;

            }
            else if (selectedIncome == Head) {
                Head = Head->Prev;
                Head->Next = nullptr;

            }
            else if(selectedIncome == Tail) {
                Tail = Tail->Next;
                Tail->Prev = nullptr;
            }
            else {
                selectedIncome->Prev->Next = selectedIncome->Next;
                selectedIncome->Next->Prev = selectedIncome->Prev;
            }

            delete selectedIncome;
            size--;

            cout<< "Income entry is deleted successfully" << endl << endl;
        }

    int calculateTotalIncome() {
            int total = 0;
            Income *current = Tail;
            while (current != nullptr) {
                total += current->getAmount();
                current = current->Next;
            }
            return total;
        }

    void DisplayIncomeByPeriod(int sY, int sM, int sD, int eY, int eM, int eD) {
            if (size == 0) {
                cout << "No income entries to search." << endl;
                return;
            }

            cout << "--- Income Report (" << sY<<"-"<<sM<<"-"<<sD << " to " << eY<<"-"<<eM<<"-"<<eD << ") ---" << endl;

            long startVal = sY * 10000 + sM * 100 + sD;
            long endVal = eY * 10000 + eM * 100 + eD;

            Income *current = Tail;
            bool found = false;
            int counter = 1;

            while (current != nullptr) {
                int entryY = current->getYear();
                int entryM = current->getMonth();
                int entryD = current->getDay();
                long entryVal = entryY * 10000 + entryM * 100 + entryD;

                if (entryVal >= startVal && entryVal <= endVal) {
                    cout << counter << ". " << current->getAmount() << " " << current->getSource() << " " << current->getDate() << endl;
                    found = true;
                    counter++;
                }
                current = current->Next;
            }

            if (!found) {
                cout << "No income entries found in this period." << endl;
            }
            cout << endl;
        }
};


#endif //OOP_PROJECT_HATEM_MAHMOUD_INCOMELIST_H