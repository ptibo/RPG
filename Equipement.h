
#ifndef DEF_EQUIPEMENT
#define DEF_EQUIPEMENT

#include "Includes.h"

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

    unsigned int get_niveau() const;

    protected:

    unsigned int m_niveau;
};

static Equipement *Bague_Rose=new Equipement("Bague Rose",ANNEAU,1);
static Equipement *Bague_Argentee=new Equipement("Bague Argentee",ANNEAU,10);
static Equipement *Cape_Eritif=new Equipement("Cape Eritif",CAPE,23);
static Equipement *Ceinture_en_Cuir=new Equipement("Ceinture en Cuir",CEINTURE,5);
static Equipement *Tassettes_Abimees=new Equipement("Tassettes Abimees",CEINTURE,2);
static Equipement *String_Rouge=new Equipement("String Rouge",CEINTURE,100);
static Equipement *Spartiates=new Equipement("Spartiates",CHAUSSURES,2);
static Equipement *Tongs=new Equipement("Tongs",CHAUSSURES,1);
static Equipement *Coiffe_du_Samourai_Debutant=new Equipement("Coiffe du Samourai Debutant",COIFFE,1);
static Equipement *Tiare_en_toc=new Equipement("Tiare en Toc",COIFFE,1);
static Equipement *Jambieres_en_Fer=new Equipement("Jambieres en Fer",JAMBIERES,3);
static Equipement *Cotte_de_Mailles=new Equipement("Cotte de Mailles",PLASTRON,12);
static Equipement *Soutif=new Equipement("Soutif",PLASTRON,1);

#endif
