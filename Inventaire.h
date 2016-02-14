
#ifndef DEF_INVENTAIRE
#define DEF_INVENTAIRE

#include "Includes.h"

#include "Objet.h"

class Inventaire
{
    public:

    Inventaire();

    //Renvoie la quantité de cet objet dans l'inventaire (0 si absent) et sa position dans l'inventaire.
    //Si l'objet est absent de l'inventaire, indice_inv contient l'indice du premier emplacement libre.
    bool contient(const std::string nomObjet, unsigned int *quantite_inv, unsigned int *indice_inv) const;
    // Ajouter un objet dans l'inventaire
    void ajouterObjet(const std::string nomNouvelObjet, const type_objet typeNouvelObjet, const unsigned int quantite);
    // Supprimer un objet de l'inventaire, renvoie la quantite effectivement supprimée
    int supprimerObjet(const std::string nomObjet, const unsigned int quantite);

    private:

    std::vector<Objet> m_objets;
    std::vector<int> m_quantite;
};

#endif
