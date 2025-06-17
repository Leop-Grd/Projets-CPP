#include <string>
#include <iostream>

#include "Personnage.hpp"
#include "Magicien.hpp"

class Druide : public Magicien
{
    public :
    Druide(std::string nom);
    void heal(Personnage &cible, int heal_pdv);
    
};