#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <cstring>

namespace carconfig {

enum Engine { Petrol, Diesel, Electric, Hybrid };

class Model
{
private:
    char*  name;
    int    power;
    Engine engine;
    float  basePrice;

    // utilitaire interne pour dupliquer une c-string
    static char* duplicate(const char* s);

public:
    // constructeurs / destructeur
    Model();
    Model(const char* n, int p, Engine e, float bp);
    Model(const Model& m);
    ~Model();

    // opérateur d'affectation (pour éviter shallow copy)
    Model& operator=(const Model& m);

    // setters
    void setName(const char* n);
    void setPower(int p);
    void setEngine(Engine e);
    void setBasePrice(float bp);

    // getters
    const char* getName() const;
    int         getPower() const;
    Engine      getEngine() const;
    float       getBasePrice() const;

    // affichage
    void display() const;
};

// opérateurs de flux (dans le namespace)
std::ostream& operator<<(std::ostream& os, const Model& m);
std::istream& operator>>(std::istream& is, Model& m);

} // namespace carconfig

#endif // MODEL_H
