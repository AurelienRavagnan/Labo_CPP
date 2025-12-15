#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <fstream>
#include "Actor.h"

using namespace std;

class Employee : public Actor
{
private:
    string login;
    string* password;   
    string role;        

public:

    static const string SELLER;
    static const string ADMINISTRATIVE;

    Employee();
    Employee(const string& last, const string& first, int id,
             const string& login, const string& role);
    Employee(const Employee& other);
    ~Employee();

    string getLogin() const;
    void setLogin(const string& login);
    string getRole() const;
    void setRole(const string& role);
    string getPassword() const;
    void setPassword(const string& mdp);
    void resetPassword();


    Employee& operator=(const Employee& other);
    string toString() const override;  
    string tuple() const override;     

    friend ostream& operator<<(ostream& os, const Employee& e);
    friend istream& operator>>(istream& is, Employee& e);
};

#endif
