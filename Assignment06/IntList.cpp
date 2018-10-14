//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment06/IntList.cpp 
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
#include <algorithm>
#include "IntList.h"

using namespace std;

IntList::IntList()
{
    head = 0;
    tail = 0;
}

IntList::~IntList()
{
    while (head != 0)
    {
        pop_front();
    }
}

void IntList::display() const
{
    IntNode *curr = head;
    if(head != 0)
    {
        if(head->next != 0)
        {
            for (; curr->next != 0; curr = curr->next)
            {
                cout << curr->data << " ";
            }
            cout << curr->data;
        }
        else
        {
            cout << curr->data;
        }
    }
    return;
}

void IntList::push_front(int value)
{
    IntNode *temp =  new IntNode(value);
    
    if(head == 0)
    {
        tail = temp;
    }
    
    temp->next = head;
    head = temp;
    
    return;
}

void IntList::pop_front()
{
    if (head != 0)
    {
        if (head->next != 0)
        {
            IntNode *temp = 0;
            temp = head->next;
            delete head;
            head = temp;
        }
        else
        {
            delete head;
            head = 0;
            tail = 0;
        }
    }
    return;
}

void IntList::push_back(int value)
{
    IntNode *temp = new IntNode(value);
    
    if (head == 0)
    {
        head = temp;
    }
    else
    {
        tail->next = temp;
    }
    
    tail =  temp;
    
    return;
}

void IntList::select_sort()
{
    if (head != 0)
    {
        IntNode *MinVal =0;
        IntNode *i = head;
        IntNode *j = 0;
        for (; i != 0; i = i->next)
        {
            MinVal = i;
            for (j = i->next; j != 0; j = j->next)
            {
                if((j->data) < (MinVal->data))
                {
                    MinVal = j;
                }
            }
            
            if (MinVal != i)
            {
                swap((i->data), (MinVal->data));
            }
        }
    }
    
    return;
}

void IntList::insert_sorted(int value)
{
    IntNode *newNode = new IntNode(value);
    IntNode *temp = 0;
    IntNode *i = head;
    IntNode *lastnode = i;
    bool inserted = false;
    
    //list with entries
    for (; i != 0; i = i->next)
    {
        if (!inserted)
        {
            if ((newNode->data) <= (i->data))
            {
                if (i == head) //beginning of list
                {
                    // cout << "Insterted into beginning of list" << endl;
                    // cout << "i: " << i->data << endl;
                    newNode->next = head;
                    head = newNode;
                    inserted = true;

                }
                else // middle of list
                {
                    temp = lastnode->next;
                    lastnode->next = newNode;
                    newNode->next = temp;
                    inserted = true;
                    // cout << "Insterted into middle of list" << endl;
                    // cout << "i: " << i->data << endl;
                }
            }
            else if (i->next == 0) // end of list
            {
                newNode->next = 0;
                i->next = newNode;
                tail = newNode;
                inserted = true;
                // cout << "Insterted into end of list" << endl;
                // cout << "i: " << i->data << endl;
            }
        }
        lastnode = i;
    }
    
    if (!inserted)//empty list
    {
        newNode->next = head;
        head = newNode;
        tail = newNode;
        inserted = true;
        // cout << "Insterted into empty list" << endl;
        // cout << "i: " << i->data << endl;
    }

    return;
}

 void IntList::remove_duplicates()
 {
    IntNode *i = head;
    IntNode *j = head;
    IntNode *lastnode = head;
    IntNode *nodebefore = head;
    IntNode *duplicate = head;
    bool found = false;
     
     for (; i != 0; i = i->next)
     {
         for(j = i->next, lastnode = j; j != 0; j = j->next)
         {
             if (((i->data) == (j->data)) && ((i->next) != j))
             {
                // cout << endl;
                // cout << "Found Duplicate: " << i->data << " and " << j->data;cout << endl;
                // cout << " i: " << i << " i->data: " << i->data; cout << endl;
                // cout << " j: " << j << " j->data: " << j->data;cout << endl;
                //cout << " lastnode: " << lastnode << " lastnode->data: " << lastnode->data;cout << endl;
                //cout << endl;
                
                nodebefore = lastnode;
                duplicate = j;
                found = true;
             }
             else if(((i->data) == (j->data)))
             {
                // cout << endl;
                // cout << "Found Duplicate: " << i->data << " and " << j->data;cout << endl;
                // cout << " i: " << i << " i->data: " << i->data; cout << endl;
                // cout << " j: " << j << " j->data: " << j->data;cout << endl;
                //cout << " lastnode: " << lastnode << " lastnode->data: " << lastnode->data;cout << endl;
                //cout << endl;
                
                nodebefore = i;
                duplicate = j;
                found = true;
             }
             
             
             if(found)
             {
                //cout << " nodebefore: " << nodebefore << " nodebefore->data: " << nodebefore->data; cout << endl;
                //cout << " duplicate: " << duplicate << " duplicate->data: " << duplicate->data;cout << endl;
                //cout << endl;
                //cout << "Delete called on address " << duplicate << endl << endl;

                nodebefore->next = duplicate->next;
                if (duplicate->next == 0)
                {
                    tail = nodebefore;
                }
                
                
                delete duplicate;
                
                j = nodebefore;
                found = false;
             }
            lastnode = j;
         }
     }
     
     return;
 }









