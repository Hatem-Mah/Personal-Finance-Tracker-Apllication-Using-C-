#include <iostream>
#include "IncomeList.h"
#include "ExpenseList.h"

using namespace std;


int main() {

    cout << "-- Welcome To Personal Finance Tracker App ---"<< endl;


    IncomeList income_list;
    ExpenseList expense_list;
    CategoryList categories;

    int input_1;

    do {
        cout << endl << "Please choose one of the following options: " << endl;
        cout << "1) To manage the income"<< endl;
        cout << "2) to manage the expenses" << endl;
        cout << "3) to manage the budget" << endl;
        cout << "4) for the reports" << endl;
        cout << "-1) To exit the program "<<endl;
        cin>>input_1;

        int input_2;

        switch (input_1) {
            case 1:
                do {
                    cout << endl << "Please choose one of the following options: " << endl;
                    cout << "1) To add new income entry" << endl;
                    cout << "2) To update existing income entry" << endl;
                    cout << "3) To delete existing income entry" << endl;
                    cout << "4) To show all existing income entries" << endl;
                    cout << "-1) To go back"<< endl;
                    cin>>input_2;

                    int order;

                    switch (input_2) {
                        case 1:
                            income_list.AddIncome();
                            break;
                        case 2:
                            if (income_list.GetSize() ==0) {
                                cout << "No income entries yet to update"<< endl;
                                break;
                            }
                            income_list.DisplayAllIncome();
                            cout << "Please enter the order of the item you want to update: "<< endl;
                            cin>>order;
                            income_list.UpdateIncome(order);
                            break;
                        case 3:
                            if (income_list.GetSize() ==0) {
                                cout << "No income entries yet to delete"<< endl;
                                break;
                            }
                            income_list.DisplayAllIncome();
                            cout << "Please enter the order of the item you want to delete: "<< endl;
                            cin>>order;
                            income_list.RemoveIncome(order);
                            break;
                        case 4:
                            income_list.DisplayAllIncome();
                            break; // Added break here for safety
                        case -1:
                            break;
                        default:
                            cout << "Invalid option" << endl;
                    }
                } while (input_2 !=-1);

            break;

            case 2:
                do {
                    cout << endl << "Please choose one of the following options: " << endl;
                    cout << "1) To add new expense entry" << endl;
                    cout << "2) To update existing expense entry" << endl;
                    cout << "3) To delete existing expense entry" << endl;
                    cout << "4) To show all existing expense entries" << endl;
                    cout << "-1) To go back"<< endl;
                    cin>>input_2;

                    int order;

                    switch (input_2) {
                        case 1:
                            expense_list.AddExpense(categories);
                            break;
                        case 2:
                            if (expense_list.GetSize() ==0) {
                                cout << "No expense entries yet to update"<< endl;
                                break;
                            }
                            expense_list.DisplayAllExpense();
                            cout << "Please enter the order of the item you want to update: "<< endl;
                            cin>>order;
                            expense_list.UpdateExpense(order);
                            break;
                        case 3:
                            if (expense_list.GetSize() ==0) {
                                cout << "No expense entries yet to delete"<< endl;
                                break;
                            }
                            expense_list.DisplayAllExpense();
                            cout << "Please enter the order of the item you want to delete: "<< endl;
                            cin>>order;
                            expense_list.RemoveExpense(order);
                            break;
                        case 4:
                            expense_list.DisplayAllExpense();
                            break;
                        case -1:
                            break;
                        default:
                            cout << "Invalid option" << endl;
                    }
                } while (input_2 !=-1);
                break;

            case 3:
                do {
                    cout << endl << "--- Budget Management ---" << endl;
                    cout << "Please choose one of the following options: " << endl;
                    cout << "1) To set budget for a category" << endl;
                    cout << "2) To view budget status" << endl;
                    cout << "-1) To go back" << endl;
                    cin >> input_2;

                    string catName;
                    int currentTotal;

                    switch (input_2) {
                        case 1:
                            cout << "Enter Category Name (e.g., Food, Transport): " << endl;
                            cin >> catName;

                            // 1. Calculate existing expenses for this category
                            currentTotal = expense_list.calculateTotalForCategory(catName);

                            // 2. Pass name and total to AddCategory
                            categories.AddCategory(catName, currentTotal);
                            break;

                        case 2:
                            categories.DisplayBudgets();
                            break;

                        case -1:
                            break;

                        default:
                            cout << "Invalid option" << endl;
                    }
                } while (input_2 != -1);
                break;

            case 4:
            do {
                cout << endl << "--- Financial Reports ---" << endl;
                cout << "Please choose one of the following options: " << endl;
                cout << "1) General Summary (Total Income, Expenses, Balance)" << endl;
                cout << "2) Detailed Reports (By Category or Time)" << endl;
                cout << "-1) To go back" << endl;
                cin >> input_2;

                switch (input_2) {
                    case 1: {
                        // FR9: Summary Report
                        int totalInc = income_list.calculateTotalIncome();
                        int totalExp = expense_list.calculateTotalExpense();
                        int balance = totalInc - totalExp;

                        cout << "--- General Financial Summary ---" << endl;
                        cout << "Total Income:   " << totalInc << endl;
                        cout << "Total Expenses: " << totalExp << endl;
                        cout << "Net Balance:    " << balance << endl;
                        cout << "---------------------------------" << endl;
                        break;
                    }
                    case 2: {
                        int input_3;
                        cout << "1) Report by Expense Category" << endl;
                        cout << "2) Report by Time Period" << endl;
                        cin >> input_3;

                        if (input_3 == 1) {
                            string catSearch;
                            cout << "Enter Category name to filter by: ";
                            cin >> catSearch;
                            expense_list.DisplayExpensesByCategory(catSearch);
                        }
                        else if (input_3 == 2) {
                            int sY, sM, sD, eY, eM, eD;
                            cout << "Enter Start Date (YYYY MM DD): ";
                            cin >> sY >> sM >> sD;
                            cout << "Enter End Date (YYYY MM DD): ";
                            cin >> eY >> eM >> eD;

                            income_list.DisplayIncomeByPeriod(sY, sM, sD, eY, eM, eD);
                            expense_list.DisplayExpensesByPeriod(sY, sM, sD, eY, eM, eD);
                        }
                        else {
                            cout << "Invalid selection." << endl;
                        }
                        break;
                    }
                    case -1:
                        break;
                    default:
                        cout << "Invalid option" << endl;
                }
            } while (input_2 != -1);
            break;

            case -1:
                break;

            default:
                cout << "Invalid option" << endl;
        }
    } while (input_1 != -1);

    cout << endl << "Thanks for using Personal Finance Tracker APP" << endl;
    cout << "We wish you had a great experience, and we are waiting for your feedback :D" <<endl;

}