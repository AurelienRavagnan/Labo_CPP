#include "Car.h"
#include <iostream>
#include <cstring>
#include "Model.h"
#include "Option.h"
using namespace std;

namespace carconfig
{

  //-----------Constructeurs----------
  Car::Car()
  {
    #ifdef DEBUG
    cout << ">>> Car : constructeur par défaut <<<" << endl;
    #endif
    name = "---";
    Model();
    for(int i =0 ; i < 5; i++){
        options[i] = NULL;
    }
  }

  Car::Car(const string& n, Model m)
  {
    #ifdef DEBUG
    cout << ">>> Car : constructeur d'initialisation <<<" << endl;
    #endif
    setName(n);
    setModel(m);
    for(int i = 0 ;i < 5; i++){
        options[i]=NULL;
    }
  }

  Car::Car(const Car& c) 
  {
    #ifdef DEBUG
    cout << ">>> Car : constructeur de copie <<<" << endl;
    #endif
    name = c.name;
    model = c.model;
    for (int i = 0; i < 5; ++i) {
        if (c.options[i] != NULL)
            options[i] = new Option(*c.options[i]);
        else
            options[i] = NULL;
    }
  }

  //----------Set----------------
  void Car::setName(const string& n)
  {
    name = n;
  }

  void Car::setModel(Model m)
  {
    model = m;
  }

  //-------------Get----------------
  const string Car::getName() const
  {
    return name;
  }

  Model Car::getModel() const
  {
    return model;
  }

  //---------Destructeur----------
  Car::~Car()
  {
    #ifdef DEBUG
    cout << ">>> Car : destructeur <<<" << endl;
    #endif
    for (int i = 0; i < 5; ++i) 
    {
      if (options[i] != nullptr) 
      {
        delete options[i];
        options[i] = nullptr;
      }
    }
  }

  //------------Méthode pour les options----------------
  int Car::addOption(const Option & option)
  {
    for(int i = 0;i < 5 ; i++)
    {
        if(options[i]== nullptr)
        {
            options[i]= new Option(option);
            return 0;
        }
    }
    cout << "Aucune place disponible pour ajouter cette option !" << endl;
    return -1; 
  }

  void Car::removeOption(string code)
  {
    for (int i = 0; i < 5; ++i) 
    {
      if (options[i] != nullptr && options[i]->getCode() == code) 
      {
        delete options[i];
        options[i] = nullptr;
        return;
      }
    }
    cout << "Option non trouvée : " << code << endl;
  }

  float Car::getPrice() const 
  {
    float total = model.getBasePrice();
    for (int i = 0; i < 5; ++i) 
    {
      if (options[i] != nullptr)
          total += options[i]->getPrice();
    }
    return total;
  }

  //-----------Méthode--------------
  void Car::display() const
  {
    cout << "=== Projet de Voiture ===" << endl;
    cout << "Nom du Projet : " << name << endl;
    cout << "Modèle de Base : "<< endl;
    model.display();
    cout << "Options :" << endl;
    for (int i = 0; i < 5; ++i)
    {
      if (options[i] != nullptr)
        options[i]->display();
    }
    cout << "Prix total : " << getPrice() << " euros" << endl;
  }

  //-----------Operateur d'affectation (=)--------------
  Car& Car::operator=(const Car& c)
  {
    if (this != &c) // éviter l'auto-affectation
    {
      name = c.name;
      model = c.model;

      // Nettoyer les anciennes options
      for (int i = 0; i < 5; ++i)
      {
        if (options[i] != nullptr)
        {
          delete options[i];
          options[i] = nullptr;
        }
      }

      // Copier les options
      for (int i = 0; i < 5; ++i)
      {
        if (c.options[i] != nullptr)
          options[i] = new Option(*c.options[i]);
        else
          options[i] = nullptr;
      }
    }
    return *this;
  }

  Car Car::operator+(const Option& opt) const
  {
    Car copie(*this);
    copie.addOption(opt);
    return copie;
  }

  Car operator+(const Option& opt, const Car& c)
  {
    Car copie(c);
    copie.addOption(opt);
    return copie;
  }

  Car Car::operator-(const Option& opt) const
  {
    Car copie(*this);
    copie.removeOption(opt.getCode());
    return copie;
  }

  Car Car::operator-(const string& code) const
  {
    Car copie(*this);
    copie.removeOption(code);
    return copie;
  }

  bool Car::operator<(const Car& other) const
  {
    return this->getPrice() < other.getPrice();
  }

  bool Car::operator>(const Car& other) const
  {
    return this->getPrice() > other.getPrice();
  }

  bool Car::operator==(const Car& other) const
  {
    return this->getPrice() == other.getPrice();
  }

  ostream& operator<<(ostream& out, const Car& c)
  {
    out << c.getName() << ", " << c.getModel() << ", ";  //sorti par exemple -> Toyota, Supra, 
    for(int compt = 0; compt < 5; compt ++) //boucle pour les 5 options possibles de la voiture.
    {
      if (c.options[compt] != nullptr) //on vérifie que l'autre voiture contient bien la compt-ème option.
      out << (*(c.options[compt])); // on ajoute l'option exsistante ( * on passe d'un pointeur a en objet)
    }

    return out; 
  }

  Option* Car::operator[](int i) const
  {
    return options[i]; 
  }

}