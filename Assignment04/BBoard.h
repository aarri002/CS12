#ifndef __BBOARD_H__
#define __BBOARD_H__

#include "User.h"
#include "Message.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class BBoard
{
    private:
        string title;
        vector<User> user_list;
        User current_user;
        vector<Message> message_list;
    public:
        BBoard();
        BBoard(const string &ttl);
        void setup(const string &input_file);
        void login();
        void run();
    private:
        bool user_exists(const string &name, const string &pass) const;
        bool logged_in() const;
        void add_message();
};

#endif