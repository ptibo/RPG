
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
    m_vie -= nbDegats;
    if (m_vie < 0){
        m_vie = 0;
    }
    else if (m_vie > m_vie_max){
        m_vie = m_vie_max;
    }
}

void Entite::recevoirSoin(const unsigned int soin){
    m_vie += soin;
    if (m_vie > m_vie_max){
        m_vie = m_vie_max;
    }
    else if (m_vie < 0){
        m_vie = 0;
    }
}

bool Entite::estVivant() const{
    return m_vie > 0;
}

string Entite::get_nom() const{
    return m_nom;
}
