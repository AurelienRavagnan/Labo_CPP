#include <string>
#include <iostream>

#include "Client.h"
#include "Actor.h"

// Constructeurs
Client::Client() : Actor()
{
#ifdef DEBUG
    cout << "Constructeur par defaut de Client" << endl;
#endif
    gsm = "0400/00.00.00";
}

Client::Client(string nom, string prenom, int n, string g)
    : Actor(nom, prenom, n)
{
#ifdef DEBUG
    cout << "Constructeur d'initialisation de Client" << endl;
#endif
    gsm = g;
}

Client::Client(const Client& c)
    : Actor(c)   // copie Person + Actor
{
#ifdef DEBUG
    cout << "Constructeur de copie de Client" << endl;
#endif
    gsm = c.gsm;
}

// Destructeur
Client::~Client()
{
#ifdef DEBUG
    cout << "Destructeur de Client" << endl;
#endif
}

// Get / Set
void Client::setGsm(string g)
{
    gsm = g;
}

string Client::getGsm() const
{
    return gsm;
}

void Client::setId(int n)
{
    setId(n);   // <-- CORRECT
}

int Client::getId() const
{
    return getId(); // <-- CORRECT
}

// Opérateur =
Client& Client::operator=(const Client& c)
{
    if (this != &c)
    {
        Actor::operator=(c);   // copie nom, prenom, numero
        gsm = c.gsm;
    }
    return *this;
}

// Affichage
ostream& operator<<(ostream& s, const Client& c)
{
    s << "Nom    : " << c.getLastName() << endl;
    s << "Prenom : " << c.getFirstName() << endl;
    s << "Id     : " << c.getId() << endl;
    s << "GSM    : " << c.getGsm() << endl;
    return s;
}

// ToString
string Client::toString() const
{
    return "[C" + to_string(getId()) + "] " +
           getLastName() + " " + getFirstName();
}

// Tuple
string Client::tuple() const
{
    return to_string(getId()) + ";" +
           getLastName() + ";" +
           getFirstName() + ";" +
           gsm;
}

// Sauvegarde
void Client::save(ofstream& fichier)
{
#ifdef DEBUG
    cout << "Client : Save" << endl;
#endif

    Actor::save(fichier);

    int taille = gsm.size();
    fichier.write((char*)&taille, sizeof(int));
    fichier.write(gsm.data(), taille);
}

// Chargement
Client& Client::load(ifstream& fichier)
{
#ifdef DEBUG
    cout << "Client : Load" << endl;
#endif

    Actor::load(fichier);

    int taille;
    fichier.read((char*)&taille, sizeof(int));
    gsm.resize(taille);
    fichier.read((char*)gsm.data(), taille);

    return *this;
}
