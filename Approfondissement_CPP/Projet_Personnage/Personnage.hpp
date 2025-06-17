#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>

#include "Arme.hpp"


class Personnage {

    public: 
    // constructeurs
    Personnage(); //constructeur par défaut
    Personnage(std::string nom_perso); //Constructeur surchargé
    Personnage(std::string nom_perso, std::string nom_arme, int degats_arme, int mana_arme); // CONSTRUCTEUR surchargé
    Personnage(std::string nom_perso, Personnage const& perso_to_copy); // constructeur de copie
    
    // destructeur
    ~Personnage(); 

    // méthodes
    void recevoirdegats (int degats_arme);
    void attaquer (Personnage &cible);
    void boirePotiondeVie (int quantite_potion_vie);
    void boirePotiondeMana (int quantite_potion_mana);
    void changerArme(std::string nom, int degats, int mana);
    void afficherEtat() const;
    void afficherArme() const;

    //operateur
    Personnage& operator = (Personnage const& perso_to_copy);
    // nécessaire de créer l'opérateur de surcarge + qui va de pair avec le constructeur de copie
    // si création constructeur de copie alors création opérateur de surcharge +
    
    private:
    std::string m_nom_perso; // m_ pour dire que c'est une variable membre = attribut
    int m_pdv;  
    int m_mana;
    //Arme m_arme;
    Arme *m_arme; 
};

#endif