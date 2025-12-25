#ifndef OPTIONEXCEPTION_H
#define OPTIONEXCEPTION_H
#include "Exception.h"
#include <string>
#include <iostream>
using namespace std;

class OptionException: public Exception{
    //private:

    public:
    OptionException();
    OptionException(const string& msg);
    OptionException(const OptionException& other);
    ~OptionException();

};
#endif