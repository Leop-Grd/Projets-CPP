#ifndef POLYNOME
#define POLYNOME

#include <iostream>
#include <string>
#include <vector>

/*_____________________ Classe Polynome _______________ */

class Polynome {

    public :
    Polynome(std::string name, const std::vector<double>& coeff);
    ~Polynome();

    void print_flux (std::ostream& out) const;

    static bool hide_name; // variable static pour pouvoir cacher "m_name" de l'affichage des Polynomes via print_flux lors de l'affichage de la fdt
                           // commun a tous les Polynomes et accessible à l'extérieure de la class Polynome donc depuis une méthode de la classe Fdt
    
    std::vector<double> const& getCoeff() const;

    private:
    std::string m_name;
    std::vector<double> m_coeff; //évite de créer bêtement un attribut pour chaque coeff 

};

std::ostream& operator << (std::ostream& out, Polynome const& P);


/* _______________________ Classe Fdt ____________________*/

class Fdt {

    public :
    Fdt(Polynome const& num, Polynome const& den); 
    ~Fdt();

    Polynome const& getNum()const;
    Polynome const& getDen()const;
    void print_fdt(std::ostream &out)const; 

    private :
    Polynome m_Num,m_Den;
};

std::ostream& operator << (std::ostream& out, Fdt const& fdt);

#endif