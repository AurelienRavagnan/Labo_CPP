#ifndef OPTION_H
#define OPTION_H
#include <iostream>
#include <string>
using namespace std;

namespace carconfig {

    class Option {
    private:
        string code;
        string label;
        float price;

    public:
        // Constructeurs et destructeur
        Option();                     
        Option(const string& c, const string& l, float p); 
        Option(const Option& o);                 
        ~Option();

        void setCode(const string& c);
        void setLabel(const string& l);
        void setPrice(float p);

        string getCode() const;
        string getLabel() const;
        float getPrice() const;

        Option& operator--();       
        Option operator--(int);     

        friend ostream& operator<<(ostream& os, const Option& op);
        friend istream& operator>>(istream& is, Option& op);
        //friend car ce sont des fonctions non-membre de la classe qui doivent accèder aux variables privées

        void display() const;
    };

} 
#endif
