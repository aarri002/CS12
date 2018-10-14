//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment05/IntVector.h 
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

#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

class IntVector
{
    private:
        unsigned sz;
        unsigned cap;
        int *data;
    public:
        IntVector();
        IntVector(unsigned size);
        IntVector(unsigned size, int value);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at (unsigned index) const;
        int & at( unsigned index );
        void insert(unsigned index, int value);
        void erase(unsigned index);
        const int & front() const;
        int & front();
        const int & back() const;
        int & back();
        void assign(unsigned n, int value);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned size);
        void resize(unsigned size, int value);
        void reserve(unsigned n);
        //temp function
        void display() const;
        
    private:
        void expand();
        void expand(unsigned amount);
};

#endif