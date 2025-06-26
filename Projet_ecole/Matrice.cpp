#include "Matrice.hpp"

using namespace std;


Matrice::Matrice(int l, int c, double data) : m_lignes(l), m_colonnes(c), m_data_coeff(l,vector<double>(c,data))
{
}

Matrice::Matrice(const vector<vector<double>>& coeff) : m_lignes(coeff.size()), m_colonnes(coeff[0].size()), m_data_coeff(coeff)
{
}

Matrice::~Matrice()
{
}

/* Méthodes de la classe Matrice */

int Matrice::getLigne()const 
{
    return m_lignes;
}

int Matrice::getColonne()const 
{
    return m_colonnes;
}

double& Matrice::operator()(int i, int j)
{
    return m_data_coeff[i][j];
}

double Matrice::operator()(int i, int j)const
{
    return m_data_coeff[i][j];
}


void Matrice::print_Matrice(ostream& out)const
{
    for (int i=0;i<getLigne();i++)
    {
        out << "| ";
        for (int j=0;j<getColonne();j++)
            out << m_data_coeff[i][j] << " ";
        out << "|" << endl;
    }
}


ostream& operator << (ostream& out, Matrice const& M)
{
    M.print_Matrice(out);
    return out;
}