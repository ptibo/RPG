
#ifndef DEF_MONSTRE
#define DEF_MONSTRE

#include <iostream>
#include <string>

#include "Entite.h"

class Monstre : public Entite
{
    public:

    Monstre();
    Monstre(const std::string nom);
    Monstre(const std::string nom, const unsigned int niveau, const unsigned int vie, const unsigned int degats);

    void auto_attack(Entite &cible) const;

    void afficherEtat() const; //Affiche les caractéristiques du Monstre

    private:

    unsigned int m_degats;
};

#endif
