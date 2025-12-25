#include "Exception.h"
#include <string>
#include <iostream>
using namespace std;

Exception::Exception(const string& msg) : message(msg) {}

Exception::Exception(const Exception& other) : message(other.message) {}

Exception::~Exception() {}

string Exception::getMessage() const {
    return message;
}

ostream& operator<<(ostream& os, const Exception& e) {
    os << e.getMessage();
    return os;
}
