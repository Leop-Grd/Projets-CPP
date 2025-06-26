#ifndef MATRICE
#define MATRICE
#include <iostream>
#include <vector>

#include "Polynome.hpp"

class Matrice {

    public :
    Matrice(int l, int c, double data);
    Matrice(const std::vector<std::vector<double>>& data); // constructeur surchargé
    ~Matrice();

    int getLigne() const;
    int getColonne() const;

    // Création de foncteur pour déterminer le comportement du vecteur de coefficients
    double& operator()(int i, int j); // écriture
    double operator()(int i, int j) const; // lecture


    void print_Matrice(std::ostream& out)const;
    
    private : 
    int m_lignes;
    int m_colonnes;
    std::vector<std::vector<double>> m_data_coeff; // Matrice = vecteur où chaque ligne est un vecteur de coefficients double 
};

std::ostream& operator << (std::ostream& out, Matrice const& M);

#endif