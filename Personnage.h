
#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include "Includes.h"

#include "Entite.h"
#include "Monstre.h"

#include "Equipement.h"
#include "Arme.h"
#include "Sort.h"
#include "Inventaire.h"

enum Genre {HOMME, FEMME};

class Personnage : public Entite
{
    public:

    Personnage();
    Personnage(const std::string nom, const Genre genre);
    Personnage(const std::string nom, const Genre genre, const unsigned int niveau, const unsigned int XP);

    void auto_attack(Entite &cible);
    //Utilise le sort nomSort sur cible. Renvoie vrai si tout s'est bien pass�, faux sinon.
    bool utiliser_sort(const std::string nomSort, Entite &cible);
    //Fait jouer un tour de combat au personnage. Renvoie vrai si le personnage a pris la fuite.
    virtual bool jouer_tour(std::vector<Entite *> & allies, std::vector<Entite *> & ennemis);

    void boirePotionDeVie(const unsigned int quantitePotion);
    void boirePotionMana(const unsigned int quantitePotion);

    void gagnerXP(const unsigned int nbXP);

    void changerEquipement(const Equipement *nouvelEquipement); // Changer ou �quiper un nouvel objet

    //Renvoie la quantit� de cet objet dans l'inventaire (0 si absent) et sa position dans l'inventaire.
    //Si l'objet est absent de l'inventaire, indice_inv contient l'indice du premier emplacement libre.
    bool possedeObjet(const Objet *objet, unsigned int *quantite_inv, unsigned int *indice_inv) const;
    void ajouterObjetInventaire(const Objet *nouvelObjet, const unsigned int quantite); // Ajouter un objet dans l'inventaire
    void supprimerObjetInventaire(const Objet *objet, const unsigned int quantite);  // Supprimer un objet de l'inventaire

    virtual void afficherEtat() const;  //Affiche les caract�ristiques du personnage
    void afficherInfos() const;         //Affiche les informations du personnage
    void afficher_menu_sorts() const;   //Affiche les sorts disponibles pour le personnage

    int get_res(const type_sort type) const;

    private:

    unsigned int m_mana, m_mana_max;
    unsigned int m_XP;
    Genre m_genre;

    Arme *m_arme;
    Equipement *m_coiffe, *m_plastron, *m_cape, *m_anneau, *m_ceinture, *m_jambieres, *m_chaussures;

    int m_dmg_FEU, m_dmg_ELEC, m_dmg_DESTR;
    int m_res_FEU, m_res_ELEC, m_res_DESTR;

    Inventaire m_inventaire;
};

#endif
