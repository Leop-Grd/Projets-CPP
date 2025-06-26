#include <iostream>
#include <vector>

#include "Polynome.hpp"
#include "Matrice.hpp"
#include "RepresentationEtat.hpp"

using namespace std;

int main ()
{
    int nbr_polynome = 2;
    vector<Polynome> tablePolynomes; // tableaux dynamique de Polynomes, de taille nbr_polynome 
                                      // !! NE PAS FAIRE tablePolynomes(nbr_polynome) 
                                      // -> cela créé un tableau de pointeur nullptr de taille nbr_polynome dont on augmente ensuite la taille en ajoutant les 2 polynomes
                                      // DONC size = 2 pointeurs nullptr + les pointeurs vers les polynomes
    int order_polynome;
    string nom;
    double coeff_cin;

    bool first_Polynome = true;
    for (int i=0 ; i<nbr_polynome ; i++)
    {
        
        if (first_Polynome) 
        {
            nom = "Numerator";
            first_Polynome = false;
        }
        else
        {
            nom = "Denominator";
            first_Polynome = true;
        }
        cout << "Order of " << nom << ": ";
        cin >> order_polynome ;
        vector<double> coeffPolynome; // idem que pour tablePolynomes
            
        cout << "Enter coefficients of " << nom << ": " << endl;
  
        for (int it=0; it<order_polynome+1; it++) // remplissage du vecteur de coefficient avec les coefficient donnés en ligne de commande
        {
            if (!first_Polynome){         // même principe mais logique inversée 
                cout << "b" << it << ": ";
            }
            else 
                cout << "a" << it << ": ";
            
            cin >> coeff_cin;
            coeffPolynome.push_back(coeff_cin); // ajout du coefficient à la fin du vecteur de coefficient
        }

        tablePolynomes.push_back(Polynome(nom, coeffPolynome)); // ajout d'un Polynome à la fin du vecteur de Polynome, avec en argument le vecteur de coefficient
        
    }
    
    /*Affichage des Polynomes*/
    for (Polynome p : tablePolynomes)
    {
        cout << p;
    }



    /*Création d'une fonction de transfert TF qui prend en argument les 2 polynomes saisi et contenus dans le vecteur de polynomes*/
    Fdt TF(tablePolynomes[0],tablePolynomes[1]);
    cout << TF;     /*Affichage en utilisant une 2ème surcharge de l'opérateur <<*/

    /*Création d'une représentation d'état*/
    RepresentationEtat RepEtat;
    RepEtat.print_commande(TF);
    RepEtat.print_observation(TF);

    /* Utilisation initiale d'un vecteur de pointeurs vector <Polynomes*> tablePolynomes mais finalement pas utile car pas de Polymorphisme
    for (Polynome *p : tablePolynomes)
    {
        if (p) // n'affiche que si pointeur != nullptr (!! comme on remet à 0 tablePolynomes dans les lignes suivantes, il est nécessaire de le faire !!)            
            cout << *p;
    }
    for (int i=0; i<tablePolynomes.size(); i++)
    {
        delete tablePolynomes[i];
        tablePolynomes[i]=nullptr;
    }*/
    
    return 0;
}