#ifndef REPRESENTATIONETAT
#define REPRESENTATIONETAT

#include <iostream>
#include <vector>

#include "Matrice.hpp"

class RepresentationEtat {

    public : 
    RepresentationEtat();
    ~RepresentationEtat();

    void print_commande(Fdt const& TF);
    void print_observation(Fdt const& TF);

    private :
    Matrice m_A, m_B, m_C;
    double m_D;
};

#endif