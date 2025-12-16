#ifndef XMLFILESERIALIZEREXCEPTION_H
#define XMLFILESERIALIZEREXCEPTION_H

#include <string>
#include <iostream>
using namespace std;

class XmlFileSerializerException
{
private:
    int code;
    string message;

public:
    static const int NOT_ALLOWED = 1;
    static const int FILE_NOT_FOUND = 2;
    static const int END_OF_FILE = 3;

    XmlFileSerializerException() : code(0), message("") {}
    XmlFileSerializerException(int c, const string& msg) : code(c), message(msg) {}
    XmlFileSerializerException(const XmlFileSerializerException& e)
        : code(e.code), message(e.message) {}
    ~XmlFileSerializerException() {}

    int getCode() const { return code; }
    string getMessage() const { return message; }

    void display() const {
        cout << "Erreur : " << message << " (code = " << code << ")" << endl;
    }
};

#endif
