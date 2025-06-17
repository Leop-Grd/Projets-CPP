#include <cmath>
#include <iostream>

#include "Figure.hpp"

#define PI 3.14159265

using namespace std;

// Classe Figure

Figure::Figure()
{
}

Figure::~Figure()
{
}

void Figure::afficher() const
{
    cout << "\n" << "Ceci est une figure" ;
}

// Classe Triangle

Triangle::Triangle(double b, double h, double c): Figure(), m_base(b), m_hauteur(h), m_cote(c)
{
}

Triangle::~Triangle()
{
}

void Triangle::afficher() const
{
    Figure::afficher();
    cout << " mais c'est aussi un triangle de base " << m_base << " et de hauteur " << m_hauteur << endl;
    cout << "Son perimetre: " << perimetre() << "cm" << endl; // une méthode const NE PEUT PAS appeler une méthode non constante
    cout << "Son aire: " << aire() << "cm^2" << endl;
    
}

double Triangle::perimetre()const
{
    double _perim;
    _perim = m_base+2*m_cote;
    return (_perim);
}

double Triangle::aire()const
{
    return (m_base*m_hauteur)/2;
}

// Classe Triangle rectangle
Triangle_rect::Triangle_rect(double h, double b, double c): Triangle(h,b,c)
{
}

Triangle_rect::~Triangle_rect()
{
}

double Triangle_rect::calculer_hypotenuse()const
{
    return sqrt(m_base*m_base + m_cote+m_cote);
}

void Triangle_rect::afficher()const
{
    Figure::afficher();
    cout << " mais c'est aussi un triangle rectangle de base " << m_base << " et de cote " << m_cote << endl;
    cout << "Son hypotenuse est " << calculer_hypotenuse() << "cm" << endl;
    cout << "Son perimetre: " << perimetre() << "cm" << endl; // une méthode const NE PEUT PAS appeler une méthode non constante
    cout << "Son aire: " << aire() << "cm^2" << endl;
}


// Classe Carre

Carre::Carre(double cote) : Figure(), m_cote(cote)
{
}

Carre::~Carre()
{
}

void Carre::afficher() const
{
    Figure::afficher();
    cout << " mais c'est aussi un carre de cote " << m_cote << endl;
    cout << "Son perimetre: " << perimetre() << "cm" << endl;
    cout << "Son aire: " << aire() << "cm^2" << endl;
}

double Carre::perimetre()const
{
    return 4*m_cote;
}

double Carre::aire()const
{
    return m_cote*m_cote;
}


// Classe Rectangle

Rectangle::Rectangle(double longueur, double largeur):Figure(), m_longueur(longueur),m_largeur(largeur)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::afficher()const
{
    Figure::afficher();
    cout << " mais c'est aussi un rectangle de longueur " << m_longueur << " et de largeur " << m_largeur <<endl;
    cout << "Son perimetre: " << perimetre() << "cm" << endl;
    cout << "Son aire: " << aire() << "cm^2" << endl;
}

double Rectangle::perimetre()const
{
    return (2*m_longueur + 2*m_largeur);
}

double Rectangle::aire()const
{
    return (m_longueur*m_largeur);
}


// Classe Cercle

Cercle::Cercle(double rayon):Figure(), m_rayon(rayon)
{
}

Cercle::~Cercle()
{
}

void Cercle::afficher()const
{
    Figure::afficher();
    cout << " mais c'est aussi un cercle de rayon " << m_rayon <<endl;
    cout << "Son perimetre: " << perimetre() << "cm" << endl;
    cout << "Son aire: " << aire() << "cm^2" << endl;
}

double Cercle::perimetre()const
{
    return (2*m_rayon*PI);
}

double Cercle::aire()const
{
    return (m_rayon*m_rayon*PI);
}
