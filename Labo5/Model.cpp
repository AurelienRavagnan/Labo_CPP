#include "Model.h"
#include <iostream>
using namespace std;
namespace carconfig{
    Model::Model() {
        cout << ">>> Model : constructeur par défaut <<<" << endl;
        name = "---";
        power = 1;
        engine = Petrol;
        basePrice = 1.1f;
    }

    Model::Model(const string& n, int p, Engine e, float bp) {
        cout << ">>> Model : constructeur d'initialisation <<<" << endl;
        name = n;
        power = p;
        engine = e;
        basePrice = bp;
    }

    Model::Model(const Model& m) {
        cout << ">>> Model : constructeur de copie <<<" << endl;
        name = m.name;
        power = m.power;
        engine = m.engine;
        basePrice = m.basePrice;
    }

    Model::~Model() {
        cout << ">>> Model : destructeur <<<" << endl;
    }

    void Model::setName(const string& n) { 
        name = n; 
    }
    void Model::setPower(int p) { 
        if(p >= 1) power = p; 
    }
    void Model::setEngine(Engine e) { 
        engine = e; 
    }
    void Model::setBasePrice(float bp) { 
        if(bp >= 0) basePrice = bp; 
    }

    const string& Model::getName() const { 
        return name; 
    }
    int Model::getPower() const { 
        return power; 
    }
    Engine Model::getEngine() const { 
        return engine; 
    }
    float Model::getBasePrice() const { 
        return basePrice; 
    }

    void Model::display() const {
        cout << "=== Model Info ===" << endl;
        cout << "Name      : " << name << endl;
        cout << "Power     : " << power << " HP" << endl;

        cout << "Engine    : ";
        switch (engine) {
            case Petrol:   cout << "Petrol"; break;
            case Diesel:   cout << "Diesel"; break;
            case Electric: cout << "Electric"; break;
            case Hybrid:   cout << "Hybrid"; break;
        }
        cout << endl;

        cout << "Base Price: " << basePrice << " €" << endl;
    }
    ostream& operator<<(ostream& os, const Model& m) {
        os << "=== Model Info ===" << endl;
        os << "Name      : " << m.name << endl;
        os << "Power     : " << m.power << " HP" << endl;
        os << "Engine    : " << m.engine << endl; 
        os << "Base Price: " << m.basePrice << " €" << endl;
        return os;
    }

    istream& operator>>(istream& is, Model& m) {
        cout << "Nom du modèle : ";
        getline(is, m.name);

        cout << "Puissance (HP) : ";
        is >> m.power;

        int e;
        cout << "Type moteur (0=Petrol, 1=Diesel, 2=Electric, 3=Hybrid) : ";
        is >> e;
        m.engine = static_cast<Engine>(e);

        cout << "Prix de base : ";
        is >> m.basePrice;
        return is;
    }
}

