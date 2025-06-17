/*POLYMORPHISME
Le polymorphisme permet de manipuler des objets d'une classe fille 
via des pointeurs ou des références sur une classe mère.

Deux ingrédients sont nécessaires : des fonctions virtuelles 
et des pointeurs ou références sur l'objet.
*/

#include "Garage.hpp"
#include <vector>
#include <iostream>

using namespace std;

// void presenter (Vehicule const& v)
// {
//     v.afficher();
// }


int main(){

    // //Passage par référence 
    // Voiture voiture1(1, "Mercedes", "Grise", 4, 5);
    // Moto moto1(2, "Yamaha", "Verte", 2, 90);

    // presenter(voiture1);
    // presenter(moto1);

    // // Passage par pointeurs
    // Vehicule *voiture2= new Voiture(3, "Peugeot 107", "Rouge", 4, 3);
    // Vehicule *moto2 = new Moto(4, "Suzuki GSXR650", "Bleue", 2, 150);

    // (*voiture2).afficher();
    // moto2->afficher();

    // delete voiture2;
    // delete moto2;


    vector<Vehicule*> listeVehicules; // std::vector est une classe générique qu'on utilise comme un template et de mettre le type qu'on veut entre les <>

    listeVehicules.push_back(new Voiture("Peugeot 107", "Rouge", 4, 3));
    listeVehicules.push_back(new Moto("Suzuki GSXR650", "Bleue", 2, 150)); // push_back ajoute élément à la fin du vecteur 
    
    //int numero =1;
    for (Vehicule* v : listeVehicules)
    {
        //cout << "\n" << "Vehicule " << numero << " :" << endl ;     
        (*v).afficher();
        //numero++;
    }

    for (int i; i<listeVehicules.size(); i++)
    {
        delete  listeVehicules[i];
        listeVehicules[i]=0;
    }

    return 0;
}