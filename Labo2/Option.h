#ifndef OPTION_H
#define OPTION_H
#include <iostream>
#include <cstring>
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
        
        // Set et get
        void setCode(const string& c);
        void setLabel(const string& l);
        void setPrice(float p);

        string getCode() const;
        string getLabel() const;
        float getPrice() const;

        //Méthode
        void display() const;
    };

} 
#endif
