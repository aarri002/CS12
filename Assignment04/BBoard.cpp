#include "User.h"
#include "Message.h"
#include "BBoard.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

BBoard::BBoard()
: title("default-title"), current_user(User("default", "default"))
{
}

BBoard::BBoard(const string &ttl)
: title(ttl), current_user(User("default", "default"))
{
}

void BBoard::setup(const string &input_file)
{
    //------------------------------------------------------------
    //opening input file for reading values    
    ifstream fin;
    fin.open(input_file.c_str());
    if(!fin.is_open()) // is_open() returns true if file is open
    {
        cout << "Error, " << input_file << " did not open correctly"<<endl;
        exit(0); //if inside a function and want to break out of program, you use exit(0); from cstdlib
    }
    
    string uname;
    string pass;
    
    fin >> uname;
    while(uname != "end")
    {
        fin >> pass;
        this->user_list.push_back(User(uname, pass));
        fin >> uname;
    }
    
    fin.close();
    
    return;
}

bool BBoard::user_exists(const string &name, const string &pass)const
{
    for (unsigned i = 0; i < this->user_list.size(); ++i)
    {
        if ((this->user_list).at(i).check(name, pass))
        {
            return true;
        }
    }
    return false;
}

void BBoard::login()
{
    string uname;
    string pass;
    bool validated = false;
    
    cout << "Welcome to " << this->title << " Bulletin Board" << endl;
    cout << "Enter your username ('Q' or 'q' to quit): ";
    cin >> uname;
    while (!(validated))
    {
        if ((uname == "Q") || (uname == "q"))
        {
            cout << "Bye!" << endl;
            exit(0); //Quit if user enters Q or q
        }
        else
        {
            cout << "Enter your password: ";
            cin >> pass;
        }
        
        if(this->user_exists(uname, pass))
        {
            validated = true;
        }
        else
        {
            cout << "Invalid Username or Password!" << endl << endl;
            
            cout << "Enter your username ('Q' or 'q' to quit): ";
            cin >> uname;
        }

    }
    if(validated)
    {
        this->current_user = User(uname, pass);
    }
    return;
}

bool BBoard::logged_in() const
{
    if((current_user.get_username()).size() < 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void BBoard::run()
{
    
    if (this->logged_in())
    {
        string selection;
        bool quit = false;
        
        cout << endl;
        cout << "Menu" << endl;
        cout << "  - Display Messages ('D' or 'd')" << endl;
        cout << "  - Add New Message ('N' or 'n')" << endl;
        cout << "  - Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> selection;
        
        if((selection == "Q") || (selection == "q"))
        {
            quit = true;
        }
        //cout << selection;
        while (!quit)
        {
            if ((selection == "D") || (selection == "d"))
            {
                if (message_list.size() > 0)
                {
                    cout << "-----------------------------------------------" << endl;
                    for(int i =0; i < message_list.size(); ++i)
                    {
                        cout << "Message #" << i+1 << ":";
                        message_list.at(i).display();
                        cout << "-----------------------------------------------" << endl;
                    }
                }
                else
                {
                    cout << endl << "Nothing to Display." << endl << endl;
                }
            }
            if ((selection == "N") || (selection == "n"))
            {
                this->add_message();
                
            }
            cout << "Menu" << endl;
            cout << "  - Display Messages ('D' or 'd')" << endl;
            cout << "  - Add New Message ('N' or 'n')" << endl;
            cout << "  - Quit ('Q' or 'q')" << endl;
            cout << "Choose an action: ";
            cin >> selection;
            if((selection == "Q") || (selection == "q"))
            {
                quit = true;
            }
        }
        
    }
    return;
    
}

void BBoard::add_message()
{
    string subject;
    string body;
    
    cout << "Enter Subject: ";
    getline(cin, subject);
    getline(cin, subject);
    cout << "Enter Body: ";
    getline(cin, body);
    
    message_list.push_back(Message(current_user.get_username(), subject, body));
    
    cout << "Message Recorded!" << endl << endl;
    return;
}















