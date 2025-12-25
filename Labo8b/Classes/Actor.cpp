#include "Actor.h"
#include <string>
#include <iostream>
using namespace std;

int Actor::currentId = 1;
Actor::Actor() : Person(), id(0) {}


Actor::Actor(int id, const string& last, const string& first): Person(last, first), id(id) {}


Actor::Actor(const Actor& other): Person(other), id(other.id) {}


Actor::~Actor() {}


void Actor::setId(int newId) {
    id = newId;
}


int Actor::getId() const {
    return id;
}

Actor& Actor::operator=(const Actor& other) {
    if (this != &other) {
        Person::operator=(other); // appelle l’opérateur= de Person
        id = other.id;
    }
    return *this;
}