#include "PasswordException.h"
#include <sstream>

PasswordException::PasswordException(const string& msg, int c)
    : Exception(msg), code(c) {}

PasswordException::PasswordException(const PasswordException& other)
    : Exception(other), code(other.code) {}

PasswordException::~PasswordException() {}

int PasswordException::getCode() const {
    return code;
}

string PasswordException::getMessage() const {
    ostringstream oss;//permet de construire une chaine de caractère comme si j'écrivais dans un flux 
    oss << Exception::getMessage() << " (code: " << code << ")";
    return oss.str();
}
