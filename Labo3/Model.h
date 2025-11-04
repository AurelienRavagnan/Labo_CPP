#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <cstring>
using namespace std;

namespace carconfig
{

enum Engine {Petrol, Diesel, Electric, Hybrid};

class Model
{

  friend ostream& operator<<(ostream& out, const Model& m);
  friend istream& operator>>(istream& in, Model& m);
  
  private:
    string  name;
    int     power;
    Engine  engine;
    float   basePrice;

  public:
    Model();
    Model(const string& n, int p, Engine e, float bp);
    Model(const Model &m);
    ~Model();

    void setName(const string& n);
    void setPower(int p);
    void setEngine(Engine e);
    void setBasePrice(float bp);

    const string& getName() const;
    int         getPower() const;
    Engine      getEngine() const;
    float       getBasePrice() const;

    void display() const;
};

}
#endif