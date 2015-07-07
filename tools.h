#ifndef tools_header
#define tools_header

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <time.h>

namespace tools
{

/*----------------------------------------
       ***************************
       |  Trim String Function   |
       ***************************
Trim whitespace from a string
------------------------------------------*/
inline extern std::string trim (std::string line)
{
    std::string trimmed_line;
    unsigned int first = line.find_first_not_of(" \t\r\n\x0b");
    unsigned int last = line.find_last_not_of(" \t\r\n\x0b") + 1;


    last = last - first;

    //Check for string of blanks and set default to blank
    int length = (int)line.length();
    int cntr = 0;
    for (int i=0; i<length; ++i)
    {
        std::string test = line.substr(i,1);
        if(test.find_first_of(" \t\r\n\x0b")==0)
        {
            ++cntr;
        }
    }

    //Trim spaces from front and end of line
    if (line.length() == 0 || (length - cntr) == 0)
    {
        trimmed_line = "";
    }
    else
    {
        trimmed_line = line.substr(first,last);
    }

    return trimmed_line;
};

/*----------------------------------------
       ***************************
       |    Command Execution    |
       ***************************
------------------------------------------*/
inline extern std::string exec(std::string cmd)
{
    //cout << "EXEC: " << cmd << endl;
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "ERROR";
    char buffer[4000];
    std::string result = "";
    while(!feof(pipe))
    {
        if(fgets(buffer, 4000, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
};

};
#endif

