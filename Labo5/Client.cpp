#include <string>
#include <iostream>

#include "Client.h"

// Constructeurs
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
// Destructeur
Client::~Client() {}

// Get / Set
void Client::setGsm(const string& g) { gsm = g; }
string Client::getGsm() const { return gsm; }

// Opérateur =
Client& Client::operator=(const Client& other)
{
    if (this != &other)
    {
        Actor::operator=(other);
        setGsm(other.getGsm());
    }
    return *this;
}


// Affichage
ostream& operator<<(ostream& os, const Client& c) {
    os << c.toString();
    return os;
}

istream& operator>>(istream& is, Client& c) {
    string last, first, gsm;
    int id;

    cout << "ID: ";
    is >> id;
    cout << "Nom: ";
    is >> last;
    cout << "Prenom: ";
    is >> first;
    cout << "GSM: ";
    is >> gsm;

    c = Client(last,first,id,gsm);
    return is;
}

// ToString
string Client::toString() const {
    return "[C" + to_string(getId()) + "] " + getLastName() + " " + getFirstName();
}



// Tuple
string Client::tuple() const {
    return to_string(getId()) + ";" + getLastName() + ";" + getFirstName() + ";" + gsm;
}