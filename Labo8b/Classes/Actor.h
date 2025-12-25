#ifndef ACTOR_H
#define ACTOR_H

#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

class Actor : public Person{
    protected:
    int id;

    public:
    static int currentId; 
    Actor();
    Actor(int id, const string& last, const string& first);
    Actor(const Actor& other);

    //le destructeur est virtual car la classe va être héritée x fois ducoup si on le rend pas virtual uniquement le destructeur des classes héritées sera appelé
    virtual ~Actor();

    void setId(int newId);
    int getId() const;

    // Méthodes virtuelles pures
    virtual string tuple() const = 0;
    virtual string toString() const = 0;

    Actor& operator=(const Actor& other);
};

#endif