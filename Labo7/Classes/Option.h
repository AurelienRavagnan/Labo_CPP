#ifndef OPTION_H
#define OPTION_H
#include <iostream>
#include <string>
#include <sstream>
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

        // Setters
        void setCode(const string& c);
        void setLabel(const string& l);
        void setPrice(float p);

        // Getters
        string getCode() const;
        string getLabel() const;
        float getPrice() const;

        // Opérateurs de décrémentation
        Option& operator--();       // préfixé
        Option operator--(int);     // postfixé

        // Sérialisation / désérialisation
        friend ostream& operator<<(ostream& os, const Option& op);
        friend istream& operator>>(istream& is, Option& op);

        // Méthode d'affichage texte
        string toString() const;

        void display() const; 
    };

} // namespace carconfig

#endif
