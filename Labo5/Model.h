#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
using namespace std;

namespace carconfig {
enum Engine { Petrol, Diesel, Electric, Hybrid };

class Model {
private:
    string name;
    int power;
    Engine engine;
    float basePrice;

public:
    // Constructeurs & destructeur
    Model(); // par défaut
    Model(const string& n, int p, Engine e, float bp); // initialisation
    Model(const Model& m); // copie
    ~Model(); // destructeur

    // Setters
    void setName(const string& n);
    void setPower(int p);
    void setEngine(Engine e);
    void setBasePrice(float bp);

    // Getters
    const string& getName() const;
    int getPower() const;
    Engine getEngine() const;
    float getBasePrice() const;

    void display() const;


    friend ostream& operator<<(ostream& os, const Model& m);
    friend istream& operator>>(istream& is, Model& m);

    //je mets const string& pour pas faire de copie => passage par référence c'est plus rapide 
};
}
#endif
