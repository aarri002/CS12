//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment06/main.cpp 
/// @brief Assignment 6 for CS 12 Fall 2014
///
/// @author Alberto Arriaga Felix [aarri002@ucr.edu]
/// @date 11/25/2014
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 021
/// @par
///     TA: Leo P. Vu
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>
#include "IntList.h"

using namespace std;

int main()
{
    IntList list1 = IntList();
    IntList list2 = IntList();
    IntList list3 = IntList();
    IntList list4 = IntList();
    
    cout << "Filling list1 with push_front:" << endl;
    for (int i = 1; i < 11; ++i)
    {
        list1.push_front(i);
        list1.display();
         cout << endl;
    }
    
    cout << endl;
    cout << "Emptying list1 with pop_front:" << endl;
    
    for (int i = 1; i < 11; ++i)
    {
        list1.display();
        cout << endl;
        list1.pop_front();
    }
    
    cout << endl;
    cout << "Filling list1 with push_back:" << endl;
    
     for (int i = 1; i < 11; ++i)
    {
        list1.push_back(i);
        list1.display();
        cout << endl;
    }
    
    cout << endl;
    cout << "Testing select_sort() with List 2: " << endl;
    
    for (int i = 1; i < 11; ++i)
    {
        list2.push_front(i);
    }
    cout << "Unsorted: ";
    list2.display();
    cout << endl;
    
    list2.select_sort();
    cout << "Sorted: ";
    list2.display();
    cout << endl;
    
    
    cout << endl;
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "==============================================================" << endl;
    
    
    cout << endl;
    cout << "Testing insert_sorted() with List 2, inserting 5: " << endl;
    
    cout << "Original: ";
    list2.display();
    cout << endl;
    
    list2.insert_sorted(5);
    
    cout << "After: ";
    list2.display();
    cout << endl;
    
    cout << endl;
    cout << "Testing insert_sorted() with List 2, inserting 1: " << endl;
    
    cout << "Original: ";
    list2.display();
    cout << endl;
    
    list2.insert_sorted(1);
    
    cout << "After: ";
    list2.display();
    cout << endl;
    
    cout << endl;
    cout << "Testing insert_sorted() with List 2, inserting 11: " << endl;
    
    cout << "Original: ";
    list2.display();
    cout << endl;
    
    list2.insert_sorted(11);
    
    cout << "After: ";
    list2.display();
    cout << endl;
    
    cout << endl;
    cout << "Testing insert_sorted() with List 2, inserting 10: " << endl;
    
    cout << "Original: ";
    list2.display();
    cout << endl;
    
    list2.insert_sorted(10);
    
    cout << "After: ";
    list2.display();
    cout << endl;
    
    cout << endl;
    cout << "Testing insert_sorted() with List 2, inserting -100: " << endl;
    
    cout << "Original: ";
    list2.display();
    cout << endl;
    
    list2.insert_sorted(-100);
    
    cout << "After: ";
    list2.display();
    cout << endl;
    
    cout << endl;
    cout << "Testing insert_sorted() with List 2, inserting 0: " << endl;
    
    cout << "Original: ";
    list2.display();
    cout << endl;
    
    list2.insert_sorted(0);
    
    cout << "After: ";
    list2.display();
    cout << endl;
    
    cout << endl;
    cout << "Testing insert_sorted() with List 2, inserting 100: " << endl;
    
    cout << "Original: ";
    list2.display();
    cout << endl;
    
    list2.insert_sorted(100);
    
    cout << "After: ";
    list2.display();
    cout << endl;
    
    cout << endl;
    cout << "Testing insert_sorted() with List 4, inserting 37 into empty list: " << endl;
    
    cout << "Original: ";
    list4.display();
    cout << endl;
    
    list4.insert_sorted(37);
    
    cout << "After: ";
    list4.display();
    cout << endl;
    
    cout << endl;
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "==============================================================" << endl;
    
    list3.push_back(545);
    list3.push_back(86);
    list3.push_back(545);
    list3.push_back(403);
    list3.push_back(996);
    list3.push_back(999);
    list3.push_back(234);
    list3.push_back(353);
    list3.push_back(86);
    list3.push_back(482);
    list3.push_back(86);
    list3.push_back(545);
    
    cout << endl;
    cout << "Testing remove_duplicates() with List 2: " << endl;
    
    cout << "Original: ";
    list2.display();
    cout << endl;
    
    list2.remove_duplicates();
    
    cout << "After: ";
    list2.display();
    cout << endl;
    
    cout << endl;
    cout << "Testing remove_duplicates() with List 3: " << endl;
    
    cout << "Original: ";
    list3.display();
    cout << endl;
    
    list3.remove_duplicates();
    
    cout << "After: ";
    list3.display();
    cout << endl;
    
    
 
    
    return 0;
}