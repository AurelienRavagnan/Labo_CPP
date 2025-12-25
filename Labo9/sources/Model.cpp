#include "includes/Model.h"
#include <iostream>
using namespace std;

namespace carconfig {

    Model::Model() {
        name = "---";
        power = 1;
        engine = Petrol;
        basePrice = 1.1f;
        image = "default.png";
    }

    Model::Model(const string& n, int p, Engine e, float bp, const string& img)
        : name(n), power(p), engine(e), basePrice(bp), image(img) {}

    Model::Model(const Model& m)
        : name(m.name), power(m.power), engine(m.engine), basePrice(m.basePrice), image(m.image) {}

    Model::~Model() {}

    void Model::setName(const string& n) { name = n; }
    void Model::setPower(int p) { if (p >= 1) power = p; }
    void Model::setEngine(Engine e) { engine = e; }
    void Model::setBasePrice(float bp) { if (bp >= 0) basePrice = bp; }
    void Model::setImage(const string& img) { image = img; }

    const string& Model::getName() const { return name; }
    int Model::getPower() const { return power; }
    Engine Model::getEngine() const { return engine; }
    float Model::getBasePrice() const { return basePrice; }
    const string& Model::getImage() const { return image; }

    void Model::display() const {
        cout << *this;
    }

    string Model::toString() const {
        return "<model>\n=== Model Info ===\n"
               "Name: " + name +
               "\nPower: " + to_string(power) +
               "\nEngine: " + to_string(engine) +
               "\nBase Price: " + to_string(basePrice) + " €" +
               "\nImage: " + image + "\n</model>\n";
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
        os << "<image>" << endl << m.image << endl << "</image>" << endl;

        os << "</Model>" << endl;
        return os;
    }

    istream& operator>>(istream& is, Model& m) {
        getline(is, m.name);
        is >> m.power;
        int e; is >> e;
        m.engine = static_cast<Engine>(e);
        is >> m.basePrice;
        if (!(is >> ws).eof()) {
            getline(is, m.image);
        } else {
            m.image = "default.jpg";
        }

        return is;
    }
}
