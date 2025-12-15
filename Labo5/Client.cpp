#include <string>
#include <iostream>

#include "Client.h"

// Constructeurs
Client::Client() : Actor(), gsm("---") {}

Client::Client(const string& last, const string& first, int id, const string& gsm) : Actor(id, last, first), gsm(gsm) {}
Client::Client(const Client& other) : Actor(other), gsm(other.gsm) {}

// Destructeur
Client::~Client() {}

// Get / Set
void Client::setGsm(const string& g) { gsm = g; }
string Client::getGsm() const { return gsm; }

// Opérateur =
Client& Client::operator=(const Client& other) {
    if (this != &other) {
        Actor::operator=(other); // copie la partie héritée
        gsm = other.gsm;         // copie spécifique à Client
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