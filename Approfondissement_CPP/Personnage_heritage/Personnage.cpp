#include <string>
#include <iostream>
#include "Personnage.hpp"

using namespace std ;

Personnage::Personnage(string nom_Personnage) : m_nom(nom_Personnage), m_pdv(100), m_mana(100)
{
}

Personnage::~Personnage()
{
}

void Personnage::recevoirDegats(int degats)
{
    m_pdv -= degats;
    if (m_pdv<0)
        m_pdv=0;
}

void Personnage::recevoirSoins(int soins)
{
    m_pdv += soins;
    if (m_pdv>100)
        m_pdv=100;
}

void Personnage::attaquer(Personnage &cible) const
{
    cout << "\n\033[33m" << m_nom << " attaque " << cible.m_nom << "\33[0m\n" << endl;
    cible.recevoirDegats(10);
}

void Personnage::afficher()const
{
    cout << m_nom << ": " << "\033[32m" << m_pdv << "/100\033[0m | \033[34m" << m_mana << "/100\033[0m" << endl;
}

string Personnage::getNom()const 
{
    return m_nom;
}