//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment05/main.cpp 
/// @brief Assignment 5 for CS 12 Fall 2014
///
/// @author Alberto Arriaga Felix [aarri002@ucr.edu]
/// @date 11/19/2014
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
#include "IntVector.h"

using namespace std;

int main ()
{
    
    
    cout << "-----data1 data2 data3 initialized-----" << endl << endl;
    
    IntVector data1;
    IntVector data2 = IntVector(5);
    IntVector data3 = IntVector(10, 1);
    
    cout << "Size of data 1: " << data1.size() << endl;
    cout << "Size of data 2: " << data2.size() << endl;
    cout << "Size of data 3: " << data3.size() << endl << endl;
    
    cout << "Capacity of data 1: " << data1.capacity() << endl;
    cout << "Capacity of data 2: " << data2.capacity() << endl;
    cout << "Capacity of data 3: " << data3.capacity() << endl << endl;
    
    cout << "Data 1: "; data1.display(); cout << endl;
    cout << "Data 2: "; data2.display(); cout << endl;
    cout << "Data 3: "; data3.display(); cout << endl<< endl;
    
    
    cout << "-----Using resize(0) on datas-----" << endl << endl;
    
    data1.resize(0);
    data2.resize(0);
    data3.resize(0);
    
    cout << "Size of data 1: " << data1.size() << endl;
    cout << "Size of data 2: " << data2.size() << endl;
    cout << "Size of data 3: " << data3.size() << endl << endl;
    
    cout << "Capacity of data 1: " << data1.capacity() << endl;
    cout << "Capacity of data 2: " << data2.capacity() << endl;
    cout << "Capacity of data 3: " << data3.capacity() << endl << endl;
    
    cout << "Data 1: "; data1.display(); cout << endl;
    cout << "Data 2: "; data2.display(); cout << endl;
    cout << "Data 3: "; data3.display(); cout << endl<< endl;
    
    
    
    cout << "-----Using resize(5) on datas-----" << endl << endl;
    
    data1.resize(5);
    data2.resize(5);
    data3.resize(5);
    
    cout << "Size of data 1: " << data1.size() << endl;
    cout << "Size of data 2: " << data2.size() << endl;
    cout << "Size of data 3: " << data3.size() << endl << endl;
    
    cout << "Capacity of data 1: " << data1.capacity() << endl;
    cout << "Capacity of data 2: " << data2.capacity() << endl;
    cout << "Capacity of data 3: " << data3.capacity() << endl << endl;
    
    cout << "Data 1: "; data1.display(); cout << endl;
    cout << "Data 2: "; data2.display(); cout << endl;
    cout << "Data 3: "; data3.display(); cout << endl<< endl;
    
    cout << "-----Using assign(10,1) to make everything size 10 with 1's as data-----" << endl << endl;
    
    data1.assign(10,1);
    data2.assign(10,1);
    data3.assign(10,1);
    
    cout << "Size of data 1: " << data1.size() << endl;
    cout << "Size of data 2: " << data2.size() << endl;
    cout << "Size of data 3: " << data3.size() << endl << endl;
    
    cout << "Capacity of data 1: " << data1.capacity() << endl;
    cout << "Capacity of data 2: " << data2.capacity() << endl;
    cout << "Capacity of data 3: " << data3.capacity() << endl << endl;
    
    cout << "Data 1: "; data1.display(); cout << endl;
    cout << "Data 2: "; data2.display(); cout << endl;
    cout << "Data 3: "; data3.display(); cout << endl<< endl;
    
    cout << "-----Using resize(5) resize(14) resize(21) on datas, should get 10 20 21-----" << endl << endl;
    
    data1.resize(5);
    data2.resize(14);
    data3.resize(21);
    
    cout << "Size of data 1: " << data1.size() << endl;
    cout << "Size of data 2: " << data2.size() << endl;
    cout << "Size of data 3: " << data3.size() << endl << endl;
    
    cout << "Capacity of data 1: " << data1.capacity() << endl;
    cout << "Capacity of data 2: " << data2.capacity() << endl;
    cout << "Capacity of data 3: " << data3.capacity() << endl << endl;
    
    cout << "Data 1: "; data1.display(); cout << endl;
    cout << "Data 2: "; data2.display(); cout << endl;
    cout << "Data 3: "; data3.display(); cout << endl<< endl;
    
    
    
    cout << "-----Using resize(10,2) resize(20,2) resize(43,2) on datas, should get 10 40 43-----" << endl << endl;
    
    data1.resize(10,2);
    data2.resize(30,2);
    data3.resize(43,2);
    
    cout << "Size of data 1: " << data1.size() << endl;
    cout << "Size of data 2: " << data2.size() << endl;
    cout << "Size of data 3: " << data3.size() << endl << endl;
    
    cout << "Capacity of data 1: " << data1.capacity() << endl;
    cout << "Capacity of data 2: " << data2.capacity() << endl;
    cout << "Capacity of data 3: " << data3.capacity() << endl << endl;
    
    cout << "Data 1: "; data1.display(); cout << endl;
    cout << "Data 2: "; data2.display(); cout << endl;
    cout << "Data 3: "; data3.display(); cout << endl<< endl;
    
    
    return 0;
}