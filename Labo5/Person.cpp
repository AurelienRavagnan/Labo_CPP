#include <iostream>
#include "Person.h"



//-------------------------------------------------------
// Constructeurs
//-------------------------------------------------------

Person::Person()
{
    setLastName("---");
    setFirstName("---");
}


Person::Person(const string& last, const string& first)
{
    setLastName(last);
    setFirstName(first);
}


Person::Person(const Person& other)
{
    setLastName(other.getLastName());
    setFirstName(other.getFirstName());
}


//-------------------------------------------------------
// Destructeur
//-------------------------------------------------------

Person::~Person() {}

//-------------------------------------------------------
// Getters / Setters
//-------------------------------------------------------

void Person::setLastName(const string& last) {
    lastName = last;
}

void Person::setFirstName(const string& first) {
    firstName = first;
}

const string& Person::getLastName() const {
    return lastName;
}

const string& Person::getFirstName() const {
    return firstName;
}

//-------------------------------------------------------
// Opérateur =
//-------------------------------------------------------

Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        setLastName(other.getLastName());
        setFirstName(other.getFirstName());
    }
    return *this;
}

//-------------------------------------------------------
// Opérateur <<
//-------------------------------------------------------

ostream& operator<<(ostream& os, const Person& p) {
    os << p.firstName << " " << p.lastName;
    return os;
}

//-------------------------------------------------------
// Opérateur >>
//-------------------------------------------------------

istream& operator>>(istream& is, Person& p) {
    cout << "Entrez le prénom : ";
    is >> p.firstName;
    cout << "Entrez le nom : ";
    is >> p.lastName;
    return is;
}