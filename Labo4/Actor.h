#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <iostream>
#include <fstream>

#include "Person.h"

using namespace std;

class Actor : public Person
{
	protected:
		int Id;
	public:
		//constructeur
		Actor();
		Actor(string nom, string prenom, int id);
		Actor(const Actor& i);
		//destructeur
		virtual ~Actor();

		//get et set
		int getId() const;
		void setId(int id);

		//opérateur
		Actor& operator=(const Actor& i);

		//Fonctions
		virtual string toString() const = 0;
		virtual string tuple() const = 0;

		void save(ofstream& fichier);
		void load(ifstream& fichier);
};

#endif