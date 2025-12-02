#include "Car.h"
#include <iostream>
#include "Model.h"
#include "Option.h"

namespace carconfig
{

  //-----------Constructeurs----------
 Car::Car()
{
    cout << ">>> Car : constructeur par défaut <<<" << endl;
    name = "---";
    for(int i = 0; i < 5; i++) {
        options[i] = nullptr;
    }
}

  Car::Car(const string& n, Model m)
  {
    cout << ">>> Car : constructeur d'initialisation <<<" << endl;
    setName(n);
    setModel(m);
    for(int i = 0 ; i < 5; i++){
        options[i] = NULL;
    }
  }

  Car::Car(const Car& c) 
  {
    cout << ">>> Car : constructeur de copie <<<" << endl;
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
    cout << ">>> Car : destructeur <<<" << endl;
    for (int i = 0; i < 5; ++i) 
    {
        if (options[i] != NULL) 
        {
            delete options[i];
            options[i] = NULL;
        }
    }
  }

  //------------Méthode pour les options----------------
  int Car::addOption(const Option & option)
  {
    for(int i = 0; i < 5 ; i++)
    {
        if(options[i] == NULL)
        {
            options[i] = new Option(option);
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
      if (options[i] != NULL && options[i]->getCode() == code) 
      {
        delete options[i];
        options[i] = NULL;
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
        if (options[i] != NULL)
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

    cout << "--- Options ---" << endl;
    for (int i = 0; i < 5; ++i) {
        if (options[i] != NULL)
            options[i]->display();
    }
    cout << "Prix total : " << getPrice() << " euros" << endl;
  }
}
