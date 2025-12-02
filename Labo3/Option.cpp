#include "Option.h"
#include <iostream>
using namespace std;

namespace carconfig 
{
    //Constructeur
    Option::Option() 
    {
        #ifdef DEBUG
        cout << ">>> Option : constructeur par défaut <<<" << endl;
        #endif
        code = "---";
        label = "---";
        price = 0.0f;
    }

    Option::Option(const string& c, const string& l, float p) 
    {
        #ifdef DEBUG
        cout << ">>> Option : constructeur d'initialisation <<<" << endl;
        #endif
        code = c;
        label = l;
        price = p;
    }

    Option::Option(const Option& o) 
    {
        #ifdef DEBUG
        cout << ">>> Option : constructeur de copie <<<" << endl;
        #endif
        code = o.code;
        label = o.label;
        price = o.price;
    }

    //Destructeur
    Option::~Option() 
    {
        #ifdef DEBUG
        cout << ">>> Option : destructeur <<<" << endl;
        #endif
    }

    //Setter
    void Option::setCode(const string& c) 
    { 
        code = c; 
    }
    void Option::setLabel(const string& l) 
    { 
        label = l; 
    }
    void Option::setPrice(float p) 
    { 
        if(p >= 0) price = p; 
    }
    void Option::setIntitule(const std::string& i) 
    {
        label = i;
    }

    //Getter
    string Option::getCode() const 
    { 
        return code; 
    }
    string Option::getLabel() const 
    { 
        return label; 
    }
    float Option::getPrice() const 
    { 
        return price; 
    }
    const std::string& Option::getIntitule() const 
    {
        return label;
    }


    //Methode
    void Option::display() const 
    {
        cout << "=== Option Info ===" << endl;
        cout << "Code  : " << code << endl;
        cout << "Label : " << label << endl;
        cout << "Price : " << price << " €" << endl;
    }

    //Opérateur
    ostream& operator<<(ostream& os, const Option& opt)
    {
        os << "Code: " << opt.getCode()
        << ", Intitule: " << opt.getIntitule()
        << ", Prix: " << opt.getPrice();
        return os;
    }

    istream& operator>>(istream& is, Option& opt)
    {
        string code, intitule;
        float prix;

        cout << "  Code     : ";
        is >> code;

        cout << "  Intitule : ";
        is.ignore();
        getline(is, intitule);

        cout << "  Prix     : ";
        is >> prix;

        opt.setCode(code);
        opt.setIntitule(intitule);
        opt.setPrice(prix);

        return is;
    }

    Option& Option::operator--()
    {
        setPrice(getPrice() - 50.00);
        return *this; 
    }


    Option Option::operator--(int i)
    {
        Option copy = *this;
        setPrice(getPrice() - 50.00);
        return copy; 

    }
} 
