cmake_minimum_required(VERSION 4.0)
project(OOP_Project_Hatem_Mahmoud)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP_Project_Hatem_Mahmoud main.cpp
        Income.cpp
        Income.h
        IncomeList.cpp
        IncomeList.h
        Expense.cpp
        Expense.h
        Entry.cpp
        Entry.h
        ExpenseList.cpp
        ExpenseList.h
        Category.cpp
        Category.h
        CategoryList.cpp
        CategoryList.h
)
