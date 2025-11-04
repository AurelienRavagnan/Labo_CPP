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
        friend ostream& operator<<(ostream& os, const Option& opt);
        friend istream& operator>>(istream& is, Option& opt);
        
        Option& operator--();
        Option operator--(int i);
        
        // Set et get
        void setCode(const string& c);
        void setLabel(const string& l);
        void setIntitule(const string& i);
        void setPrice(float p);

        string getCode() const;
        string getLabel() const;
        const string& getIntitule() const;
        float getPrice() const;

        //Méthode
        void display() const;

    };

} 
#endif
