#include <iostream>
#include <fstream>
#include <string>

#include "Employee.h"
#include "Actor.h"
#include "PasswordException.h"

using namespace std;

const string Employee::ADMINISTRATIVE = "Administratif";
const string Employee::SELLER = "Vendeur";

// =======================
//  CONSTRUCTEURS
// =======================

Employee::Employee() : Actor(), login(""), password(nullptr), role("") {}

Employee::Employee(const string& last, const string& first, int id,
                   const string& login, const string& role)
    : Actor(id, last, first), login(login), password(nullptr), role(role) {}

Employee::Employee(const Employee& other) : Actor(other), login(other.login), role(other.role) {
    if (other.password)
        password = new string(*other.password);
    else
        password = nullptr;
}

// =======================
//  DESTRUCTEUR
// =======================

Employee::~Employee() {
    delete password;
}

// =======================
//     SETTERS
// =======================

void Employee::setLogin(const string& login) { this->login = login; }

void Employee::setRole(const string& role) { this->role = role; }

void Employee::setPassword(const string& mdp) {
    if (mdp.length() < 6)
        throw PasswordException("Mot de passe trop court", PasswordException::INVALID_LENGTH);

    bool hasLetter = false, hasDigit = false;
    for (char c : mdp) {
        if (isalpha(c)) hasLetter = true; // parcourt char par char et vérifie s'il le char et soit une lettre soit un chiffre sinon lance l'exception 
        if (isdigit(c)) hasDigit = true;
    }
    if (!hasLetter)
        throw PasswordException("Mot de passe doit contenir au moins une lettre", PasswordException::ALPHA_MISSING);
    if (!hasDigit)
        throw PasswordException("Mot de passe doit contenir au moins un chiffre", PasswordException::DIGIT_MISSING);

    delete password;
    password = new string(mdp);
}
void Employee::resetPassword() {
    delete password;
    password = nullptr;
}

// =======================
//     GETTERS
// =======================

string Employee::getLogin() const { return login; }

string Employee::getRole() const { return role; }

string Employee::getPassword() const { return password ? *password : ""; }

// =======================
//   OPERATEUR =
// =======================

Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        Actor::operator=(other);
        login = other.login;
        role = other.role;
        delete password;
        if (other.password)
            password = new string(*other.password);
        else
            password = nullptr;
    }
    return *this;
}

// =======================
//  AFFICHAGE
// =======================

ostream& operator<<(ostream& os, const Employee& e) {
    os << e.toString();
    return os;
}

istream& operator>>(istream& is, Employee& e) {
    string last, first, login, role;
    cout << "Nom : ";
    is >> last;
    cout << "Prenom : ";
    is >> first;
    cout << "Login : ";
    is >> login;
    cout << "Role (" << Employee::SELLER << "/" << Employee::ADMINISTRATIVE << ") : ";
    is >> role;
    e.setLastName(last);
    e.setFirstName(first);
    e.setLogin(login);
    e.setRole(role);
    return is;
}


// =======================
//  ToString()
// =======================

string Employee::toString() const {
    string prefix = (role == SELLER) ? "[V" : "[A";
    return prefix + to_string(getId()) + "] " + getLastName() + " " + getFirstName();
}

// =======================
//  Tuple()
// =======================

string Employee::tuple() const {
    return to_string(getId()) + ";" + getLastName() + ";" + getFirstName() + ";" + role;
}