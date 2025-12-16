#include "Car.h"
#include "Option.h"
#include "OptionException.h"
#include <iostream>
#include <sstream>
using namespace std;

namespace carconfig {

// Constructeurs
Car::Car()
{
    #ifdef DEBUG
    cout << ">>> Car : constructeur par défaut <<<" << endl;
    #endif
    setName("---");
    for (int i = 0; i < 5; ++i)
        options[i] = nullptr;
}

Car::Car(const string& n, Model m)
{
    #ifdef DEBUG
    cout << ">>> Car : constructeur d'initialisation <<<" << endl;
    #endif
    setName(n);
    setModel(m);
    for (int i = 0; i < 5; ++i)
        options[i] = nullptr;
}


Car::Car(const Car& c)
{
    #ifdef DEBUG
    cout << ">>> Car : constructeur de copie <<<" << endl;
    #endif
    setName(c.getName());
    setModel(c.getModel());

    for (int i = 0; i < 5; ++i)
    {
        if (c.options[i] != nullptr)
            options[i] = new Option(*c.options[i]);
        else
            options[i] = nullptr;
    }
}


// Destructeur
Car::~Car() {
    #ifdef DEBUG
    cout << ">>> Car : destructeur <<<" << endl;
    #endif
    for (int i = 0; i < 5; ++i) {
        if (options[i] != nullptr) {
            delete options[i];
            options[i] = nullptr;
        }
    }
}

// Setters/Getters
void Car::setName(const string& n) { name = n; }
void Car::setModel(Model m) { model = m; }
const string Car::getName() const { return name; }
Model Car::getModel() const { return model; }

// Options
int Car::addOption(const Option& option) {
    for (int i = 0; i < 5; ++i) {
        if (options[i] != nullptr && options[i]->getCode() == option.getCode()) {
            throw OptionException("Option déjà présente : " + option.getCode());
        }
    }
    for (int i = 0; i < 5; ++i) {
        if (options[i] == nullptr) {
            options[i] = new Option(option);
            return 0;
        }
    }
    throw OptionException("Aucune place disponible pour ajouter l'option : " + option.getCode());
}

void Car::removeOption(const string& code) {
    for (int i = 0; i < 5; ++i) {
        if (options[i] != nullptr && options[i]->getCode() == code) {
            delete options[i];
            options[i] = nullptr;
            return;
        }
    }
    throw OptionException("Option non trouvée : " + code);
}

float Car::getPrice() const {
    float total = model.getBasePrice();
    for (int i = 0; i < 5; ++i) {
        if (options[i] != nullptr) total += options[i]->getPrice();
    }
    return total;
}

// Display
void Car::display() const {
    cout << "=== Projet de voiture ===" << endl;
    cout << "Nom du projet : " << name << endl;
    cout << "Modèle de base :" << endl;
    model.display();
    cout << "Options :" << endl;
    bool hasOption = false;
    for (int i = 0; i < 5; ++i) {
        if (options[i] != nullptr) {
            options[i]->display();
            hasOption = true;
        }
    }
    if (!hasOption) cout << "Aucune option." << endl;
    cout << "Prix total : " << getPrice() << " €" << endl;
}

// Surcharge opérateurs
Car& Car::operator=(const Car& c)
{
    if (this != &c)
    {
        setName(c.getName());
        setModel(c.getModel());

        for (int i = 0; i < 5; ++i)
        {
            if (options[i] != nullptr)
                delete options[i];

            options[i] = (c.options[i] != nullptr)
                           ? new Option(*c.options[i])
                           : nullptr;
        }
    }
    return *this;
}


Car Car::operator+(const Option& op) const {
    Car temp(*this);
    temp.addOption(op);
    return temp;
}

Car Car::operator-(const Option& op) const {
    Car temp(*this);
    temp.removeOption(op.getCode());
    return temp;
}

Car Car::operator-(const string& code) const {
    Car temp(*this);
    temp.removeOption(code);
    return temp;
}

bool Car::operator<(const Car& c) const { return getPrice() < c.getPrice(); }
bool Car::operator>(const Car& c) const { return getPrice() > c.getPrice(); }
bool Car::operator==(const Car& c) const { return getPrice() == c.getPrice(); }

Option* Car::operator[](int index) const {
    if (index < 0 || index >= 5) return nullptr;
    return options[index];
}


ostream& operator<<(ostream& out, const Car& c) {
    out << "<Car>" << endl;

    out << "<name>" << endl;
    out << c.name << endl;
    out << "</name>" << endl;

    out << "<model>" << endl;
    out << c.model; // Appel opérateur << de Model
    out << "</model>" << endl;

    out << "<options>" << endl;
    for (int i = 0; i < 5; ++i) {
        if (c.options[i] != nullptr) {
            out << *c.options[i]; // Appel opérateur << de Option
        }
    }
    out << "</options>" << endl;

    out << "</Car>" << endl;
    return out;
}

istream& operator>>(istream& is, Car& c) {
    string tag;

    getline(is, tag); // <Car>
    getline(is, tag); // <name>
    getline(is, c.name);
    getline(is, tag); // </name>

    // Lecture du modèle
    getline(is, tag); // <model>
    is >> c.model;
    getline(is, tag); // </model>

    // Lecture des options
    getline(is, tag); // <options>
    while (true) {
        streampos pos = is.tellg();
        getline(is, tag);

        if (tag.find("</options>") != string::npos)
            break;

        if (tag.find("<Option>") != string::npos) {
            is.seekg(pos);  
            Option opt;
            is >> opt;
            c.addOption(opt);
        }
    }

    getline(is, tag); // </Car>
    return is;
}
    // Option + Car
    Car operator+(const Option& op, const Car& c) {
        Car temp(c);
        temp.addOption(op);
        return temp;
    }

}
