#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include "Actor.h"
using namespace std;

class Client : public Actor {
private:
    string gsm;

public:
    // Constructeurs & destructeur
    Client();
    Client(const string& last, const string& first, int id, const string& gsm);
    Client(const Client& other);
    virtual ~Client();

    // Setters/Getters
    void setGsm(const string& g);
    string getGsm() const;

    Client& operator=(const Client& other);

    virtual string tuple() const override;
    virtual string toString() const override;

    // Sérialisation / Désérialisation XML
    friend ostream& operator<<(ostream& os, const Client& c);
    friend istream& operator>>(istream& is, Client& c);
    bool operator< (const Client& other)const;
};

#endif
