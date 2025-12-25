#ifndef GARAGE_H
#define GARAGE_H
#include <iostream>
#include <set>
#include <list>
#include <string>
#include "Employee.h"
#include "Client.h"
#include "Option.h"
#include "Model.h"

using namespace std;
using namespace carconfig;
class Garage {
private:

    set<Employee> employees;
    set<Client> clients;
    list<Model> models;
    list<Option> options;
    static Garage instance;

public:
    Garage();
    ~Garage();

    static Garage& getInstance();
    
    void addModel(const Model & m);
    void displayAllModels() const;
    Model getModel(int index) const;

    void addOption(const Option & o);
    void displayAllOptions() const;
    Option getOption(int index);

    int addClient(string lastName, string firstName, string gsm);
    void displayClients() const;
    void deleteClientByIndex(int index);
    void deleteClientById(int id);
    Client findClientByIndex(int index) const;
    Client findClientById(int id) const;

    int addEmployee(string lastName, string firstName, string login, string role);
    void displayEmployees() const;
    void deleteEmployeeByIndex(int index);
    void deleteEmployeeById(int id);
    Employee findEmployeeByIndex(int index) const;
    Employee findEmployeeById(int id) const;
};

#endif