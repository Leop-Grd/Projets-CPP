#include <iostream>

#include "Duree.hpp"

using namespace std;

int main(){

    Duree duree1(1,30,30), duree2(2,39,59);
    Duree resultat;

    cout << duree1 << duree2 << endl; //duree1.afficher(); duree2.afficher();

    if (duree1 == duree2)
        cout << "duree1 est identique a duree2\n";
    
    else if (duree1 < duree2)
        cout << "duree1 est inferieure a duree2\n";
    
    else if (duree1 > duree2)
        cout << "duree1 est superieure a duree2" << endl;
    
    resultat = duree1+duree2; // le compteur ne s'incrémente par pour resultat car l'operateur "+" utilise le constructeur de copie
    cout << "Duree1 + Duree2 = " << resultat << endl; //resultat.afficher();

    return 0;
}