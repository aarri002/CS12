//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment07/Message.cpp 
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
#include "Message.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Message::Message()
: author(""), subject(""), body(""), id()
{
}

Message::Message(const string &athr, const string &sbjct, const string &body, unsigned id)
: author(athr), subject(sbjct), body(body), id(id)
{
}

Message::~Message()
{
}


/* This function is responsible for printing the Message
    * ( whether Topic or Reply) , and and all of the Message's
    * "subtree" recursively:
    * After printing the Message with indentation n and appropriate
    * format ( see output details) , it will invoke itself
    * recursively on all of the Replies in its child_list,
    * incrementing the indentation value at each new level.
    *
    Note: Each indentation increment represents 2 spaces. e. g. if
    * indentation == 1, the reply should be indented 2 spaces, if
    * it' s 2, indent by 4 spaces, etc.
*/
void Message::print(unsigned indentation) const
{
    istringstream parse;
    string body_line;
    int line_num = 0;
    
    string indent ="";
    for (unsigned i = 1; i <= indentation;++i)
    {
        indent += "  ";
    }
    
    if(child_list.size() == 0)
    {
        if(indentation == 0)
        {
            cout << indent << "Message #" << id << ": "<< subject << endl;
            cout << indent << "from " << author << ": ";
            parse.str(body);
            line_num++;
            while(getline(parse, body_line))
            {
                if (line_num == 1)
                {
                    cout << body_line << endl;
                }
                else
                {
                    cout << indent << body_line << endl;
                }
                line_num++;
            }
            //cout << endl;
        }
        else if (indentation > 0)
        {
            cout << indent << "Message #" << id << ": "<< subject << endl;
            cout << indent << "from " << author << ": ";
            parse.str(body);
            line_num++;
            while(getline(parse, body_line))
            {
                if (line_num == 1)
                {
                    cout << body_line << endl;
                }
                else
                {
                    cout << indent << body_line << endl;
                }
                line_num++;
            }
            //cout << endl;
        }
    }
    else if (child_list.size() > 0)
    {
        cout << indent << "Message #" << id << ": "<< subject << endl;
        cout << indent << "from " << author << ": ";
        parse.str(body);
        line_num++;
        while(getline(parse, body_line))
        {
            if (line_num == 1)
            {
                cout << body_line << endl;
            }
            else
            {
                cout << indent << body_line << endl;
            }
            line_num++;
        }
        cout << endl;
        
        for(unsigned i = 0; i < child_list.size(); ++i)
        {
            (child_list.at(i))->print(indentation+1);
            if (i < child_list.size() - 1)
            {
                cout << endl;
            }
        }
    }

    return;
}

const string & Message::get_subject() const
{
    return subject;
}

unsigned Message::get_id() const
{
    return id;
}

void Message::add_child(Message *child)
{
    this->child_list.push_back(child);
}