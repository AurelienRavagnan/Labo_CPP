#include <iostream>
#include <fstream>
#include <string>

#include "Employee.h"
#include "Actor.h"

using namespace std;

const string Employee::ADMINISTRATIVE = "Administratif";
const string Employee::SELLER = "Vendeur";

// =======================
//  CONSTRUCTEURS
// =======================

Employee::Employee() : Actor()
{
    login = "";
    Password = new string("");
    role = "";
}

Employee::Employee(string nom, string prenom, int n, string l, string r)
    : Actor(nom, prenom, n)
{
    login = l;
    Password = new string("");
    role = r;
}

Employee::Employee(const Employee& e)
    : Actor(e)
{
    login = e.login;
    Password = new string(*(e.Password));
    role = e.role;
}

// =======================
//  DESTRUCTEUR
// =======================

Employee::~Employee()
{
    delete Password;
}

// =======================
//     SETTERS
// =======================

void Employee::setLogin(string l)
{
    login = l;
}

void Employee::setPassword(string p)
{
    *Password = p;
}

void Employee::resetPassword()
{
    *Password = "";
}

void Employee::setRole(string r)
{
    role = r;
}

// =======================
//     GETTERS
// =======================

string Employee::getLogin() const
{
    return login;
}

string Employee::getPassword() const
{
    return *Password;
}

string Employee::getRole() const
{
    return role;
}

// =======================
//   OPERATEUR =
// =======================

Employee& Employee::operator=(const Employee& e)
{
    if (this == &e) return *this;

    Actor::operator=(e);

    login = e.login;
    *Password = *(e.Password);
    role = e.role;

    return *this;
}

// =======================
//  AFFICHAGE
// =======================

ostream& operator<<(ostream& s, const Employee& e)
{
    s << "Nom        : " << e.getLastName() << endl;
    s << "Prénom     : " << e.getFirstName() << endl;
    s << "Numéro     : " << e.getId() << endl;
    s << "Login      : " << e.getLogin() << endl;
    s << "Mot de passe : " << e.getPassword() << endl;
    s << "Fonction   : " << e.getRole() << endl;

    return s;
}

// =======================
//  ToString()
// =======================

string Employee::toString() const
{
    return "[" + string(1, role[0])
           + to_string(getId()) + "] "
           + getLastName() + " " + getFirstName();
}

// =======================
//  Tuple()
// =======================

string Employee::tuple() const
{
    return to_string(getId()) + ";"
         + getLastName() + ";"
         + getFirstName() + ";"
         + login + ";"
         + role;
}

// =======================
//  SAVE()
// =======================

void Employee::Save(ofstream& fichier)
{
    if (!fichier) return;

    // ===== Actor =====
    int num = getId();
    fichier.write((char*)&num, sizeof(int));

    int tailleNom = getLastName().size() + 1;
    fichier.write((char*)&tailleNom, sizeof(int));
    fichier.write(getLastName().c_str(), tailleNom);

    int taillePrenom = getFirstName().size() + 1;
    fichier.write((char*)&taillePrenom, sizeof(int));
    fichier.write(getFirstName().c_str(), taillePrenom);

    // ===== Employee =====

    int tailleLogin = login.size() + 1;
    fichier.write((char*)&tailleLogin, sizeof(int));
    fichier.write(login.c_str(), tailleLogin);

    int tailleMot = Password->size() + 1;
    fichier.write((char*)&tailleMot, sizeof(int));
    fichier.write(Password->c_str(), tailleMot);

    int tailleRole = role.size() + 1;
    fichier.write((char*)&tailleRole, sizeof(int));
    fichier.write(role.c_str(), tailleRole);
}

// =======================
//  LOAD()
// =======================

Employee& Employee::Load(ifstream& fichier)
{
    if (!fichier) return *this;

    // ===== Actor =====

    int num;
    fichier.read((char*)&num, sizeof(int));
    setId(num);

    int tailleNom;
    fichier.read((char*)&tailleNom, sizeof(int));
    char* bufferNom = new char[tailleNom];
    fichier.read(bufferNom, tailleNom);
    setLastName(bufferNom);
    delete[] bufferNom;

    int taillePrenom;
    fichier.read((char*)&taillePrenom, sizeof(int));
    char* bufferPrenom = new char[taillePrenom];
    fichier.read(bufferPrenom, taillePrenom);
    setFirstName(bufferPrenom);
    delete[] bufferPrenom;

    // ===== Employee =====

    int tailleLogin;
    fichier.read((char*)&tailleLogin, sizeof(int));
    char* bufferLogin = new char[tailleLogin];
    fichier.read(bufferLogin, tailleLogin);
    login = bufferLogin;
    delete[] bufferLogin;

    int tailleMot;
    fichier.read((char*)&tailleMot, sizeof(int));
    char* bufferMot = new char[tailleMot];
    fichier.read(bufferMot, tailleMot);
    *Password = bufferMot;
    delete[] bufferMot;

    int tailleRole;
    fichier.read((char*)&tailleRole, sizeof(int));
    char* bufferF = new char[tailleRole];
    fichier.read(bufferF, tailleRole);
    role = bufferF;
    delete[] bufferF;

    return *this;
}
