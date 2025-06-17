#include "Guerrier.hpp"

using namespace std;

Guerrier::Guerrier(string nom):Personnage(nom)
{
} // le compilateur appelle le constructeur de la classe fille, qui appelle le constructeur de la classe mère. Donc le constructeur de la classe mère est exécuté avant le constructeur de la classe fille


void Guerrier::coupDeHache(Personnage &cible)
{
    cible.recevoirDegats(30);
}