//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment07/Reply.h 
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

#ifndef __REPLY_H__
#define __REPLY_H__

#include "Message.h"

#include <string>
#include <vector>

using namespace std;

class Reply : public Message
{
    public:
        //default constructor
        Reply();
        /* Parameterized constructor - similar to Message' s constructor except:
        * The subj ect should be initialized to "Re: <sbj ct>" not <sbj ct>.
        */
        Reply( const string &athr,
        const string &sbjct,
        const string &body,
        unsigned id);
        virtual bool is_reply() const; //returns true
        /* to_formatted_string writes the contents of the Reply to a string in the
        * following format:
        <begin_reply>
        : id: 4
        : subj ect: single line
        : from: author
        : children: 5 6 [ this line should not be printed if there are no children. ]
        : body: multiple lines
        2nd line
        <end>
        * the line starting with : children: has the list of id' s of all children
        * ( See file specs. for details)
        */
        virtual string to_formatted_string() const;
};


#endif