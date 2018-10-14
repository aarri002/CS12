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