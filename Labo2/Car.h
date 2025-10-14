#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "Model.h"
#include "Option.h"
using namespace std;

namespace carconfig
{
    class Car
    {
    private:
        string name;
        Model model;
        Option* options[5];

    public:
        // Constructeur et destructeur :
        Car();
        Car(const string& n, Model m);
        Car(const Car& c);
        Car& operator=(const Car& c);
        ~Car();

        //Set&Get :
        void setName(const string& n);
        void setModel(Model m);

        const string getName()const;
        Model getModel()const;
        
        //Méthode pour les options :
        int addOption(const Option& option);
        void removeOption(string code);
        float getPrice()const;

        //Méthode
        void display() const;
    };
}
    #endif

