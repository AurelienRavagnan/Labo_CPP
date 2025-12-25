#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <iostream>
using namespace std;

class Exception {
private:
    string message;

public:
    Exception(const string& msg = ""); // indique que si dans le throw on met pas de param ça prendra la valeur par défaut ""
    Exception(const Exception& other);

    virtual ~Exception();

    string getMessage() const;

    friend ostream& operator<<(ostream& os, const Exception& e);
};

#endif
