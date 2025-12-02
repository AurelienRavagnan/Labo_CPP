#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <stdlib.h>
#include <string>
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

        //Opérateur
        Car& operator=(const Car& c);
        Car operator+(const Option& opt) const;
        friend Car operator+(const Option& opt, const Car& c);
        Car operator-(const Option& opt) const;
        Car operator-(const string& code) const;
        bool operator<(const Car& other) const;
        bool operator>(const Car& other) const;
        bool operator==(const Car& other) const;
        Option* operator[](int i) const; 
        friend ostream& operator<<(ostream& out, const Car& c);
    };
}
    #endif

