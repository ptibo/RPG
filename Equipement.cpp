
#include "Equipement.h"

using namespace std;

Equipement::Equipement() : m_niveau(0)
{}

Equipement::Equipement(const string nom, const type_objet type, const unsigned int niveau) : Objet(nom,type), m_niveau(niveau)
{}

// Changer ou ajouter un nouvel équipement
void Equipement::changer_equip(const std::string nom, const type_objet type, const unsigned int niveau){
    changer_obj(nom,type);
    m_niveau=niveau;
}

// Affiche les informations de l'équipement
void Equipement::afficher_equip() const{
    afficher_obj();
    cout << "(Niv." << m_niveau << ")" << endl;
}


unsigned int Equipement::get_niveau() const{
    return m_niveau;
}
