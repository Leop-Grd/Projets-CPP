#include <string>
#include "Personnage.hpp"

class Magicien : public Personnage
{
    
    public : 
    Magicien(std::string nom);
    void ice_ball(Personnage &cible);//, Magicien &attaquant);
    void perdre_mana(int mana);

};