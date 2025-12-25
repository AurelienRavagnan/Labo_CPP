#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <vector>
#include "Model.h"
#include "Option.h"
#include "XmlFileSerializer.hpp"
#include "XmlFileSerializerException.h"

using namespace std;

namespace carconfig {

class Car {
private:
    string name;
    Model model;
    Option* options[5];

public:
    // Constructeurs & destructeur
    Car();
    Car(const string& n, Model m);
    Car(const Car& c);
    ~Car();

    // Setters/Getters
    void setName(const string& n);
    void setModel(Model m);
    const string getName() const;
    Model getModel() const;

    // Options
    int addOption(const Option& option);
    void removeOption(const string& code);
    float getPrice() const;

    // Display
    void display() const;

    // Surcharge opérateurs
    Car& operator=(const Car& c);
    Car operator+(const Option& op) const;
    Car operator-(const Option& op) const;
    Car operator-(const string& code) const;

    bool operator<(const Car& c) const;
    bool operator>(const Car& c) const;
    bool operator==(const Car& c) const;

    Option* operator[](int index) const;

    // Surcharge << comme fonction amie
    friend ostream& operator<<(ostream& os, const Car& c);
    friend istream& operator>>(istream& is, Car& c);
    void save(const string& projectName);
    void load(string projectName);
    //méthode rajoutée, pour récupérer les options dans l'interface graphique
    vector<Option> getOptions() const;
};

// Surcharge non-membre Option + Car
Car operator+(const Option& op, const Car& c);

} // namespace carconfig

#endif
    //Le const devant : la chaîne renvoyée est une référence constante → on ne peut pas la modifier.
    //Le const à la fin : la méthode ne modifie pas l’objet.

    //Surcharge => on passe une option en param car dans l'exemple ou doit savoir retirer ou ajouter une option à une voiture



