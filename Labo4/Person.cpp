#include <iostream>
#include "Person.h"



//-------------------------------------------------------
// Constructeurs
//-------------------------------------------------------

Person::Person()
{
    lastName = "Sans nom";
    firstName = "Sans prenom";
}

Person::Person(const string& nom, const string& prenom)
{
    lastName = nom;
    firstName = prenom;
}

Person::Person(const Person& p)
{
    lastName = p.lastName;
    firstName = p.firstName;
}

//-------------------------------------------------------
// Destructeur
//-------------------------------------------------------

Person::~Person()
{

}

//-------------------------------------------------------
// Getters / Setters
//-------------------------------------------------------

string Person::getLastName() const 
{ 
    return lastName; 
}
string Person::getFirstName() const 
{ 
    return firstName; 
}

void Person::setLastName(const string& s) 
{ 
    lastName = s; 
}
void Person::setFirstName(const string& s) 
{ 
    firstName = s; 
}

//-------------------------------------------------------
// Opérateur =
//-------------------------------------------------------

Person& Person::operator=(const Person& p)
{
    if (this != &p)
    {
        lastName = p.lastName;
        firstName = p.firstName;
    }
    return *this;
}

//-------------------------------------------------------
// Opérateur <<
//-------------------------------------------------------

ostream& operator<<(ostream& s, const Person& p)
{
    s << "Nom : " << p.lastName 
      << ", Prenom : " << p.firstName;
    return s;
}

//-------------------------------------------------------
// Opérateur >>
//-------------------------------------------------------

istream& operator>>(istream& s, Person& p)
{
    cout << "Nom : ";
    getline(s, p.lastName);

    cout << "Prenom : ";
    getline(s, p.firstName);

    return s;
}

void Person::save(ofstream & fichier)
{
  #ifdef DEBUG
  cout << "Personne : Save" << endl;
  #endif

  int taille = (*this).lastName.size();
  int tailleI = (*this).firstName.size();

  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }

  fichier.write((char*)&taille,sizeof(int)); // on enregistre le nombre de caractere de nom
  fichier.write((char*)(*this).lastName.data(),taille*sizeof(char));

  fichier.write((char*)&tailleI,sizeof(int)); // on enregistre le nombre de caractere de prenom
  fichier.write((char*)(*this).firstName.data(),tailleI*sizeof(char));
}

void Person::load(ifstream & fichier)
{
  #ifdef DEBUG
  cout << "Personne : Load" << endl;
  #endif

  int t;
  int t2;

  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }
  fichier.read((char*)&t,sizeof(int)); // Lecture de nom
  (*this).lastName.resize(t);
  fichier.read((char*)(*this).lastName.data(),t*sizeof(char));
  

  fichier.read((char*)&t2,sizeof(int)); // Lecture de prenom
  (*this).firstName.resize(t2);
  fichier.read((char*)(*this).firstName.data(),t2*sizeof(char));

}