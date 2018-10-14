//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment07/User.cpp
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

#include <string>
#include "User.h"

using namespace std;

User::User()
: username(""), password("")
{
}

User::User(const string &uname, const string &pass)
: username(uname), password(pass)
{
}

string User::get_username() const
{
    return this->username;
}

bool User::check(const string &uname, const string &pass) const
{
    if (uname.size() <= 0)
    {
        return false;
    }
    if((this->username == uname) && (this->password == pass))
    {
        return true;
    }
    
    return false;
}

void User::set_password(const string &newpass)
{
    password = newpass;
    return;
}