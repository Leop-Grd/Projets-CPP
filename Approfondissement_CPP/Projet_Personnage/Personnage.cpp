#include <iostream>
#include <string>

#include "Personnage.hpp"


using namespace std;

// __________ CONSTRUCTEURS __________

// Constructeur par défaut
Personnage::Personnage() : m_pdv(100), m_mana(100), m_arme(nullptr) 
{
    m_arme = new Arme();
} 
// Constructeur surchargé
Personnage::Personnage(string nom_perso) : m_nom_perso(nom_perso), m_pdv(100), m_mana(100), m_arme(nullptr)
{
    m_arme = new Arme(); // Arme est un pointeur, il faut le créer par le biais d'une allocation dynamique avec new
}
// Constructeur surchargé
Personnage::Personnage(string nom_perso, string nom_arme, int degats_arme, int mana_arme) : m_nom_perso(nom_perso), m_pdv(100), m_mana(100), m_arme(nullptr)
{
    m_arme = new Arme(nom_arme, degats_arme, mana_arme ); // new renvoie l'adresse de l'objet créé, stockée dans pointeur m_arme
} 
// Constructeur de copie
Personnage :: Personnage(string nom_perso, Personnage const& perso_to_copy) : m_nom_perso (nom_perso), m_pdv(perso_to_copy.m_pdv), m_mana(perso_to_copy.m_mana), m_arme(nullptr)
{
    //m_arme = new rme(); on créer une nouvelle arme mais avec le constructeur par défaut, donc pas l'arme du personnage copié
    //m_arme = new Arme(perso_to_copy.m_arme); // m_arme est un pointeur donc ici renvoie l'adresse de l'objet
    m_arme = new Arme(*(perso_to_copy.m_arme)); // ici renvoie l'objet copié
} 

// Destructeur
Personnage::~Personnage()
{
    delete m_arme; // OBLIGATOIRE : évite fuite de mémoire (=traine en mémoire et ne peut pas être supprimé)
} //destructeur




// __________ METHODES __________

void Personnage::recevoirdegats(int degats_arme){
    m_pdv -= degats_arme;

    if (m_pdv < 0){
        m_pdv=0;
    }
}

void Personnage::attaquer(Personnage &cible){
    cout << "\n\033[1;33m" << m_nom_perso << " attaque " << cible.m_nom_perso << "\033[0m \n" << endl;

    int mana_arme_attaquant;
    mana_arme_attaquant = (*m_arme).getMana();

    if (m_mana - mana_arme_attaquant >=0){
        m_mana -= mana_arme_attaquant;
        cible.recevoirdegats((*m_arme).getDegats());
    }
    else 
        cout << "\033[31mMana insuffisante\033[0m\n" << endl;
}

void Personnage::boirePotiondeVie(int quantite_potion_vie){
    cout << "\n\033[3m" << m_nom_perso << " boit une potion de vie\033[0m\n" << endl;
    m_pdv += quantite_potion_vie;
    
    if (m_pdv > 100){
        m_pdv=100;
    }
}

void Personnage::boirePotiondeMana(int quantite_potion_mana){
    cout << "\n\033[3m" << m_nom_perso << " boit une potion de mana\033[0m\n" << endl;
    m_mana = m_mana + quantite_potion_mana;
    
    if (m_mana > 100){
        m_mana=100;
    }
}

void Personnage::changerArme(string nom, int degats, int mana){
    cout << "\n\033[3m" << m_nom_perso << " change d'arme\033[0m" << endl;
    (*m_arme).changer(nom, degats, mana);
    (*m_arme).afficher();
}

void Personnage::afficherEtat() const{
    
    string etat;

    cout << m_nom_perso << ": " << "\033[32m" << m_pdv << "/100\033[0m" << "\033[34m  " << m_mana << "/100\033[0m" << endl;

    if (m_pdv==0){
        etat = "MORT";
        cout << "\n\033[31m" << m_nom_perso << " est " << etat << "\033[0m" << endl;
    }
     
}

void Personnage::afficherArme() const {
    (*m_arme).afficher();
}


// Operateur membre
Personnage& Personnage::operator = (Personnage const& perso_to_copy)
{
    if (this != &perso_to_copy){ // verification que les 2 objets sont distincts
        
        m_nom_perso = perso_to_copy.m_nom_perso;
        m_pdv = perso_to_copy.m_pdv;
        m_mana = perso_to_copy.m_mana;
        delete m_arme; // suppression arme déjà existante
        m_arme = new Arme(*(perso_to_copy.m_arme));
    }

    return *this; // renvoie la référence de l'objet pointé
}
   