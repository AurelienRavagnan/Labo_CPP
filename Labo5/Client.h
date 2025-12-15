#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <fstream>

#include "Actor.h"

using namespace std;

class Client : public Actor
{
private:
    string gsm;

public:

    Client();
    Client(const string& last, const string& first, int id, const string& gsm);
    Client(const Client& other);

    virtual ~Client();


    void setGsm(const string& g);
    string getGsm() const;

    Client& operator=(const Client& other);

    virtual string tuple() const override;
    virtual string toString() const override;

    friend ostream& operator<<(ostream& os, const Client& c);
    friend istream& operator>>(istream& is, Client& c);
};

#endif
