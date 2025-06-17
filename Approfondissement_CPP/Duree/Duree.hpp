#ifndef DUREE
#define DUREE

class Duree {
    
    public : 
    Duree(int h=0, int min=0, int sec=0); 
    ~Duree();
    
    bool estInf(Duree const& d) const;
    Duree& operator +=(const Duree &d); // operateurs arithmetiques

    /* Duree operator + (Duree &d) const; // 1ère méthode operator + avant += */
    /* void afficher() const; // const pour une méthode n'est possible QUE si methode membre
       void afficher_flux(std::ostream &out) const; // remplace afficher() et remplacée par << declaré "friend"
       bool estEgal(Duree const& d) const; // remplacé par == déclaré "friend"
    */
    

    private:
    int m_h;
    int m_min;
    int m_sec;
    int m_compteur;
    static int s_compteur;

    // Passage des operateur << et == comme fonctions friend de Duree
    friend std::ostream &operator << (std::ostream &out, Duree const& d); // avec "friend" remplace afficher_flux
    friend bool operator == (Duree const& d1, Duree const& d2); // avec "friend" remplace estEgal
};

// operateurs de comparaison :
/* n'est pas une méthode donc ne peut pas utiliser les attributs
donc il faut appeler une méthode qui peut utiliser les attributs
*/

//bool operator == (Duree const& d1, Duree const& d2); // references constantes sur les objets à comparer --> evite de copier l'objet et donc d'utiliser de la place en mémoire 
bool operator < (Duree const& d1, Duree const& d2);
bool operator > (Duree const& d1, Duree const& d2);
Duree operator + (Duree const &d1, Duree const &d2); // on ne peut pas mettre la methode const car elle n'est pas membre de la classe

// operateur de flux :
//std::ostream &operator << (std::ostream &out, Duree const& d); // déplacé dans la classe Duree car déclaré "friend"

#endif