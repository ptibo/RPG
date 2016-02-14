
#include "Entite.h"

using namespace std;


Entite::Entite() : m_nom("Undefined entity"), m_niveau(1), m_vie(100), m_vie_max(100)
{}

Entite::Entite(const string nom) : m_nom(nom), m_niveau(1), m_vie(100), m_vie_max(100)
{}

Entite::Entite(const string nom, const unsigned int niveau) : m_nom(nom), m_niveau(niveau), m_vie(100), m_vie_max(100)
{}

Entite::Entite(const string nom, const unsigned int niveau, const unsigned int vie) : m_nom(nom), m_niveau(niveau), m_vie(vie), m_vie_max(vie)
{}

void Entite::recevoirDegats(const unsigned int nbDegats){
    if (m_vie < nbDegats){
        m_vie = 0;
    }
    else{
        m_vie -= nbDegats;
    }
}

void Entite::recevoirSoin(const unsigned int soin){
    m_vie += soin;
    if (m_vie > m_vie_max){
        m_vie = m_vie_max;
    }
}

bool Entite::jouer_tour(vector<Entite *> & allies, vector<Entite *> & ennemis){
    cout << "Impossible de jouer un tour pour une entite" << endl;
    return true;
}

void Entite::afficherEtat() const{
    cout << "Nom : " << m_nom << endl;
    cout << "Niveau : " << m_niveau << endl;
    cout << "Vie : " << m_vie << "/" << m_vie_max << endl;
}

bool Entite::estVivant() const{
    return m_vie != 0;
}

string Entite::get_nom() const{
    return m_nom;
}
