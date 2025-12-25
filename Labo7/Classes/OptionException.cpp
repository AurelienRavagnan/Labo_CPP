#include "OptionException.h"

OptionException::OptionException(const string& msg) : Exception(msg) {}

OptionException::OptionException(const OptionException& other) : Exception(other) {}

OptionException::~OptionException() {}
