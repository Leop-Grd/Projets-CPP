#include <iostream>

#include "Duree.hpp"

using namespace std;

int Duree::s_compteur=0; // initialisation compteur static

// Constructeur et destructeur  __________________________________________
Duree::Duree(int h, int min, int sec) : m_h(h), m_min(min), m_sec(sec)
{
    ++s_compteur;
    m_compteur= s_compteur;
}

Duree::~Duree()
{
    --s_compteur;
}

// Methodes _______________________________________________________________

/* Remplacée par afficher_flux qui utilise l'operateur <<
void Duree::afficher() const {
    if (m_min<10) 
        cout << m_h << ":0" << m_min << ':' << m_sec <<"\n";
    else 
        cout << m_h << ':' << m_min << ':' << m_sec <<"\n";
}*/

/*Remplacée par l'operateur << seul, déclaré fonction "friend" de Duree
void Duree::afficher_flux(ostream &out) const
{
    if (m_min<10) 
        out << "Duree " << m_compteur << "  " << m_h << ":0" << m_min << ':' << m_sec <<"\n";
    else 
        out << "Duree " << m_compteur << "  " << m_h << ':' << m_min << ':' << m_sec <<"\n";
}*/

/* Remplacée par operateur == déclaré fonction "friend" de Duree
bool Duree::estEgal(Duree const& d) const {
    if (m_h == d.m_h && m_min == d.m_min && m_sec == d.m_sec)
        return true;
    else 
        return false;
}*/

/*estInf peut être remplacé par < en le déclarant friend comme << et == */
bool Duree::estInf(Duree const& d) const 
{
    if (m_h < d.m_h 
        || m_h==d.m_h && m_min < d.m_min 
        || m_h==d.m_h && m_min==d.m_min && m_sec < d.m_sec)
        return true;
    else 
        return false;
}


//operateur de raccourci 
Duree& Duree::operator += (const Duree &d) 
{
    //secondes
    m_sec+=d.m_sec;
    m_min+=m_sec/60;
    m_sec%=60;

    //minutes
    m_min+=d.m_min;
    m_h+=m_min/60;
    m_min%=60;

    //heures
    m_h+=d.m_h;

    return *this; 
/*  return *this va avec Duree& = règle à appliquer pour opérateur de raccourci
    this est le pointeur vers l'objet courant et est de type Duree*
    *this est la référence à l'objet courant modifié de type Duree& 
    Donc le return *this renvoie l'objet référenté modifié : ici l'objet de type Duree
*/
}                

//operateur arithmetique

Duree operator + (Duree const &d1, Duree const &d2)
{
    
    Duree copie(d1); // on créer un constructeur de copie pour pouvoir ne pas modifier d1
    copie += d2;
    return copie;

}

/* 1ère méthode de l'opérateur + avant utilisation +=
Duree Duree::operator + (Duree &d) const{
    
    int sec= (m_sec + d.m_sec)%60 ;
    int min= (m_min + d.m_min)%60 + (m_sec + d.m_sec)/60;
    int h= m_h + d.m_h + (m_min + d.m_min)/60;
    
    return Duree(h,min,sec);
}
*/

//operateurs de comparaison _______________________________________________
bool operator == (Duree const& d1, Duree const& d2)
{
    //return d1.estEgal(d2); // méthode utilisee avant utilisation de friend
    if (d1.m_h == d2.m_h && d1.m_min == d2.m_min && d1.m_sec == d2.m_sec)
        return true;
    else 
        return false;
}

bool operator < (Duree const& d1, Duree const& d2)
{
    return d1.estInf(d2);
}

bool operator > (Duree const& d1, Duree const& d2)
{
    if ( (d1.estInf(d2) == false) && ((d1 == d2) == false) ) // avant friend : (d1.estEgal(d2) == false)
        return true;
}

// operateur de flux 
ostream &operator << (ostream &out, Duree const& d)
{
    /* d.afficher_flux(out); // méthode utilisée avant utilisation de "friend" */
    
    if (d.m_min<10) 
        out << "Duree " << d.m_compteur << "  " << d.m_h << ":0" << d.m_min << ':' << d.m_sec <<"\n";
    else 
        out << "Duree " << d.m_compteur << "  " << d.m_h << ':' << d.m_min << ':' << d.m_sec <<"\n";
    return out;
}