#include <string>
#include <iostream>

#include "Arme.hpp"

using namespace std;

Arme::Arme():m_nom("Arme de base"), m_degats(1), m_mana_arme(1)
{
}

Arme::Arme(string nom, int degats, int mana): m_nom(nom), m_degats(degats), m_mana_arme(mana)
{
}

Arme::~Arme()
{
} //destructeur 


void Arme::changer(string nvl_arme, int degats_nvl_arme, int mana_nvl_arme){
    m_nom = nvl_arme;
    m_degats = degats_nvl_arme;
    m_mana_arme = mana_nvl_arme;
}

int Arme::getDegats() const{
    return m_degats;
}

int Arme::getMana() const{
    return m_mana_arme;
}

void Arme::afficher() const{

    cout << "\033[35m"<< m_nom << "\033[0m | " << "Degats: " << m_degats << " | " << "Mana: "<< m_mana_arme << endl;
}