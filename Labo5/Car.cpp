#include "Car.h"
#include "Option.h"
#include "OptionException.h"
#include <iostream>
using namespace std;

namespace carconfig {

// Constructeurs
    Car::Car() {
        cout << ">>> Car : constructeur par défaut <<<" << endl;
        name = "---";
        for (int i = 0; i < 5; ++i) options[i] = nullptr;
    }

    Car::Car(const string& n, Model m) {
        cout << ">>> Car : constructeur d'initialisation <<<" << endl;
        name = n;
        model = m;
        for (int i = 0; i < 5; ++i) options[i] = nullptr;
    }

    Car::Car(const Car& c) {
        cout << ">>> Car : constructeur de copie <<<" << endl;
        name = c.name;
        model = c.model;
        for (int i = 0; i < 5; ++i) {
            if (c.options[i] != nullptr)
                options[i] = new Option(*c.options[i]);
            else
                options[i] = nullptr;
        }
    }

    // Destructeur
    Car::~Car() {
        cout << ">>> Car : destructeur <<<" << endl;
        for (int i = 0; i < 5; ++i) {
            if (options[i] != nullptr) {
                delete options[i];
                options[i] = nullptr;
            }
        }
    }

    // Setters/Getters
    void Car::setName(const string& n) { name = n; }
    void Car::setModel(Model m) { model = m; }
    const string Car::getName() const { return name; }
    Model Car::getModel() const { return model; }

    // Options
    int Car::addOption(const Option& option) {
        // Vérifier si l'option existe déjà (par code)
        for (int i = 0; i < 5; ++i) {
            if (options[i] != nullptr && options[i]->getCode() == option.getCode()) {
                throw OptionException("Option déjà présente : " + option.getCode());
            }
        }
        // Vérifier s'il reste de la place
        for (int i = 0; i < 5; ++i) {
            if (options[i] == nullptr) {
                options[i] = new Option(option);
                return 0;
            }
        }

        throw OptionException("Aucune place disponible pour ajouter l'option : " + option.getCode());
    }

    void Car::removeOption(const string& code) {
        for (int i = 0; i < 5; ++i) {
            if (options[i] != nullptr && options[i]->getCode() == code) {
                delete options[i];
                options[i] = nullptr;
                return;
            }
        }
        throw OptionException("Option non trouvée : " + code);
    }
    float Car::getPrice() const {
        float total = model.getBasePrice();
        for (int i = 0; i < 5; ++i) {
            if (options[i] != nullptr) total += options[i]->getPrice();
        }
        return total;
    }

    // Display
    void Car::display() const {
        cout << "=== Projet de voiture ===" << endl;
        cout << "Nom du projet : " << name << endl;
        cout << "Modèle de base :" << endl;
        model.display();
        cout << "Options :" << endl;
        bool hasOption = false;
        for (int i = 0; i < 5; ++i) {
            if (options[i] != nullptr) {
                options[i]->display();
                hasOption = true;
            }
        }
        if (!hasOption) cout << "Aucune option." << endl;
        cout << "Prix total : " << getPrice() << " €" << endl;
    }

    // Surcharge opérateurs
    Car& Car::operator=(const Car& c) {
        if (this != &c) {
            name = c.name;
            model = c.model;
            for (int i = 0; i < 5; ++i) {
                if (options[i] != nullptr) delete options[i];
                options[i] = (c.options[i] != nullptr) ? new Option(*c.options[i]) : nullptr;
            }
        }
        return *this;
    }

    Car Car::operator+(const Option& op) const {
        Car temp(*this);
        temp.addOption(op);
        return temp;
    }

    Car Car::operator-(const Option& op) const {
        Car temp(*this);
        temp.removeOption(op.getCode());
        return temp;
    }

    Car Car::operator-(const string& code) const {
        Car temp(*this);
        temp.removeOption(code);
        return temp;
    }

    // Comparaison par prix
    bool Car::operator<(const Car& c) const { return getPrice() < c.getPrice(); }
    bool Car::operator>(const Car& c) const { return getPrice() > c.getPrice(); }
    bool Car::operator==(const Car& c) const { return getPrice() == c.getPrice(); }

    // Accès option par index
    Option* Car::operator[](int index) const {
        if (index < 0 || index >= 5) return nullptr;
        return options[index];
    }

    // Surcharge <<
    ostream& operator<<(ostream& out, const Car& c) {
        out << "=== Projet de voiture ===" << endl;
        out << "Nom du projet : " << c.name << endl;
        out << "Modèle de base :" << endl;
        out << c.model;
        out << "Options :" << endl;
        bool hasOption = false;
        for (int i = 0; i < 5; ++i) {
            if (c.options[i] != nullptr) {
                out << *c.options[i];
                hasOption = true;
            }
        }
        if (!hasOption) out << "Aucune option." << endl;
        out << "Prix total : " << c.getPrice() << " €" << endl;
        return out;
    }

    // Option + Car
    Car operator+(const Option& op, const Car& c) {
        Car temp(c);
        temp.addOption(op);
        return temp;
    }

} 


//TEST2A
/* CLASSES = ./Classes/
COMPILE = g++ -I $(CLASSES)

Test2a: Test2a.cpp $(CLASSES)Car.o $(CLASSES)Model.o
	$(COMPILE) Test2a.cpp $(CLASSES)Car.o $(CLASSES)Model.o -o Test2a

$(CLASSES)Car.o: $(CLASSES)Car.cpp $(CLASSES)Car.h $(CLASSES)Model.h
	$(COMPILE) -c $(CLASSES)Car.cpp -o $(CLASSES)Car.o

$(CLASSES)Model.o: $(CLASSES)Model.cpp $(CLASSES)Model.h
	$(COMPILE) -c $(CLASSES)Model.cpp -o $(CLASSES)Model.o

clean:
	rm -f $(CLASSES)*.o Test2a */

//TEST2B

/*
CLASSES = ./Classes/
COMPILE = g++ -I $(CLASSES)

Test2b: Test2b.cpp $(CLASSES)Option.o
	$(COMPILE) Test2b.cpp $(CLASSES)Option.o -o Test2b

$(CLASSES)Option.o: $(CLASSES)Option.cpp $(CLASSES)Option.h
	$(COMPILE) -c $(CLASSES)Option.cpp -o $(CLASSES)Option.o

clean:
	rm -f $(CLASSES)*.o Test2b
 */

//TEST2C 

/*
CLASSES = ./Classes/
COMPILE = g++
Test2c: Test2c.cpp $(CLASSES)Car.o $(CLASSES)Model.o $(CLASSES)Option.o
	$(COMPILE) Test2c.cpp $(CLASSES)Car.o $(CLASSES)Model.o $(CLASSES)Option.o -o Test2c

$(CLASSES)Car.o: $(CLASSES)Car.cpp $(CLASSES)Car.h $(CLASSES)Model.h $(CLASSES)Option.h
	$(COMPILE) -I $(CLASSES) -c $(CLASSES)Car.cpp -o $(CLASSES)Car.o

$(CLASSES)Model.o: $(CLASSES)Model.cpp $(CLASSES)Model.h
	$(COMPILE) -I $(CLASSES) -c $(CLASSES)Model.cpp -o $(CLASSES)Model.o

$(CLASSES)Option.o: $(CLASSES)Option.cpp $(CLASSES)Option.h
	$(COMPILE) -I $(CLASSES) -c $(CLASSES)Option.cpp -o $(CLASSES)Option.o

clean:
	rm -f $(CLASSES)*.o Test2c
*/




