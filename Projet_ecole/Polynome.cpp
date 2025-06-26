#include <iostream>
#include <string>

#include "Polynome.hpp"

using namespace std;

/*________________________________CLASSE POLYNOME ________________________________________*/

bool Polynome::hide_name=false;

/*Constructeurs surchargés*/
Polynome::Polynome(string name, const vector<double>& coeff) : m_name(name), m_coeff(coeff)
{
}

Polynome::~Polynome()
{
}

vector<double>const& Polynome::getCoeff() const 
{
    return m_coeff;
}

/*Methodes de la classe*/
void Polynome::print_flux(ostream& out) const
{
    bool first = true; 
    
    if (!hide_name) {out << endl << m_name << ": " ;} // affiche le nom des Polynomes que pour print_flux et non print_fdt
    
    for (int i=m_coeff.size()-1; i>=0; i--)
    {
        if (m_coeff[i]==0) // si le coeff est nul --> n'affiche rien
            continue;
         
        if (!first) // si c'est le premier coefficient du polynome --> n'affiche pas le "+"
            out << " + ";
        first = false;
        
        if (i==0)                    // si coeff a0 --> affiche a0 et non a0z^0
            out <<m_coeff[i];
        else if (i==1)               // si coeff a1 --> affiche z et non z^1
            out << m_coeff[i] << "z";
        else                         // pour les autres coeff 
            out << m_coeff[i] << "z^" << i;
        
    }    
}



/*Operateur de flux*/
ostream& operator << (ostream& out, Polynome const& P)
{
    P.print_flux(out);
    return out;
}


/*______________________________CLASSE Fdt_________________________*/

Fdt::Fdt(Polynome const& num, Polynome const& den) : m_Num(num), m_Den(den)
{
}

Fdt::~Fdt()
{
}

void Fdt::print_fdt(ostream &out)const
{
    Polynome::hide_name = true; 
    out << endl << "                                " << m_Num << endl;
    out << "Fonction de transfert : H(z) = --------------------" << endl;
    out << "                                " << m_Den << endl;
    Polynome::hide_name = false;
}

Polynome const& Fdt::getNum()const
{
    return m_Num;
}

Polynome const& Fdt::getDen()const
{
    return m_Den;
}


ostream& operator << (ostream& out, Fdt const& fdt)
{
    fdt.print_fdt(out);
    return out;
}
