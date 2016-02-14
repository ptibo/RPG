
#include "Personnage.h"

using namespace std;

Personnage::Personnage() : Entite(), m_mana(50), m_mana_max(50), m_XP(0), m_genre(HOMME)
{
}

Personnage::Personnage(const string nom, const Genre genre) : Entite(nom), m_mana(50), m_mana_max(50), m_XP(0), m_genre(genre)
{
}

Personnage::Personnage(const string nom, const Genre genre, const unsigned int niveau, const unsigned int XP=0) : Entite(nom,niveau), m_XP(XP), m_genre(genre)
{
    m_vie=m_vie_max=60+niveau*40;
    m_mana=m_mana_max=35+niveau*15;
}

void Personnage::auto_attack(Entite &cible){
    cout << m_nom << " attaque " << cible.get_nom() << " avec " << m_arme->getNom() << " !" << endl;
    cible.recevoirDegats(m_arme->getDegats());
    if (!cible.estVivant()) cout << cible.get_nom() << " est mort !" << endl;
}

bool Personnage::utiliser_sort(const string nomSort, Entite &cible){
    Sort const leSort = Sort::recuperer_sort(nomSort);
    //On vérifie que le sort de nom nomSort existe bien et est défini
    if (leSort.get_type()!=NIL){
        if(m_mana>=leSort.get_cout()){
            if(leSort.get_type()==REPAIR or leSort.get_type()==VAPEUR){
                cible.recevoirSoin(leSort.get_puissance());
            }
            else{
                cible.recevoirDegats(leSort.get_puissance());
            }
            cout << m_nom << " utilise " << leSort.get_nom() << " sur " << cible.get_nom() << " !" << endl;
            m_mana -= leSort.get_cout();
            return true;
        }
        else{
            cout << m_nom << " tente d'utiliser " << leSort.get_nom() << " sur " << cible.get_nom() << " !" << endl;
            cout << "Pas assez de mana pour lancer ce sort !" << endl;
            return false;
        }
    }
    else {
        cout << m_nom << " essaye d'utiliser :  " << leSort.get_nom() << " sur " << cible.get_nom() << "!" << endl;
        cout << "Le sort " << nomSort << " n'existe pas !" << endl;
        return false;
    }
}

bool Personnage::jouer_tour(vector<Entite *> & allies, vector<Entite *> & ennemis){
    string choix,choix_cible;
    Entite *cible,*a,*e;
    bool ok=false;
    for(unsigned int i=0;i<ennemis.size();i++){
        ennemis[i]->afficherEtat();
        cout << endl;
    }
    for(unsigned int i=0;i<allies.size();i++){
        allies[i]->afficherEtat();
        cout << endl;
    }
    cout << "--> Tour de " << m_nom << " :" << endl;
    cout << "Que faire ?" << endl << "S - Sort, A - Attaquer, F - Fuir" << endl;
    while(!ok){
        ok=true;
        getline(cin,choix);
        switch(choix[0]){
            case 's':
            case 'S':   afficher_menu_sorts();
                        do{
                            cout << "Sort a utiliser : ";
                            getline(cin,choix);
                            do{
                                cout << "Cible : ";
                                getline(cin,choix_cible);
                                e=0;
                                a=0;
                                for(unsigned int i=0;i<ennemis.size();i++){
                                    if(ennemis[i]->get_nom()==choix_cible) e=ennemis[i];
                                }
                                if(e==0){
                                    for(unsigned int i=0;i<allies.size();i++){
                                        if(allies[i]->get_nom()==choix_cible) a=allies[i];
                                    }
                                }
                            }while(e==0 && a==0);
                            if(e!=0) cible=e;
                            else cible=a;
                        }while(!utiliser_sort(choix,*cible));
                        break;
            case 'a':
            case 'A':   cout << "Cible : ";
                        do{
                            getline(cin,choix_cible);
                            e=0;
                            a=0;
                            for(unsigned int i=0;i<ennemis.size();i++){
                                if(ennemis[i]->get_nom()==choix_cible) e=ennemis[i];
                            }
                            if(e==0){
                                for(unsigned int i=0;i<allies.size();i++){
                                    if(allies[i]->get_nom()==choix_cible) a=allies[i];
                                }
                            }
                        }while(e==0 && a==0);
                        if(e!=0) cible=e;
                        else cible=a;
                        auto_attack(*cible);
                        break;
            case 'f':
            case 'F':   return true;
                        break;
            default:    ok=false;
                        break;
        }
    }
    return false;
}

void Personnage::boirePotionDeVie(const unsigned int quantitePotion){
    recevoirSoin(quantitePotion);
}

void Personnage::boirePotionMana(const unsigned int quantitePotion){
    m_mana += quantitePotion;
    if (m_mana > m_mana_max){
        m_mana = m_mana_max;
    }
}

