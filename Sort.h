#ifndef DEF_SORT
#define DEF_SORT

#include "Includes.h"

#define NB_SORTS 5
#define NB_ELEMENTS 6
enum type_sort {NIL, FEU, ELEC, VAPEUR, REPAIR, DESTR};

class Sort
{
    public :

    Sort();
    Sort(const std::string nom, const type_sort type, const unsigned int niveau, const unsigned int puissance, const unsigned int leCout);

    void afficher_infos() const;

    std::string get_nom() const;
    type_sort get_type() const;
    unsigned int get_niveau() const;
    unsigned int get_puissance() const;
    unsigned int get_cout() const;

    /* Récupère le sort de nom nomSort dans le grimoire de sorts */
    /* Renvoie le sort voulu et renvoie NIL s'il n'existe pas*/
    static Sort recuperer_sort(const std::string nomSort);

    private :

    std::string m_nom;
    type_sort m_type;
    unsigned int m_niveau;
    unsigned int m_puissance;
    unsigned int m_cout;
};
static Sort Sorts[NB_SORTS]={
    Sort("Firaga",FEU,1,13,15),Sort("Fatale Foudre",ELEC,1,15,18),Sort("Speed-",VAPEUR,1,0,0),Sort("Heal",REPAIR,1,40,14),Sort("Devisse Boulon",DESTR,1,80,50)
};
#endif
