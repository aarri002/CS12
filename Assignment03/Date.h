#include <string>
using namespace std;

class Date
{
    private:
        unsigned day;
        unsigned month;
        string monthName;
        unsigned year;
    public:
        Date(); //Default constructor, initializes variables to date January 1st, 2000
        Date(unsigned m, unsigned d, unsigned y); //innitializes variables month number, year...
                                                //Will correct date if arguments are invalid to closest correct date
        Date(const string &nm, unsigned d, unsigned y); //parameterized constructor: month name, day, year e.g.
                                                        //(December, 15, 2012) would construct the date December 15th, 2012
        void printNumeric() const; //const accessor function to output a Date exactly in the format "3/1/2012".
                                    //Do not output a newline (endl) at the end
        void printAlpha() const; //const accessor function to output a Date exactly in the format "March 1, 2012". The first
                                //letter of the month name is upper case, and the month name is printed in full so Jan, january,
                                //jan are not valid formats.
                                //Do not output a newline (endl) at the end
    private:
        bool isLeap(unsigned) const;
        unsigned daysPerMonth(unsigned m, unsigned y) const;
        string name(unsigned m) const;
        unsigned number(const string &mn) const;
};