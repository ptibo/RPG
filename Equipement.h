
#ifndef DEF_EQUIPEMENT
#define DEF_EQUIPEMENT

#include <iostream>
#include <string>

#include "Objet.h"

class Equipement : public Objet
{
    public:

    Equipement();
    Equipement(const std::string nom, const type_objet type, const unsigned int niveau);

    // Changer ou ajouter un nouvel équipement
    void changer_equip(const std::string nom, const type_objet type, const unsigned int niveau);

    // Affiche les informations de l'équipement
    void afficher_equip() const;

    protected:

    unsigned int m_niveau;
};

#endif
