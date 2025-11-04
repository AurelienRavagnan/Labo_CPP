#include "Model.h"
#include <cstring>
#include <limits>

using namespace std;
namespace carconfig
{
//-----------CONSTRUCTEURS------------------
Model::Model()
{
  cout << ">>>> Model : constructeur par defaut <<<<" << endl;
  name = "---";
  setName("nom");
  setPower(0);
  setEngine(Engine::Petrol);
  setBasePrice(0.0);
}

Model::Model(const string& n, int p, Engine e, float bp)
{
  cout << ">>>> Model : constructeur d'initialisation <<<<" << endl;
  name = n;
  power = p;
  engine = e;
  basePrice = bp;
}

Model::Model(const Model &m)
{
  cout << ">>>> Model : constructeur de copie <<<<" << endl;
  name = m.name;
  power = m.power;
  engine = m.engine;
  basePrice = m.basePrice;
}
//--------DESTRUCTEUR-------------
Model::~Model()
{
  cout << ">>>> Model : destructeur <<<<" << endl;
}

//--------SET & GET----------------

void Model::setName(const string& n)
{
name = n;
}

void Model::setPower(int p)
{
  if (p < 0) return;
  power = p;
}

void Model::setEngine(Engine e)
{
  engine = e;
}

void Model::setBasePrice(float bp)
{
  if (bp < 0) return;
  basePrice = bp;
}


const string& Model::getName() const
{
  return name;
}

int         Model::getPower() const
{
  return power;
}

Engine      Model::getEngine() const
{
  return engine;
}

float       Model::getBasePrice() const
{
  return basePrice;
}

//------------------METHODES---------------------
void Model::display() const
{
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

ostream& operator<<(ostream& os, const Model& m)
{
    os << "Nom: " << m.getName()
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
        string nom;
        int puissance;
        int moteur;
        float prix;

        cout << "  Nom du modele : ";
        is.ignore(numeric_limits<streamsize>::max(), '\n'); // vide le buffer
        getline(is, nom);

        cout << "  Puissance (HP) : ";
        is >> puissance;

        cout << "  Type moteur (0=Petrol, 1=Diesel, 2=Electric, 3=Hybrid) : ";
        is >> moteur;

        cout << "  Prix de base : ";
        is >> prix;

        m.setName(nom);
        m.setPower(puissance);
        m.setEngine(static_cast<Engine>(moteur));
        m.setBasePrice(prix);

        return is;
    }
}
