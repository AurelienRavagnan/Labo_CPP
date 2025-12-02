#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <fstream>
#include "Actor.h"
#include "Person.h"

using namespace std;

class Employee : public Actor
{
    friend ostream& operator<<(ostream& s, const Employee& e);

private:
    string login;
    string* Password;
    string role;

public:
    static const string ADMINISTRATIVE;
    static const string SELLER;

    // Constructeurs
    Employee();
    Employee(string nom, string prenom, int n, string l, string r);
    Employee(const Employee& e);

    // Destructeur
    ~Employee();

    // Setters
    void setLogin(string l);
    void setPassword(string m);
    void resetPassword();
    void setRole(string r);

    // Getters
    string getLogin() const;
    string getPassword() const;
    string getRole() const;

    // Opérateur =
    Employee& operator=(const Employee& e);

    // Fonctions
    string toString() const;
    string tuple() const;

    void Save(ofstream& fichier);
    Employee& Load(ifstream& fichier);
};

#endif
