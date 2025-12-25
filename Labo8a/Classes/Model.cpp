#include "Model.h"
#include <iostream>
using namespace std;

namespace carconfig {

    Model::Model() {
        name = "---";
        power = 1;
        engine = Petrol;
        basePrice = 1.1f;
    }

    Model::Model(const string& n, int p, Engine e, float bp)
        : name(n), power(p), engine(e), basePrice(bp) {}

    Model::Model(const Model& m)
        : name(m.name), power(m.power), engine(m.engine), basePrice(m.basePrice) {}

    Model::~Model() {}

    void Model::setName(const string& n) { name = n; }
    void Model::setPower(int p) { if (p >= 1) power = p; }
    void Model::setEngine(Engine e) { engine = e; }
    void Model::setBasePrice(float bp) { if (bp >= 0) basePrice = bp; }

    const string& Model::getName() const { return name; }
    int Model::getPower() const { return power; }
    Engine Model::getEngine() const { return engine; }
    float Model::getBasePrice() const { return basePrice; }

    void Model::display() const {
        cout << *this;
    }

    string Model::toString() const {
        return "<model>\n=== Model Info === Name : " + name +
               " Power : " + to_string(power) +
               " HP Engine : " + to_string(engine) +
               " Base Price: " + to_string(basePrice) + " €\n</model>\n";
    }

    // ----- Opérateurs -----
ostream& operator<<(ostream& os, const Model& m) {
    os << "<Model>" << endl;
    os << "<name>" << endl << m.name << endl << "</name>" << endl;
    os << "<power>" << endl << m.power << endl << "</power>" << endl;

    os << "<engine>" << endl;
    switch (m.engine) {
        case Petrol: os << "Petrol"; break;
        case Diesel: os << "Diesel"; break;
        case Electric: os << "Electric"; break;
        case Hybrid: os << "Hybrid"; break;
    }
    os << endl << "</engine>" << endl;

    os << "<basePrice>" << endl << m.basePrice << endl << "</basePrice>" << endl;
    os << "</Model>" << endl;
    return os;
}
    istream& operator>>(istream& is, Model& m) {
        getline(is, m.name);
        is >> m.power;
        int e; is >> e;
        m.engine = static_cast<Engine>(e);
        is >> m.basePrice;
        return is;
    }
}
