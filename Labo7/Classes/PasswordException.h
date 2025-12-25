#ifndef PASSWORDEXCEPTION_H
#define PASSWORDEXCEPTION_H

#include <iostream>
#include <string>
#include "Exception.h"


class PasswordException : public Exception{
    private:
    int code;

    public:
    PasswordException();
    PasswordException(const string& msg = "", int c = 0);
    PasswordException(const PasswordException& other);

    virtual ~PasswordException();

    int getCode() const;

    string getMessage() const; //je redéfinis getMessage parce que par rapport à optionexcpetion on déclare un code en plus 

    static const int INVALID_LENGTH = 1;
    static const int ALPHA_MISSING  = 2;
    static const int DIGIT_MISSING  = 3;
    static const int NO_PASSWORD    = 4;

};
#endif