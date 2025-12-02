#include "Option.h"
#include <iostream>

namespace carconfig {
Option::Option() {
    cout << ">>> Option : constructeur par défaut <<<" << endl;
    code = "---";
    label = "---";
    price = 0.0f;
}

Option::Option(const string& c, const string& l, float p) {
    cout << ">>> Option : constructeur d'initialisation <<<" << endl;
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

void Option::setCode(const string& c) { code = c; }
void Option::setLabel(const string& l) { label = l; }
void Option::setPrice(float p) { if(p >= 0) price = p; }

string Option::getCode() const { return code; }
string Option::getLabel() const { return label; }
float Option::getPrice() const { return price; }


void Option::display() const {
    cout << "=== Option Info ===" << endl;
    cout << "Code  : " << code << endl;
    cout << "Label : " << label << endl;
    cout << "Price : " << price << " €" << endl;
}

} 
