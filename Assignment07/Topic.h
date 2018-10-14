//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment07/Topic.h
/// @brief Assignment 7 for CS 12 Fall 2014
///
/// @author Alberto Arriaga Felix [aarri002@ucr.edu]
/// @date 12/06/2014
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

#ifndef __TOPIC_H__
#define __TOPIC_H__

#include "Message.h"

#include <string>
#include <vector>

using namespace std;

class Topic : public Message
{
    public:
        //default constructor
        Topic();
        //Parameterized constructor
        Topic(const string &athr,
              const string &sbjct,
              const string &body,
              unsigned id);
              
        virtual bool is_reply() const; // Returns false
    
        /* to_formatted_string writes the contents of the Topic to a
        * string in the following format:
        <begin_topic>
        : id: 4
        : subj ect: single line
        : from: author
        : children: 5 6 [ this line should not be printed if there are no children. ]
        : body: multiple lines ­ line 1
        line 2
        line 3
        <end>
        * line starting with : children: has the id' s of all children ( See file specs.
        * for details)
        */
        virtual string to_formatted_string() const;
};

#endif