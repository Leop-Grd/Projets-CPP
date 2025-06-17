#include <iostream>
#include <string>

#include "Personnage.hpp"
#include "Guerrier.hpp"
//#include "Magicien.hpp"
#include "Druide.hpp"

using namespace std;

int main(){
    Personnage Perso1("Villageois");
    Guerrier Perso2("Warrior");
    Magicien Perso3("Mage");
    Druide Perso4("Druide");

    cout << endl;
    Perso1.afficher();
    Perso2.afficher();
    Perso3.afficher();
    Perso4.afficher();

    Perso1.attaquer(Perso3);
    Perso3.ice_ball(Perso1);
    Perso1.afficher();
    Perso3.afficher();
    Perso4.heal(Perso1,100);
    Perso1.afficher();
    Perso4.afficher();


    return 0;
}