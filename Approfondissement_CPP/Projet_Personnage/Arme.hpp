#include <string>

class Arme 
{
    public :
    Arme();
    Arme(std::string nom, int degats, int mana);
    ~Arme();

    void changer(std::string nvl_arme, int degats_nvl_arme, int mana_nvl_arme);
    void afficher() const;
    int getDegats() const;
    int getMana() const;

    private : 
    std::string m_nom;
    int m_degats;
    int m_mana_arme;
};