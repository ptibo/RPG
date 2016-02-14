
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

bool Monstre::jouer_tour(vector<Entite *> & allies, vector<Entite *> & ennemis){
    srand(time(NULL));
    int cible=rand()%ennemis.size();
    while(!ennemis[cible]->estVivant()) cible+=cible%ennemis.size();
    auto_attack(*(ennemis[cible]));
    return false;
}
