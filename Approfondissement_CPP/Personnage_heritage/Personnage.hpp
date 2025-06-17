#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>

class Personnage {
    public:
    Personnage(std::string nom_Personnage);
    ~Personnage();

    void recevoirDegats(int degats);
    void recevoirSoins(int soins);   
    void attaquer(Personnage &cible) const;
    void afficher()const;

    std::string getNom() const;

    protected :
    std::string m_nom;
    int m_pdv;
    int m_mana;
};

#endif