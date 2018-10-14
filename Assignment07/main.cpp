//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment07/main.cpp 
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

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Message.h"
#include "Topic.h"
#include "Reply.h"
#include "User.h"
#include "BBoard.h"

using namespace std;

int main (int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "ERROR: Invalid program call." << endl;
        cout << "Usage: <program_name> userfile datafile" << endl;
        return 1;
    }
    string userfile(argv[1]);
    string datafile(argv[2]);
    
    BBoard bb("CS12 Bulletin Board");
    
    //load users from file
    if(!bb.load_users(userfile))
    {
        cout << "ERROR: Cannot load users from " << userfile << endl;
        return 1;
    }
    
    //load messages
    if (!bb.load_messages(datafile))
    {
        cout << "ERROR: Cannot load messages from " << datafile << endl;
        return 1;
    }
    
    bb.login();
    bb.run();
    
    //save messages
    if(!bb.save_messages(datafile))
    {
        cout << "ERROR: Cannot save messages to " << datafile << endl;
        return 1;
    }
    
    return 0;
}