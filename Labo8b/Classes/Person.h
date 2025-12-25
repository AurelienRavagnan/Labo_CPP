#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string lastName;
    string firstName;

public:
    // Constructeurs
    Person();  // par défaut
    Person(const string& last, const string& first);  // initialisation
    Person(const Person& other); // copie

    // Destructeur
    ~Person();

    // Setters
    void setLastName(const string& last);
    void setFirstName(const string& first);

    // Getters
    const string& getLastName() const;
    const string& getFirstName() const;

    Person& operator=(const Person& other);

    friend ostream& operator<<(ostream& os, const Person& p);
    friend istream& operator>>(istream& is, Person& p);
};

#endif
