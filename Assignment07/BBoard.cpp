//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment07/BBoard.cpp
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
#include "User.h"
#include "Message.h"
#include "Topic.h"
#include "Reply.h"
#include "BBoard.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

BBoard::BBoard()
: title("default-title"), current_user(0)
{
}

BBoard::BBoard(const string &ttl)
: title(ttl), current_user(0)
{
}

BBoard::~BBoard()
{
    for (unsigned i = 0; i < message_list.size(); i++)
    {
        delete message_list.at(i);
    }
}

bool BBoard::load_users(const string &userfile)
{
    //------------------------------------------------------------
    //opening input file for reading values    
    ifstream fin;
    fin.open(userfile.c_str());
    if(!fin.is_open()) // is_open() returns true if file is open
    {
        cout << "Error, " << userfile << " did not open correctly"<<endl;
        return false; //if inside a function and want to break out of program, you use exit(0); from cstdlib
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
    
    return true;
}

bool BBoard::load_messages(const string &datafile)
{
    //vector<Message *> message_list;
    vector<string> children_lists;
    string discard;
    string lineString;
    int id;
    int number_of_messages = 0;
    string subject = "";
    string author = "";
    string child_id_string = "";
    string body = "";
    string type_of_message = "";
    stringstream iss;
    
    //------------------------------------------------------------
    //opening input file for reading values    
    ifstream fin;
    fin.open(datafile.c_str());
    if(!fin.is_open()) // is_open() returns true if file is open
    {
        cout << "Error, " << datafile << " did not open correctly"<<endl;
        return false; //if inside a function and want to break out of program, you use exit(0); from cstdlib
    }
    //------------------------------------------------------------

    //------------------------------------------------------------
    //Parsing for topic messages
    iss.clear();
    getline(fin, lineString); //Get first line
    iss.str(lineString);
    iss >> number_of_messages; //Get number of messages
    for (int i = 1; i <= number_of_messages; ++i)
    {
        getline(fin, lineString);
        type_of_message = lineString; //Get message Type
        //cout << "Type of Message: " << type_of_message << endl;
        fin >> discard; //discard :id: tag
        getline(fin, lineString);
        iss.clear();
        iss.str(lineString);
        iss >> id; //Get id number
        fin >> discard; //discard :subject: tag
        getline(fin, lineString);
        subject = lineString.substr(1, lineString.size()-1); //Get subject line
        fin >> discard; //discard :from: tag
        getline(fin, lineString);
        author = lineString.substr(1, lineString.size()-1); //Get author line
        fin >> discard;
        getline(fin, lineString);
        if (discard == ":children:")
        {
            child_id_string = lineString.substr(1, lineString.size()-1) + "";
            //cout << "Child id String is:" << child_id_string << endl; 
            fin >> discard;
            getline(fin, lineString);
        }
        else
        {
            child_id_string = "";
            //cout << "Child id String is:" << child_id_string << endl;
        }
        body = lineString.substr(1, lineString.size()-1); //Get body line
        getline(fin, lineString);
        while (lineString != "<end>") //Get rest of body if more
        {
            body += "\n" + lineString;
            getline(fin, lineString);
        }
        
        if(type_of_message == "<begin_topic>")
        {
            Topic *message = new Topic(author, subject, body, id);
            message_list.push_back(message);
            //cout << "Added Topic" << endl;
        }
        
        if(type_of_message == "<begin_reply>")
        {
            Reply *message = new Reply(author, subject, body, id);
            message_list.push_back(message);
            //cout << "Added Reply" << endl;
        }
        
        children_lists.push_back(child_id_string);
    }
    
    fin.close();
    //------------------------------------------------------------
    
    //------------------------------------------------------------
    //Parsing for children
    for(unsigned i = 0; i < message_list.size(); ++i)
    {
        iss.clear();
        int child_id;
        child_id_string = children_lists.at(i);
        //cout << "Children List "<< i << ": " << child_id_string << endl;
        
        iss.str(child_id_string);
        while (iss >> child_id)
        {
            //cout << "Child Id Added: " << child_id;
            (message_list.at(i))->add_child(message_list.at(child_id-1));
        }
        //cout << endl;
    }
    //------------------------------------------------------------
    
    return true;
}

bool BBoard::save_messages(const string &datafile)
{
    //Testing Formatted String output to File
    ofstream fout;
    
    // Open file
    fout.open(datafile.c_str());
   
    if (!fout.is_open())
    {
        cout << "Error, " << datafile << " did not open correctly"<<endl;
        return false; //if inside a function and want to break out of program, you use exit(0); from cstdlib
    }
    
    fout << message_list.size() << endl;
    for (unsigned i = 0; i < message_list.size(); ++i)
    {
        fout << (message_list.at(i))->to_formatted_string();
    }
    //------------------------------------------------------------ 
    
    return true;
}

void BBoard::display() const
{
    //------------------------------------------------------------    
    //Display all topics
    for (unsigned i = 0; i < message_list.size(); ++i)
    {
        if (!(message_list.at(i)->is_reply()))
        {
            cout << "------------------------------------------------------------" << endl;
            (message_list.at(i))->print(0); 
        }
    }
    cout << "------------------------------------------------------------" << endl;
    //------------------------------------------------------------
    
    return;
}

void BBoard::login()
{
    string uname;
    string pass;
    int user_index = -1;
    bool validated = false;
    
    cout << "Welcome to " << this->title << " Bulletin Board" << endl;
    cout << "Enter your username ('Q' or 'q' to quit): ";
    cin >> uname;
    while (!(validated))
    {
        if ((uname == "Q") || (uname == "q"))
        {
            cout << "Bye!" << endl;
            return; //Quit if user enters Q or q
        }
        else
        {
            cout << "Enter your password: ";
            cin >> pass;
        }
        
        for (unsigned i = 0; i < this->user_list.size(); ++i)
        {
            if ((this->user_list).at(i).check(uname, pass))
            {
                user_index = i;
            }
        }
            
        if(user_index != -1)
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
        current_user = &(user_list.at(user_index));
    }
    
    //Seeing what user was validated
    cout << "Current User Validated: " << current_user->get_username() << endl;
    return;
}

bool BBoard::logged_in() const
{
    if(current_user == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
    return false;
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
        cout << "  - Add New Topic ('N' or 'n')" << endl;
        cout << "  - Add Reply ('R' or 'r')" << endl;
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
                    this->display();
                }
                else
                {
                    cout << endl << "Nothing to Display." << endl << endl;
                }
            }
            if ((selection == "N") || (selection == "n"))
            {
                this->add_topic();
                
            }
            if ((selection == "R") || (selection == "r"))
            {
                this->add_reply();
                
            }
            cout << "Menu" << endl;
            cout << "  - Display Messages ('D' or 'd')" << endl;
            cout << "  - Add New Topic ('N' or 'n')" << endl;
            cout << "  - Add Reply ('R' or 'r')" << endl;
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

void BBoard::add_topic()
{
    string subject;
    string discard;
    string body_line;
    ostringstream body_composition;
    string body;
    
    cout << "Enter Subject: ";
    getline(cin, discard);
    getline(cin, subject);
    cout << "Enter Body: ";
    getline(cin, body_line);
    while(body_line != "")
    {
        body_composition << body_line << "\n";
        getline(cin, body_line);
    }
    body = (body_composition.str());
    body = body.substr(0, body.size() -1);
    
    
    Topic *new_topic = new Topic(current_user->get_username(), subject, body, message_list.size()+1);
    message_list.push_back(new_topic);
    
    cout << "Message Recorded!" << endl << endl;
    return;
}

void BBoard::add_reply()
{
    string subject = "Re: ";
    string discard;
    string body_line;
    int entered_id;
    int size = message_list.size();
    ostringstream body_composition;
    string body;
    
    cout << "Enter Message ID (-1 for Menu): ";
    cin >> entered_id;
    if (entered_id == -1)
    {
        return;
    }
    while((entered_id > size) || (entered_id < -1))
    {
        cout << "Invalid Message ID!!" << endl << endl;
        cout << "Enter Message ID (-1 for Menu): ";
        cin >> entered_id;
        
        if (entered_id == -1)
        {
            return;
        }
    }
    
    getline(cin, discard);
    cout << "Enter Body: ";
    getline(cin, body_line);
    while(body_line != "")
    {
        body_composition << body_line << "\n";
        getline(cin, body_line);
    }
    body = (body_composition.str());
    body = body.substr(0, body.size() -1);
    
    subject += (message_list.at(entered_id-1))->get_subject();
    Reply *new_reply = new Reply(current_user->get_username(), subject, body, message_list.size()+1);
    
    (message_list.at(entered_id-1))->add_child(new_reply);
    
    message_list.push_back(new_reply);
    
    cout << "Message Recorded!" << endl << endl;
    return;
}
















