#include "Actor.h"
#include <string>
#include <iostream>
using namespace std;


Actor::Actor() : Person()
{
    setId(0);
}

Actor::Actor(int id, const string& last, const string& first)
    : Person(last, first)
{
    setId(id);
}

Actor::Actor(const Actor& other)
    : Person(other)
{
    setId(other.getId());
}


Actor::~Actor() {}


void Actor::setId(int newId) {
    id = newId;
}


int Actor::getId() const {
    return id;
}

Actor& Actor::operator=(const Actor& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        setId(other.getId());
    }
    return *this;
}