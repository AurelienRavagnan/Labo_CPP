#include <string>
#include <iostream>

#include "Actor.h"

// Constructeurs

Actor::Actor() : Person(), id(0) {}


Actor::Actor(int id, const string& last, const string& first): Person(last, first), id(id) {}


Actor::Actor(const Actor& other): Person(other), id(other.id) {}


// Destructeur
Actor::~Actor() {}


// Set & Get
void Actor::setId(int newId) {
    id = newId;
}


int Actor::getId() const {
    return id;
}

// Opérateur =
Actor& Actor::operator=(const Actor& other) {
    if (this != &other) {
        Person::operator=(other); // appelle l’opérateur= de Person
        id = other.id;
    }
    return *this;
}