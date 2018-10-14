#include <iostream>
#include "Message.h"
#include "User.h"
#include "BBoard.h"
//#include <string>
//#include <vector>
//#include <fstream>
//include <cstdlib>

using namespace std;

int main (int argc, char *argv[])
{
    BBoard bb = BBoard("Football");
    bb.setup(argv[1]);
    bb.login();
    bb.run();
    
    return 0;
}