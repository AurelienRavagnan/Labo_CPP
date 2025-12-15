#include "Option.h"
#include "OptionException.h"
#include <iostream>
using namespace std;

namespace carconfig {
    Option::Option() {
        cout << ">>> Option : constructeur par défaut <<<" << endl;
        code = "---";
        label = "---";
        price = 0.0f;
    }

    Option::Option(const string& c, const string& l, float p) {
        cout << ">>> Option : constructeur d'initialisation <<<" << endl;
        if(c.size() != 4)throw OptionException("Code invalide : doit contenir exactement 4 caractères !");
        if(l.empty())throw OptionException("Intitulé invalide : ne peut pas être vide !");
        if(p<0)throw OptionException("Prix invalide : ne peut pas être négatif !");

        code = c;
        label = l;
        price = p;
    }

    Option::Option(const Option& o) {
        cout << ">>> Option : constructeur de copie <<<" << endl;
        code = o.code;
        label = o.label;
        price = o.price;
    }

    Option::~Option() {
        cout << ">>> Option : destructeur <<<" << endl;
    }

    void Option::setCode(const string& c) {
        if (c.size() != 4) throw OptionException("Code invalide : doit contenir exactement 4 caractères");
        code = c;
    }

    void Option::setLabel(const string& l) {
        if (l.empty()) throw OptionException("Intitulé invalide : ne peut pas être vide");
        label = l;
    }

    void Option::setPrice(float p) {
        if (p < 0) throw OptionException("Prix invalide : doit être positif");
        price = p;
    }
    string Option::getCode() const { return code; }
    string Option::getLabel() const { return label; }
    float Option::getPrice() const { return price; }

    void Option::display() const {
        cout << "=== Option Info ===" << endl;
        cout << "Code  : " << code << endl;
        cout << "Label : " << label << endl;
        cout << "Price : " << price << " €" << endl;
    }

    Option& Option::operator--() {
        if (price - 1.0f < 0) throw OptionException("Opérateur -- invalide : prix négatif");
        price -= 1.0f;
        return *this;
    }

    Option Option::operator--(int) {
        Option temp(*this);
        if (price - 1.0f < 0) throw OptionException("Opérateur -- invalide : prix négatif");
        price -= 1.0f;
        return temp;
    }
    ostream& operator<<(ostream& os, const Option& o) {
        os << o.code << " " << o.label << " " << o.price << " €";
        return os;
    }

    istream& operator>>(istream& is, Option& o) {
        string c, l;
        float p;
        is >> c >> l >> p;

        if (c.size() != 4) throw OptionException("Code invalide (>>)");
        if (l.empty()) throw OptionException("Intitulé invalide (>>)");
        if (p < 0) throw OptionException("Prix invalide (>>)");

        o.code = c;
        o.label = l;
        o.price = p;
        return is;
    }
} 
