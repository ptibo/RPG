
#ifndef DEF_ARME
#define DEF_ARME

#include "Includes.h"

#include "Equipement.h"

class Arme : public Equipement
{
    public:

    Arme();
    Arme(const std::string nom, const unsigned int niveau, const unsigned int degats);

    // Changer ou ajouter une nouvelle arme
    void changer(const std::string nom, const unsigned int niveau, const unsigned int degats);

    // Affiche les informations de l'arme
    void afficher_infos() const;

    unsigned int getDegats() const;

    private:

    unsigned int m_degats;
};

static Arme *Dague_Cassee=new Arme("Dague Cassee",1,42);

#endif
