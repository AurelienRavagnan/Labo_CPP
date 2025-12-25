#include <iostream>
#include "includes/Garage.h"
using namespace std;

Garage Garage::instance;
Car Garage::currentProject;

Garage::Garage(){
    cout << "----Garage : Constructeur par défaut----"<<endl;
}

Garage::~Garage(){
    cout <<"----Garage : destructeur----"<<endl;
}

Garage& Garage::getInstance(){
    return instance;
}

// 													**** Model ****
//*************************************************************************************************************************************

//Les méthodes void addModel(…) et void addOption(…) permettent d’ajouter un modèle ou une option dans le bon conteneur.
void Garage::addModel(const Model & m){
    models.push_back(m);
    cout << "Modèle ajouté : " << m.getName() << endl;
}
//Les méthodes displayAllOptions() et void displayAllModels() permettent d’afficher en console le contenu des conteneurs correspondants.
void Garage::displayAllModels() const{
    cout << "Liste des modèles dans le garage :" << endl;
    int index = 0;
    for(const auto& model : models){
        cout << index++ << " : " << model.toString() << endl;
    }
}
//Les méthodes getModel(int index) et getOption(int index) qui permettent de retourner une copie du modèle ou de l’option situé(e) dans le conteneur correspondant à l’indice passé en paramètre.
Model Garage::getModel(int index) const{
    if(index < 0 || index >= static_cast<int>(models.size())){
        throw out_of_range("Index de modèle invalide");
    }
    auto it = models.begin();
    advance(it, index);
    return *it;
}
// 													**** Option ****
//*************************************************************************************************************************************
void Garage::addOption(const Option & o){
    options.push_back(o);
    cout << "Option ajoutée : " << o.getLabel() << endl;
}

void Garage::displayAllOptions() const{
    cout << "Liste des options dans le garage :" << endl;
    int index = 0;
    for(const auto& option : options){
        cout << index++ << " : " << option.toString() << endl;
    }
}

Option Garage::getOption(int index){
    if(index < 0 || index >= static_cast<int>(options.size())){
        throw out_of_range("Index d'option invalide");
    }
    auto it = options.begin();
    advance(it, index);
    return *it;
}
// 													**** Client ****
//*************************************************************************************************************************************
int Garage::addClient(string lastName, string firstName, string gsm){
    // Crée un client avec l'id courant
    Client clientToAdd(lastName, firstName, Actor::currentId, gsm);
    // Ajoute le client dans le set
    clients.insert(clientToAdd);
    // Incrémente l'id pour le prochain client/employé
    Actor::currentId++;
    
    // Retourne l'id du client ajouté
    return clientToAdd.getId();   
}
void Garage::displayClients()const{
    cout <<"Contenu du conteneur clients : "<<endl;
    for(set<Client>::const_iterator it = clients.cbegin(); it != clients.end();it++){
        cout<<"-->"<<it->toString()<<" id = "<<it->getId()<<endl;
    }
}

Client Garage::findClientByIndex(int index) const{
    int taille = clients.size();
    int sortie = 0, currentIndex = 0;

    if(index >= taille || index <0) return Client();
    else{
        for(set<Client>::const_iterator it = clients.cbegin(); it!= clients.cend(); it++){
            if(currentIndex == index){
                return *it;
            }
            currentIndex++;
        }
    }
}

Client Garage::findClientById(int id) const{
    for(set<Client>::const_iterator it = clients.cbegin(); it!= clients.cend(); it++){
        if(it->getId() == id){
            return *it;
        }
    }
    return Client();
}

void Garage::deleteClientByIndex(int index){
    int taille = clients.size();
    int currentIndex = 0, sortie = 0;

    if(index <taille && index >=0){
        Client clientToDelete;
        clientToDelete= findClientByIndex(index);
        auto it = clients.find(clientToDelete);

        if(it != clients.end()){
            clients.erase(it);
            cout << "Client supprimé : " << clientToDelete.toString() << endl;
        }
        else{
            cout << "Client non trouvé à l'index : " << index << endl;
        }
    
    }else{
        cout << "Index invalide pour la suppression du client : " << index << endl;
    }
}

void Garage::deleteClientById(int id){
    Client clientToDelete;
    clientToDelete = findClientById(id);
    auto it = clients.find(clientToDelete);

    if(it != clients.end()){
        clients.erase(it);
        cout << "Client supprimé : " << clientToDelete.toString() << endl;
    }
    else{
        cout << "Client non trouvé avec l'id : " << id << endl;
    }
}


// 													**** Employee ****
//*************************************************************************************************************************************
int Garage::addEmployee(string lastName, string firstName, string login, string role){
    // Crée un employé avec l'id courant
    Employee employeeToAdd(lastName, firstName, Actor::currentId, login, role);
    // Ajoute l'employé dans le set
    employees.insert(employeeToAdd);
    // Incrémente l'id pour le prochain client/employé
    Actor::currentId++;
    
    // Retourne l'id de l'employé ajouté
    return employeeToAdd.getId();   
}

void Garage::displayEmployees() const{
    cout <<"Contenu du conteneur employés : "<<endl;
    for(set<Employee>::const_iterator it = employees.cbegin(); it != employees.end();it++){
        cout<<"-->"<<it->toString()<<" id = "<<it->getId()<<endl;
    }
}

Employee Garage::findEmployeeByIndex(int index) const{
    int taille = employees.size();
    int currentIndex = 0, sortie = 0;

    if(index >= taille || index <0) return Employee();
    else{
        for(set<Employee>::const_iterator it = employees.cbegin(); it!= employees.cend() && sortie == 0; it++){
            if(currentIndex == index){
                return *it;
            }
            currentIndex++;
        }
    }
}

Employee Garage::findEmployeeById(int id) const{
    for(set<Employee>::const_iterator it = employees.cbegin(); it!= employees.cend(); it++){
        if(it->getId() == id){
            return *it;
        }
    }
    return Employee();
}

void Garage::deleteEmployeeByIndex(int index){
    int taille = employees.size();
    int currentIndex = 0, sortie = 0;

    if(index <taille && index >=0){
        Employee employeeToDelete;
        employeeToDelete= findEmployeeByIndex(index);
        auto it = employees.find(employeeToDelete);

        if(it != employees.end()){
            employees.erase(it);
            cout << "Employé supprimé : " << employeeToDelete.toString() << endl;
        }
        else{
            cout << "Employé non trouvé à l'index : " << index << endl;
        }
    
    }else{
        cout << "Index invalide pour la suppression de l'employé : " << index << endl;
    }
}

void Garage::deleteEmployeeById(int id){
    Employee employeeToDelete;
    employeeToDelete = findEmployeeById(id);
    auto it = employees.find(employeeToDelete);

    if(it != employees.end()){
        employees.erase(it);
        cout << "Employé supprimé : " << employeeToDelete.toString() << endl;
    }
    else{
        cout << "Employé non trouvé avec l'id : " << id << endl;
    }
}

Car& Garage::getCurrentProject(){
    return currentProject;
}

void Garage::resetCurrentProject(){
    currentProject = Car();
}