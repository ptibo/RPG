
#ifndef DEF_OBJET
#define DEF_OBJET

#include <iostream>
#include <string>
#include <fstream>

// Un objet fait partie de ces catégories
enum type_objet {NONE, RESSOURCE, ARME, COIFFE, PLASTRON, CAPE, ANNEAU, CEINTURE, JAMBIERES, CHAUSSURES};

class Objet
{
    public:

    Objet();
    Objet(const std::string nom, const type_objet type);

    // Changer ou ajouter un nouvel objet
    void changer_obj(const std::string nom, const type_objet type);

    // Affiche les informations de l'objet
    void afficher_obj() const;

    std::string getNom() const;

    protected:

    std::string m_nom;
    type_objet m_type;
};

#endif
