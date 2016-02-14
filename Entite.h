
#ifndef DEF_ENTITE
#define DEF_ENTITE

#include <iostream>
#include <string>
#include <vector>

class Entite
{
    public:

    Entite();
    Entite(const std::string nom);
    Entite(const std::string nom, const unsigned int niveau);
    Entite(const std::string nom, const unsigned int niveau, const unsigned int vie);

    void recevoirDegats(const unsigned int nbDegats);
    void recevoirSoin(const unsigned int soin);

    bool estVivant() const;
    std::string get_nom() const;

    virtual bool jouer_tour(std::vector<Entite *> & allies, std::vector<Entite *> & ennemis);
    virtual void afficherEtat() const;

    protected:

    std::string m_nom;
    unsigned int m_niveau;
    unsigned int m_vie,m_vie_max;
};

#endif
