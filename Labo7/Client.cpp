#include "Client.h"
#include <string>
#include <iostream>
using namespace std;

// Constructeurs / destructeur
Client::Client() : Actor()
{
    setGsm("---");
}

Client::Client(const string& last, const string& first, int id, const string& g)
    : Actor(id, last, first)
{
    setGsm(g);
}

Client::Client(const Client& other) : Actor(other)
{
    setGsm(other.getGsm());
}

Client::~Client() {}

// Setters / Getters
void Client::setGsm(const string& g) 
{ 
    gsm = g; 
}
string Client::getGsm() const 
{ 
    return gsm; 
}

// Opérateur d'affectation
Client& Client::operator=(const Client& other)
{
    if (this != &other)
    {
        Actor::operator=(other);
        setGsm(other.getGsm());
    }
    return *this;
}


string Client::toString() const {
    return "[C" + to_string(getId()) + "] " + getLastName() + " " + getFirstName();
}

string Client::tuple() const {
    return to_string(getId()) + ";" + getLastName() + ";" + getFirstName() + ";" + gsm;
}

// Sérialisation / Désérialisation XML
ostream& operator<<(ostream& os, const Client& c) {
    os << "<Client>" << endl;
    os << "<lastName>" << endl << c.getLastName() << endl << "</lastName>" << endl;
    os << "<firstName>" << endl << c.getFirstName() << endl << "</firstName>" << endl;
    os << "<id>" << endl << c.getId() << endl << "</id>" << endl;
    os << "<gsm>" << endl << c.getGsm() << endl << "</gsm>" << endl;
    os << "</Client>" << endl;
    return os;
}

istream& operator>>(istream& is, Client& c) {
    string line, last, first, gsm;
    int id;

    getline(is, line); // <Client>

    getline(is, line); // <lastName>
    getline(is, last);
    getline(is, line); // </lastName>

    getline(is, line); // <firstName>
    getline(is, first);
    getline(is, line); // </firstName>

    getline(is, line); // <id>
    is >> id;
    is.ignore(); // sauter retour à la ligne
    getline(is, line); // </id>

    getline(is, line); // <gsm>
    getline(is, gsm);
    getline(is, line); // </gsm>

    getline(is, line); // </Client>

    c = Client(last, first, id, gsm);
    return is;
}
