#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Person
{
    friend ostream& operator<<(ostream& s, const Person& p);
    friend istream& operator>>(istream& s, Person& p);

protected:
    string lastName;
    string firstName;

public:
    // Constructeurs
    Person();
    Person(const string& nom, const string& prenom);
    Person(const Person& p);

    // Destructeur
    ~Person();

    // Getters / Setters conformes à l'exercice Essai1
    string getLastName() const;
    string getFirstName() const;

    void setLastName(const string& s);
    void setFirstName(const string& s);

    // Opérateur d'affectation =
    Person& operator=(const Person& other);

    // Fonctions fichiers
    void save(ofstream& fichier);
    void load(ifstream& fichier);
};

#endif
