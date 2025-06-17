#include <iostream>
#include <vector>

#include "Figure.hpp"

using namespace std;

void presenter(Figure const& f)
{
    f.afficher();
}

int main () {

    // utilisation de reference
    Triangle t1(3,2.5,5.3);
    presenter(t1);
    
    // utilisation de pointeur
    Figure *t2 = new Triangle(10,10,10);
    Figure *c1 = new Carre(4.7);
    Figure *cercle1 = new Cercle(15);

    t2->afficher();
    c1->afficher();
    cercle1->afficher();

    delete t2;
    delete c1;
    delete cercle1;

    // utilisation d'un vecteur
    Figure *c2 = new Carre(6);
    Figure *cercle2 = new Cercle(3);
    Figure *rect1 = new Rectangle(6,3);
    Figure *tri_rect1 = new Triangle_rect(3,3,6);

    vector <Figure * > listeFigures;
    listeFigures.push_back(c2);
    listeFigures.push_back(cercle2);
    listeFigures.push_back(rect1);
    listeFigures.push_back(tri_rect1);

    for (Figure *f : listeFigures)
    {
        f->afficher();
    }

    for (int i=0;i<listeFigures.size();i++)
    {   
        delete listeFigures[i]; // supprime les objets dans le vecteur 
        listeFigures[i]=nullptr; // les pointeurs sont rénitialisés
    }
    listeFigures.clear(); // vide le vecteur (pas nécessaire)

    return 0;
}