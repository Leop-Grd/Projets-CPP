#ifndef GUERRIER_H
#define GUERRIER_H

#include "Personnage.hpp"

// La classe Guerrier hérite de la classe Personnage 

class Guerrier : public Personnage 
{
    public :
    Guerrier(std::string nom);
    void coupDeHache(Personnage &cible);
};


#endif 