#include "Option.h"
#include "OptionException.h"
#include <iostream>
#include <sstream>
using namespace std;

namespace carconfig {

    // ---------- Constructeurs ----------
    Option::Option() {
        cout << ">>> Option : constructeur par défaut <<<" << endl;
        code = "---";
        label = "---";
        price = 0.0f;
    }

    Option::Option(const string& c, const string& l, float p) {
        cout << ">>> Option : constructeur d'initialisation <<<" << endl;
        if (c.size() != 4) throw OptionException("Code invalide : doit contenir exactement 4 caractères !");
        if (l.empty()) throw OptionException("Intitulé invalide : ne peut pas être vide !");
        if (p < 0) throw OptionException("Prix invalide : ne peut pas être négatif !");
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

    // ---------- Setters ----------
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

    // ---------- Getters ----------
    string Option::getCode() const { return code; }
    string Option::getLabel() const { return label; }
    float Option::getPrice() const { return price; }

    // ---------- Méthodes ----------
    void Option::display() const {
        cout << toString() << endl;
    }

    string Option::toString() const {
        stringstream ss;
        ss << "Code : " << code << ", Label : " << label << ", Price : " << price << " €";
        return ss.str();
    }

    // ---------- Opérateurs ----------
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

    // ---------- Sérialisation ----------
    ostream& operator<<(ostream& os, const Option& o) {
        os << "<Option>" << endl;
        os << "<code>" << endl;
        os << o.code << endl;
        os << "</code>" << endl;
        os << "<label>" << endl;
        os << o.label << endl;
        os << "</label>" << endl;
        os << "<price>" << endl;
        os << o.price << endl;
        os << "</price>" << endl;
        os << "</Option>" << endl;
        return os;
    }

    // ---------- Désérialisation ----------
    istream& operator>>(istream& is, Option& o) {
        string line;

        getline(is, line); // <Option>

        getline(is, line); // <code>
        getline(is, o.code); // valeur du code
        getline(is, line); // </code>

        getline(is, line); // <label>
        getline(is, o.label); // valeur du label
        getline(is, line); // </label>

        getline(is, line); // <price>
        getline(is, line); // valeur du prix
        o.price = stof(line);
        getline(is, line); // </price>

        getline(is, line); // </Option>

        return is;
    }

} 
