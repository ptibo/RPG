
#ifndef DEF_MONSTRE
#define DEF_MONSTRE

#include "Includes.h"

#include "Entite.h"

class Monstre : public Entite
{
    public:

    Monstre();
    Monstre(const std::string nom);
    Monstre(const std::string nom, const unsigned int niveau, const unsigned int vie, const unsigned int degats);

    void auto_attack(Entite &cible) const;
    virtual bool jouer_tour(std::vector<Entite *> & allies, std::vector<Entite *> & ennemis);

    private:

    unsigned int m_degats;
};

#endif
