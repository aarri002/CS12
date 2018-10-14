//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment05/IntVector.cpp
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

#include "IntVector.h"
#include <iostream>
#include <cstdlib>

using namespace std;

IntVector::IntVector()
: sz(0), cap(0), data(0)
{
    
}

IntVector::IntVector(unsigned size)
: sz(size), cap(size)
{
    data = new int[size];
    for (int i = 0; i < size; ++i)
    {
        data[i] = 0;
    }
}

IntVector::IntVector(unsigned size, int value)
: sz(size), cap(size)
{
    data = new int[size];
    for (int i = 0; i < size; ++i)
    {
        data[i] = value;
    }
}

IntVector::~IntVector()
{
    delete[] data;
}


unsigned IntVector::size() const
{
    return sz;
}

unsigned IntVector::capacity() const
{
    return cap;
}

bool IntVector::empty() const
{
    return (sz == 0)? true:false;
}

const int & IntVector::at (unsigned index) const
{
    if (index >= sz)
    {
        exit(1);
    }
    else
    {
        return data[index];
    }
}

int & IntVector::at( unsigned index )
{
    if (index >= sz)
    {
        exit(1);
    }
    else
    {
        return data[index];
    }
}

void IntVector::insert(unsigned index, int value)
{
    if (index > sz)
    {
        exit(1);
    }

    if((sz+1) > cap)
    {
        expand(sz);
    }
    
    sz++;
    
    for(int i = index; i < sz; ++i)
    {
        data[i+1] = data[i];
    }
    
    data[index] = value;

    return;
}

void IntVector::erase(unsigned index)
{
    if (index > sz-1)
    {
        exit(1);
    }
    
    for(int i = index; i < sz; ++i)
    {
        data[i] = data[i+1];
    }
    
    sz--;

    return;
}

const int & IntVector::front() const
{
    return data[0];
}

int & IntVector::front()
{
    return data[0];
}

const int & IntVector::back() const
{
    return data[sz-1];
}

int & IntVector::back()
{
    return data[sz-1];
}

void IntVector::assign(unsigned n, int value)
{
    clear();
    
    if(cap < n)
    {
        if (n > 2*cap)
        {
            expand(n-cap);
        }
        else
        {
            expand();
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        push_back(value);
    }
    
    cap = n;
    
    return;
}

void IntVector::push_back(int value)
{
    if((sz+1) > cap)
    {
        expand();
    }
    
    data[sz] = value;
    sz++;
    
    return;
}

void IntVector::pop_back()
{
    if (sz == 0)
    {
        exit(1);
    }
    sz--;
}

void IntVector::clear()
{
    sz = 0;
}

void IntVector::resize(unsigned size)
{
    if (size == sz)
    {
        //do nothing
    }
    
    if (size < sz)
    {
        sz = size;
    }
    
    if (size > sz)
    {
        if (size > cap)
        {
            if ((size) > (2*cap))
            {
                expand(size-cap);
            }
            else
            {
                expand();
            }
        }
        
        for(int i = sz; i < size; ++i)
        {
            push_back(0);
        }
        
    }

    return;
}

void IntVector::resize(unsigned size, int value)
{
    if (size == sz)
    {
        //do nothing
    }
    
    if (size < sz)
    {
        sz = size;
    }
    
    if (size > sz)
    {
        if (size > cap)
        {
            if ((size) > (2*cap))
            {
                expand(size-cap);
            }
            else
            {
                expand();
            }
        }
        
        for(int i = sz; i < size; ++i)
        {
            push_back(value);
        }
        
    }

    return;
    
}

void IntVector::reserve(unsigned n)
{
    if(cap < n)
    {
        if (n > 2*cap)
        {
            expand(n-cap);
        }
        else
        {
            expand();
        }
    }
    return;
}


void IntVector::expand()
{
    if (cap == 0)
    {
        if (sz == 0)
        {
            int *temp = new int[1];
            delete[] data;
            data = temp;
            cap = 1;
        }
        else
        {
            int *temp = new int[1];
            delete[] data;
            data = temp;
            cap = 1;
        }

    }
    else
    {
        if(sz == 0)
        {
            int *temp = new int[2*cap];
            delete[] data;
            data = temp;
            cap = 2*cap;
        }
        else
        {
            int *temp = new int[2*cap];
            for(int i = 0; i < sz; ++i)
            {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            cap = 2*cap;
        }
    }
    
    return;
}

void IntVector::expand(unsigned amount)
{
    if (cap == 0)
    {
        if (sz == 0)
        {
            int *temp = new int[amount];
            delete[] data;
            data = temp;
            cap = amount;
        }
        else
        {
            int *temp = new int[amount];
            delete[] data;
            data = temp;
            cap = amount;
        }

    }
    else
    {
        if(sz == 0)
        {
            int *temp = new int[cap + amount];
            delete[] data;
            data = temp;
            cap = cap + amount;
        }
        else
        {
            int *temp = new int[cap + amount];
            for(int i = 0; i < sz; ++i)
            {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            cap = cap + amount;
        }
    }
    
    return;
}

void IntVector::display() const
{
    for(int i = 0; i < sz; ++i)
    {
        cout << data[i] << " ";
    }
    if (sz == 0)
    {
        cout << "No Data";
    }
    return;
}