void Personnage::gagnerXP(const unsigned int nbXP){
    unsigned int const seuil=(m_niveau*m_niveau)/2;    //Seuil d'XP pour passer au niveau supérieur
    unsigned int XP_totale=m_XP+nbXP;
    if (XP_totale >= seuil){    //Si on gagne un niveau
        m_niveau += 1;
        m_vie=m_vie_max += 40;
        m_mana=m_mana_max += 15;
        m_XP=0;
        gagnerXP(XP_totale-seuil);
    }
    else m_XP = XP_totale;
}

void Personnage::changerEquipement(const Equipement *nouvelEquipement){
    if(nouvelEquipement->get_niveau()<=m_niveau){
        switch (nouvelEquipement->get_type()){
            case ARME : m_arme=(Arme *)nouvelEquipement; break;
            case COIFFE : m_coiffe=(Equipement *)nouvelEquipement; break;
            case PLASTRON : m_plastron=(Equipement *)nouvelEquipement; break;
            case CAPE : m_cape=(Equipement *)nouvelEquipement; break;
            case ANNEAU : m_anneau=(Equipement *)nouvelEquipement; break;
            case CEINTURE : m_ceinture=(Equipement *)nouvelEquipement; break;
            case JAMBIERES : m_jambieres=(Equipement *)nouvelEquipement; break;
            case CHAUSSURES : m_chaussures=(Equipement *)nouvelEquipement; break;
            default : break;
        }
    }
}

//Renvoie la quantité de cet objet dans l'inventaire (faux si absent) et sa position dans l'inventaire.
//Si l'objet est absent de l'inventaire, indice_inv contient l'indice du premier emplacement libre.
bool Personnage::possedeObjet(const Objet *objet, unsigned int *quantite_inv, unsigned int *indice_inv) const{
    return m_inventaire.contient(objet,quantite_inv,indice_inv);
}

// Ajouter un objet dans l'inventaire
void Personnage::ajouterObjetInventaire(const Objet *nouvelObjet, const unsigned int quantite){
    m_inventaire.ajouterObjet(nouvelObjet,quantite);
    cout << "Ajoute " << quantite << "x" << nouvelObjet->getNom() << " dans l'inventaire de " << m_nom << "." << endl;
}

// Supprimer un objet de l'inventaire
void Personnage::supprimerObjetInventaire(const Objet *objet, const unsigned int quantite){
    int n=m_inventaire.supprimerObjet(objet,quantite);
    cout << "Supprime " << n << "x" << objet->getNom() << " de l'inventaire de " << m_nom << "." << endl;
}

// Affiche les caractéristiques du personnage
void Personnage::afficherEtat() const{
    cout << "Nom : " << m_nom << endl;
    cout << "Niveau : " << m_niveau << " (" << m_XP << " XP)" << endl;
    cout << "Vie : " << m_vie << "/" << m_vie_max << endl;
    cout << "Mana : " << m_mana << "/" << m_mana_max << endl;
}

// Affiche les informations du personnage
void Personnage::afficherInfos() const{
    afficherEtat();
    cout << endl << "Arme : " << endl; m_arme->afficher_infos();
    cout << endl << "Coiffe : " << endl; m_coiffe->afficher_equip();
    cout << endl << "Plastron : " << endl; m_plastron->afficher_equip();
    cout << endl << "Cape : " << endl; m_cape->afficher_equip();
    cout << endl << "Anneau : " << endl; m_anneau->afficher_equip();
    cout << endl << "Ceinture : " << endl; m_ceinture->afficher_equip();
    cout << endl << "Jambieres : " << endl; m_jambieres->afficher_equip();
    cout << endl << "Chaussures : " << endl; m_chaussures->afficher_equip();
}

void Personnage::afficher_menu_sorts() const {
    cout << "Liste des sorts : " << endl << endl;
    Sort Sorts[NB_SORTS]={
        Sort("Firaga",FEU,1,13,15),Sort("Fatale Foudre",ELEC,1,15,18),Sort("Speed-",VAPEUR,1,0,0),Sort("Heal",REPAIR,1,40,14),Sort("Devisse Boulon",DESTR,1,80,50)
    };
    for(unsigned int i=0; i<NB_SORTS; i++){
        if(m_niveau>=Sorts[i].get_niveau()){
            cout << Sorts[i].get_nom() << ": Niv." << Sorts[i].get_niveau() << endl;
            cout << "<type : "<< Sorts[i].get_type() << ">" << endl;
            cout << "Mana : " << Sorts[i].get_cout();
            if(Sorts[i].get_type() == REPAIR or Sorts[i].get_type() == VAPEUR){
                cout << "\tSoigne de " << Sorts[i].get_puissance();
            }
            else{
                cout << "\tInflige " << Sorts[i].get_puissance() << " degats";
            }
        cout << endl << endl;
        }
    }
}

int Personnage::get_res(const type_sort type) const{
    switch (type){
        case NIL : return 0;
        case FEU : return m_res_FEU;
        case ELEC : return m_res_ELEC;
        case VAPEUR : return 0;
        case REPAIR : return 0;
        case DESTR : return m_res_DESTR;
        default : return 0;
    }
}
