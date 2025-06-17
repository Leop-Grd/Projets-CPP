#include <string>

#include "Magicien.hpp"

using namespace std; 

Magicien::Magicien(string nom) : Personnage(nom)
{
}

void Magicien::ice_ball(Personnage &cible)//, int mana)//, Magicien &attaquant)
{
    cible.recevoirDegats(25);
    perdre_mana(20);
}

void Magicien::perdre_mana(int mana)
{
    m_mana-=mana;
}