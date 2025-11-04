#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <cstring>
using namespace std;
namespace carconfig
{

enum Engine { Petrol, Diesel, Electric, Hybrid };

class Model
{
private:
    char*  name;
    int    power;
    Engine engine;
    float  basePrice;

public:
    // Constructeurs / destructeur
    Model();
    Model(const char* n, int p, Engine e, float bp);
    Model(const Model &m);
    ~Model();

    // Setters
    void setName(const char* n);
    void setPower(int p);
    void setEngine(Engine e);
    void setBasePrice(float bp);

    // Getters
    const char* getName() const;
    int         getPower() const;
    Engine      getEngine() const;
    float       getBasePrice() const;

    Model& operator=(const Model& m);

    // Méthode d'affichage
    void display() const;
};

} // namespace carconfig

#endif // MODEL_H