#define GARAGE
#ifdef GARAGE

#include <string>

class Vehicule { // classe abstraite car au moins 1 méthode virtuelle pure
    
    public :
    Vehicule(std::string marque, std::string couleur, int roues);
    virtual ~Vehicule();
    
    virtual void afficher()const;

    virtual int nbr_Roues()const =0; // méthode virtuelle pure

    //static int nombre_vehicules(); pas utile dans ce cas 
    
    protected :
    std::string m_marque;
    std::string m_couleur;
    int m_nbr_roues;

    private:
    int m_id_compteur; // PAS STATIC pour qu'il soit unique à chaque objet créés
    static int m_s_compteur; // STATIC : commun à tous les objets créés
    
};


class Voiture : public Vehicule
{
    public:
    Voiture(std::string marque, std::string couleur, int roues, int portes);
    virtual ~Voiture();
    virtual void afficher()const;
    virtual int nbr_Roues() const;

    private:
    int m_portes;
};

class Moto : public Vehicule
{
    public : 
    Moto(std::string marque, std::string couleur, int roues, int puissance);
    virtual ~Moto();
    virtual void afficher()const;
    virtual int nbr_Roues()const;

    private : 
    int m_puissance;
};

#endif