//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment07/Reply.cpp
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

#include "Reply.h"

#include <string>
#include <vector>
#include <sstream>

using namespace std;

Reply::Reply()
{
    author = "";
    subject = "";
    body = "";
}

Reply::Reply(const string &athr, const string &sbjct, const string &body, unsigned id)
{
    author = athr;
    subject = sbjct;
    this->body = body;
    this->id = id;
}

bool Reply::is_reply() const //Returns false
{
    return true;
}

/* to_formatted_string writes the contents of the Reply to a string in the
    following format:
    <begin_reply>
    :id: 4
    :subject: single line
    :from: author
    :children: 5 6 [ this line should not be printed if there are no children. ]
    :body: multiple lines
    2nd line
    <end>
    the line starting with : children: has the list of id' s of all children
    ( See file specs. for details)
*/
string Reply::to_formatted_string() const
{
    ostringstream convert;
    convert << this->id;
    
    string formated_string = "";
    formated_string = "<begin_reply>\n";
    formated_string += ":id: " + convert.str() + "\n";
    formated_string += ":subject: " + this->subject + "\n";
    formated_string += ":from: " + this->author + "\n";
    if(this->child_list.size() > 0)
    {
        convert.str("");
        //cout << "Id list: ";
        for(unsigned i = 0; i < child_list.size(); ++i)
        {
            convert << (child_list.at(i))->get_id() << " ";
        }
        //cout << convert.str() << endl;
        formated_string += ":children: " + convert.str() + "\n";
    }
    formated_string += ":body: " + this->body + "\n";
    formated_string += "<end>\n";
    
    return formated_string;
}