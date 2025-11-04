#include "Model.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace carconfig
{
//----------- CONSTRUCTEURS ------------------
Model::Model()
{
    cout << ">>>> Model : constructeur par defaut <<<<" << endl;
    name = nullptr;
    setName("nom");
    setPower(0);
    setEngine(Engine::Petrol);
    setBasePrice(0.0f);
}

Model::Model(const char* n, int p, Engine e, float bp)
{
    cout << ">>>> Model : constructeur d'initialisation <<<<" << endl;
    name = nullptr;
    setName(n);      // Copie profonde
    setPower(p);
    setEngine(e);
    setBasePrice(bp);
}

Model::Model(const Model &m)
{
    cout << ">>>> Model : constructeur de copie <<<<" << endl;
    name = nullptr;
    setName(m.name);  // Copie profonde
    setPower(m.power);
    setEngine(m.engine);
    setBasePrice(m.basePrice);
}

//-------- DESTRUCTEUR -------------
Model::~Model()
{
    cout << ">>>> Model : destructeur <<<<" << endl;
    delete[] name;
    name = nullptr;
}

//-------- OPÉRATEUR D’AFFECTATION ----------------
Model& Model::operator=(const Model& m)
{
    if (this != &m) // éviter auto-affectation
    {
        setName(m.name); // copie profonde
        setPower(m.power);
        setEngine(m.engine);
        setBasePrice(m.basePrice);
    }
    return *this;
}

//-------- SETTERS & GETTERS ----------------
void Model::setName(const char* n)
{
    if (!n) return;

    // Libérer l'ancienne mémoire
    delete[] name;
    name = new char[strlen(n)+1];
    strcpy(name, n);
}

void Model::setPower(int p)
{
    if (p >= 0)
        power = p;
}

void Model::setEngine(Engine e)
{
    engine = e;
}

void Model::setBasePrice(float bp)
{
    if (bp >= 0)
        basePrice = bp;
}

const char* Model::getName() const
{
    return name;
}

int Model::getPower() const
{
    return power;
}

Engine Model::getEngine() const
{
    return engine;
}

float Model::getBasePrice() const
{
    return basePrice;
}

//------------------ METHODES ---------------------
void Model::display() const
{
    cout << "=== Model Info ===" << endl;
    cout << "Name      : " << (name ? name : "---") << endl;
    cout << "Power     : " << power << " HP" << endl;

    cout << "Engine    : ";
    switch (engine)
    {
        case Petrol:   cout << "Petrol"; break;
        case Diesel:   cout << "Diesel"; break;
        case Electric: cout << "Electric"; break;
        case Hybrid:   cout << "Hybrid"; break;
    }
    cout << endl;

    cout << "Base Price: " << basePrice << " €" << endl;
}
}

