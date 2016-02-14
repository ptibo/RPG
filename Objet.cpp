
#include "Objet.h"

using namespace std;

Objet::Objet() : m_nom("Undefined"), m_type(NONE)
{}

Objet::Objet(const string nom, const type_objet type) : m_nom(nom), m_type(type)
{}

// Changer ou ajouter un nouvel objet
void Objet::changer_obj(const std::string nom, const type_objet type){
    m_nom=nom;
    m_type=type;
}

// Affiche les informations de l'objet
void Objet::afficher_obj() const{
    cout << m_nom << endl << "Type : ";
    switch(m_type){
        case NONE:cout << "Undefined"; break;
        case RESSOURCE:cout << "Ressource"; break;
        case ARME:cout << "Arme"; break;
        case COIFFE:cout << "Coiffe"; break;
        case PLASTRON:cout << "Plastron"; break;
        case CAPE:cout << "Cape"; break;
        case ANNEAU:cout << "Anneau"; break;
        case CEINTURE:cout << "Ceinture"; break;
        case JAMBIERES:cout << "Jambieres"; break;
        case CHAUSSURES:cout << "Chaussures"; break;
    }
    cout << endl;
}

string Objet::getNom() const{
    return m_nom;
}

type_objet Objet::get_type() const{
    return m_type;
}
