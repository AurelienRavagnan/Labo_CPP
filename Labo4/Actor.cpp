#include <string>
#include <iostream>

#include "Actor.h"

// Constructeurs

Actor::Actor() : Person()
{
#ifdef DEBUG
    cout << "Constructeur par defaut Actor" << endl;
#endif
    Id = 0;
}

Actor::Actor(string nom, string prenom, int id)
    : Person(nom, prenom)       // <-- CORRECTION : appel du bon constructeur
{
#ifdef DEBUG
    cout << "Constructeur d'initialisation Actor" << endl;
#endif
    Id = id;
}

Actor::Actor(const Actor& i)
    : Person(i)                 // <-- CORRECTION : copie de Person
{
#ifdef DEBUG
    cout << "Constructeur de copie Actor" << endl;
#endif
    Id = i.Id;
}

// Destructeur
Actor::~Actor()
{
#ifdef DEBUG
    cout << "Destructeur Actor" << endl;
#endif
}

// Set & Get
int Actor::getId() const
{
    return Id;
}

void Actor::setId(int id)
{
    Id = id;
}

// Opérateur =
Actor& Actor::operator=(const Actor& i)
{
#ifdef DEBUG
    cout << "Operateur = Actor" << endl;
#endif
    if (this != &i)
    {
        Person::operator=(i);   // <-- copie Person
        Id = i.Id;
    }
    return *this;
}

// Save
void Actor::save(ofstream& fichier)
{
#ifdef DEBUG
    cout << "Actor : Save" << endl;
#endif

    Person::save(fichier);

    fichier.write((char*)&Id, sizeof(int));
}

// Load
void Actor::load(ifstream& fichier)
{
#ifdef DEBUG
    cout << "Actor : Load" << endl;
#endif

    Person::load(fichier);

    fichier.read((char*)&Id, sizeof(int));
}
