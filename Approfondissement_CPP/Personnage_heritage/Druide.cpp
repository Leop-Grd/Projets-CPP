#include <string>
#include <iostream>

#include "Druide.hpp"


using namespace std;

Druide::Druide(string nom): Magicien(nom)
{
}


void Druide::heal(Personnage &cible, int heal_pdv)
{
    cout << "\n\033[33m" << m_nom << " soigne " << cible.getNom() << "\033[0m" <<endl;
    cible.recevoirSoins(heal_pdv);
    
}