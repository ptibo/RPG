
#include "Arme.h"

using namespace std;

Arme::Arme() : Equipement(), m_degats(0)
{}

Arme::Arme(const std::string nom, const unsigned int niveau, const unsigned int degats) : Equipement(nom, ARME, niveau), m_degats(degats)
{}

// Changer ou ajouter une nouvelle arme
void Arme::changer(const string nom, const unsigned int niveau, const unsigned int degats){
    changer_equip(nom, ARME, niveau);
    m_degats=degats;
}

// Affiche les informations de l'arme
void Arme::afficher_infos() const{
    afficher_equip();
    cout << "Degats : " << m_degats << endl;
}

unsigned int Arme::getDegats() const{
    return m_degats;
}
