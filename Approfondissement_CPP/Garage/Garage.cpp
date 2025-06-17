#include <iostream>
#include <string>

using namespace std;

#include "Garage.hpp"

// initialisation attribut statique de la classe Vehicule
int Vehicule::m_s_compteur=0;

// Classe mère Vehicule
Vehicule::Vehicule(string marque, string couleur, int roues): m_marque(marque), m_couleur(couleur), m_nbr_roues(roues)
{
    ++m_s_compteur;
    m_id_compteur=m_s_compteur;
}

Vehicule::~Vehicule()
{
    --m_s_compteur;
}

// int Vehicule::nombre_vehicules()
// {
//     return m_s_compteur;
// }

void Vehicule::afficher()const
{
    cout << "\n" << "Vehicule " << m_id_compteur << "/" << m_s_compteur << " :" << endl ; 
    cout << m_nbr_roues << " roues" << endl ;
    cout << "Marque: " << m_marque << endl ;
    cout << "Couleur: " << m_couleur << endl;
}


// Classe fille Voiture:
Voiture::Voiture (string marque, string couleur, int roues, int portes) : Vehicule(marque, couleur, roues), m_portes(portes)
{
}

Voiture::~Voiture()
{
}

void Voiture::afficher()const 
{
    Vehicule::afficher();
    cout << "Nombres de portes: " <<m_portes <<endl;
}

int Voiture::nbr_Roues()const 
{
    return 4;
}

// Classe fille Moto:
Moto::Moto(string marque, string couleur, int roues, int puissance) : Vehicule(marque, couleur, roues), m_puissance(puissance)
{
}

Moto::~Moto()
{
}

void Moto::afficher()const
{
    Vehicule::afficher();
    cout << "Puissance: " << m_puissance << "cv" << endl;
}

int Moto::nbr_Roues()const 
{
    return 2;
}


