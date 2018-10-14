//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment07/BBoard.h
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
#ifndef __BBOARD_H__
#define __BBOARD_H__

#include "User.h"
#include "Message.h"
#include "Topic.h"
#include "Reply.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


class BBoard
{
    private:
        string title;
        vector<User> user_list;
        const User *current_user;
        vector<Message *> message_list;
    public:
        BBoard();
        BBoard(const string &ttl);
        ~BBoard();
        bool load_users(const string &userfile);
        bool load_messages(const string &datafile);
        bool save_messages(const string &datafile);
        void login();
        void run();
        void display() const;
    private:
        //void add_user(const string &name, const string &pass);
        // const User *get_user(const string &name, const string &pw) const;
        void add_topic();
        void add_reply();
        bool logged_in() const;
};

#endif