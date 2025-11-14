#include "Model.h"
#include <iostream>
#include <limits>

using namespace std;

namespace carconfig {

// utilitaire : dupliquer une c-string (retourne nullptr si src==nullptr)
char* Model::duplicate(const char* s) {
    if (!s) return nullptr;
    size_t len = std::strlen(s);
    char* dst = new char[len + 1];
    std::strcpy(dst, s);
    return dst;
}

// --------- constructeurs / destructeur ----------
Model::Model()
: name(nullptr), power(0), engine(Petrol), basePrice(0.0f)
{
    cout << ">>>> Model : constructeur par defaut <<<<" << endl;
    setName("nom");
}

Model::Model(const char* n, int p, Engine e, float bp)
: name(nullptr), power(0), engine(e), basePrice(bp)
{
    cout << ">>>> Model : constructeur d'initialisation <<<<" << endl;
    setName(n);
    setPower(p);
    setEngine(e);
    setBasePrice(bp);
}

Model::Model(const Model& m)
: name(nullptr), power(m.power), engine(m.engine), basePrice(m.basePrice)
{
    cout << ">>>> Model : constructeur de copie <<<<" << endl;
    if (m.name) name = duplicate(m.name);
}

// opérateur d'affectation (deep copy)
Model& Model::operator=(const Model& m) {
    if (this != &m) {
        // remplacer le name correctement
        delete[] name;
        name = nullptr;
        if (m.name) name = duplicate(m.name);

        power = m.power;
        engine = m.engine;
        basePrice = m.basePrice;
    }
    return *this;
}

Model::~Model()
{
    cout << ">>>> Model : destructeur <<<<" << endl;
    delete[] name;
    name = nullptr;
}

// --------- setters
void Model::setName(const char* n)
{
    // accepte nullptr ou chaîne
    delete[] name;
    name = nullptr;
    if (n) name = duplicate(n);
}

void Model::setPower(int p)
{
    if (p >= 0) power = p;
}

void Model::setEngine(Engine e)
{
    engine = e;
}

void Model::setBasePrice(float bp)
{
    if (bp >= 0.0f) basePrice = bp;
}

// --------- getters
const char* Model::getName() const { return name; }
int Model::getPower() const { return power; }
Engine Model::getEngine() const { return engine; }
float Model::getBasePrice() const { return basePrice; }

// --------- display
void Model::display() const
{
    cout << "=== Model Info ===" << endl;
    cout << "Name      : " << (name ? name : "---") << endl;
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

// --------- opérateurs de flux
ostream& operator<<(ostream& os, const Model& m)
{
    os << "Nom: " << (m.getName() ? m.getName() : "---")
       << ", Puissance: " << m.getPower() << " HP"
       << ", Moteur: ";
    switch (m.getEngine()) {
        case Petrol:   os << "Petrol"; break;
        case Diesel:   os << "Diesel"; break;
        case Electric: os << "Electric"; break;
        case Hybrid:   os << "Hybrid"; break;
    }
    os << ", Prix de base: " << m.getBasePrice() << " €";
    return os;
}

istream& operator>>(istream& is, Model& m)
{
    // lecture interactive sécurisée
    char buffer[256];
    int puissance = 0;
    int moteur = 0;
    float prix = 0.0f;

    cout << "  Nom du modele : ";
    // vider la ligne précédente puis lire une ligne
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    is.getline(buffer, sizeof(buffer));

    cout << "  Puissance (HP) : ";
    is >> puissance;

    cout << "  Type moteur (0=Petrol,1=Diesel,2=Electric,3=Hybrid) : ";
    is >> moteur;

    cout << "  Prix de base : ";
    is >> prix;

    m.setName(buffer);
    m.setPower(puissance);
    if (moteur >= 0 && moteur <= 3) m.setEngine(static_cast<Engine>(moteur));
    m.setBasePrice(prix);

    return is;
}

} // namespace carconfig
