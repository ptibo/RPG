
#include "Monstre.h"

using namespace std;


Monstre::Monstre() : Entite()
{}

Monstre::Monstre(const string nom) : Entite(nom)
{}

Monstre::Monstre(const string nom, const unsigned int niveau, const unsigned int vie, const unsigned int degats) : Entite(nom,niveau,vie), m_degats(degats)
{}

void Monstre::auto_attack(Entite &cible) const{
    cout << m_nom << " attaque " << cible.get_nom() << " !" << endl;
    cible.recevoirDegats(m_degats);
    if (!cible.estVivant()) cout << cible.get_nom() << " est mort !" << endl;
}

// Affiche les caractéristiques du Monstre
void Monstre::afficherEtat() const{
    cout << "Nom : " << m_nom << endl;
    cout << "Niveau : " << m_niveau << endl;
    cout << "Vie : " << m_vie << "/" << m_vie_max << endl;
}
