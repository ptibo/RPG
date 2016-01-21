
#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Equipement.h"
#include "Arme.h"
#include "Sort.h"

#include "Entite.h"
#include "Monstre.h"

#define TAILLE_INVENTAIRE 100
#define NB_SORTS 5

enum Genre {HOMME, FEMME};

class Personnage : public Entite
{
    public:

    Personnage();
    Personnage(const std::string nom, const Genre genre);
    Personnage(const std::string nom, const Genre genre, const unsigned int niveau, const unsigned int XP);

    void auto_attack(Entite &cible);

    void utiliser_sort(const std::string nomSort, Entite &cible);

    void boirePotionDeVie(const unsigned int quantitePotion);
    void boirePotionMana(const unsigned int quantitePotion);

    void gagnerXP(const unsigned int nbXP);

    void changerEquipement(type_objet typeNouvelEquipement, std::string nomNouvelEquipement); // Changer ou équiper un nouvel objet

    //Renvoie la quantité de cet objet dans l'inventaire (0 si absent) et sa position dans l'inventaire.
    //Si l'objet est absent de l'inventaire, indice_inv contient l'indice du premier emplacement libre.
    bool possedeObjet(const std::string nomObjet, unsigned int *quantite_inv, unsigned int *indice_inv) const;
    void ajouterObjetInventaire(const std::string nomNouvelObjet, const type_objet typeNouvelObjet, const unsigned int quantite); // Ajouter un objet dans l'inventaire
    void supprimerObjetInventaire(const std::string nomObjet, const unsigned int quantite);  // Supprimer un objet de l'inventaire

    void afficherEtat() const;          //Affiche les caractéristiques du personnage
    void afficherInfos() const;         //Affiche les informations du personnage
    void afficher_menu_sorts() const;   //Affiche les sorts disponibles pour le personnage

    int get_res(const type_sort type) const;

    private:

    unsigned int m_mana, m_mana_max;
    unsigned int m_XP;
    Genre m_genre;

    Arme m_arme;
    Equipement m_coiffe, m_plastron, m_cape, m_anneau, m_ceinture, m_jambieres, m_chaussures;

    int m_res_FEU, m_res_ELEC, m_res_DESTR;
    int m_dmg_FEU, m_dmg_ELEC, m_dmg_DESTR;

    std::vector<Objet> m_inventaire;
    std::vector<int> m_nb_inventaire;
};

#endif
