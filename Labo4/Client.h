#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <fstream>

#include "Person.h"
#include "Actor.h"

using namespace std;

class Client : public Actor
{
    friend ostream& operator<<(ostream& s,const Client& c);

private:
    string gsm;

public:

    // Constructeurs
    Client();
    Client(string nom, string prenom, int n, string g);
    Client(const Client& p);

    // Destructeur
    ~Client();

    // get/set du champ PROPRE à Client
    void setGsm(string g);
    string getGsm() const;

    // get/set de l’ID (hérité d’Actor)
    void setId(int n);        // <-- DOIT utiliser setNumero()
    int getId() const;        // <-- DOIT utiliser getNumero()

    // Opérateur =
    Client& operator=(const Client& c);

    // Fonctions
    string toString() const override;
    string tuple() const override;

    void save(ofstream& fichier);
    Client& load(ifstream& fichier);
};

#endif
