#include <string>
#include <iostream>

#include "Personnage.hpp"

using namespace std ;

int main(){

    Personnage perso1("Goliath", "Poings", 45, 50), perso2("David");
    Personnage copie_perso2("copie_David", perso2);
    Personnage copie_perso1;
    copie_perso1 = perso1; 
    
    
    cout << endl;
    perso2.afficherEtat(); perso2.afficherArme();
    perso1.afficherEtat(); perso1.afficherArme();
    //copie_perso2.afficherEtat(); copie_perso2.afficherArme();
    //copie_perso1.afficherEtat(); copie_perso1.afficherArme();

    perso1.attaquer(perso2); // Goliath attaque David
    perso2.afficherEtat();
    perso1.afficherEtat();

    perso2.attaquer(perso1); // David contre-attaque Goliath
    perso2.afficherEtat();
    perso1.afficherEtat();

    perso2.changerArme("Marteau du couroux", 100, 100);
    perso2.attaquer(perso1); // David attaque de nouveau Goliath
    perso1.afficherEtat();
    perso2.afficherEtat();
    
    perso2.boirePotiondeMana(10);
    perso2.afficherEtat();
    perso1.attaquer(perso2); // Goliath ré-attaque David
    perso2.afficherEtat();
    perso1.afficherEtat();
    
    perso2.boirePotiondeVie(100);
    perso2.afficherEtat();

    perso2.attaquer(perso1);
    perso1.afficherEtat();


    return 0;
}