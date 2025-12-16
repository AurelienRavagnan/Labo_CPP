#include "Employee.h"
#include "PasswordException.h"
#include <string>
#include <iostream>
using namespace std;

const string Employee::SELLER = "Vendeur";
const string Employee::ADMINISTRATIVE = "Administratif";

Employee::Employee() : Actor()
{
    setLogin("");
    resetPassword();
    setRole("");
}


Employee::Employee(const string& last, const string& first, int id,
                   const string& l, const string& r)
    : Actor(id, last, first)
{
    setLogin(l);
    resetPassword();
    setRole(r);
}


Employee::Employee(const Employee& other) : Actor(other)
{
    setLogin(other.getLogin());
    setRole(other.getRole());

    if (other.password)
        setPassword(other.getPassword());
    else
        resetPassword();
}


Employee::~Employee() {
    delete password;
}

string Employee::getLogin() const { return login; }
void Employee::setLogin(const string& login) { this->login = login; }
string Employee::getRole() const { return role; }
void Employee::setRole(const string& role) { this->role = role; }
string Employee::getPassword() const { return password ? *password : ""; }

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

Employee& Employee::operator=(const Employee& other)
{
    if (this != &other)
    {
        Actor::operator=(other);

        setLogin(other.getLogin());
        setRole(other.getRole());

        if (other.password)
            setPassword(other.getPassword());
        else
            resetPassword();
    }
    return *this;
}

string Employee::toString() const {
    string prefix = (role == SELLER) ? "[V" : "[A";
    return prefix + to_string(getId()) + "] " + getLastName() + " " + getFirstName();
}

string Employee::tuple() const {
    return to_string(getId()) + ";" + getLastName() + ";" + getFirstName() + ";" + role;
}

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
