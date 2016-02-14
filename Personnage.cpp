
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
    cout << m_nom << " attaque " << cible.get_nom() << " avec " << m_arme.getNom() << " !" << endl;
    cible.recevoirDegats(m_arme.getDegats());
    if (!cible.estVivant()) cout << cible.get_nom() << " est mort !" << endl;
}

bool Personnage::utiliser_sort(const string nomSort, Entite &cible){
    Sort const leSort = Sort::recuperer_sort(nomSort);
    //On v�rifie que le sort de nom nomSort existe bien et est d�fini
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
                            cin >> choix;
                            do{
                                cout << "Cible : ";
                                cin >> choix_cible;
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
                            cin >> choix_cible;
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
    unsigned int const seuil=(m_niveau*m_niveau)/2;    //Seuil d'XP pour passer au niveau sup�rieur
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

void Personnage::changerEquipement(const type_objet typeNouvelEquipement, const std::string nomNouvelEquipement){
    string line;
    unsigned int niveau, degats_arme;
    bool ok;
    ifstream f;
    switch (typeNouvelEquipement){ //Ouverture de la liste des equipements
        case ARME : f.open("Liste_Armes.h"); break;
        case COIFFE : f.open("Liste_Coiffes.h"); break;
        case PLASTRON : f.open("Liste_Plastrons.h"); break;
        case CAPE : f.open("Liste_Capes.h"); break;
        case ANNEAU : f.open("Liste_Anneaux.h"); break;
        case CEINTURE : f.open("Liste_Ceintures.h"); break;
        case JAMBIERES : f.open("Liste_Jambieres.h"); break;
        case CHAUSSURES : f.open("Liste_Chaussures.h"); break;
        default : break;
    }
    if(f){
        do{ //On cherche l'equipement demand�
            ok=getline(f,line);
        }while(ok && line != nomNouvelEquipement);
        if(ok){ //si il existe, on l'�quipe
            if(typeNouvelEquipement!=ARME) getline(f,line); // Les armes sont mixtes
            else line="MIXTE";
            if(line=="MIXTE" || (line=="HOMME" && m_genre==HOMME) || (line=="FEMME" && m_genre==FEMME)){ // On v�rifie que le personnage a le bon genre
                f >> niveau;
                if(niveau<=m_niveau){
                    switch (typeNouvelEquipement){ //Ouverture de la liste des equipements
                        case ARME : f >> degats_arme; m_arme.changer(nomNouvelEquipement, niveau, degats_arme); break;
                        case COIFFE : m_coiffe.changer_equip(nomNouvelEquipement, COIFFE, niveau); break;
                        case PLASTRON : m_plastron.changer_equip(nomNouvelEquipement, PLASTRON, niveau); break;
                        case CAPE : m_cape.changer_equip(nomNouvelEquipement, CAPE, niveau); break;
                        case ANNEAU : m_anneau.changer_equip(nomNouvelEquipement, ANNEAU, niveau); break;
                        case CEINTURE : m_ceinture.changer_equip(nomNouvelEquipement, CEINTURE, niveau); break;
                        case JAMBIERES : m_jambieres.changer_equip(nomNouvelEquipement, JAMBIERES, niveau); break;
                        case CHAUSSURES : m_chaussures.changer_equip(nomNouvelEquipement, CHAUSSURES, niveau); break;
                        default : break;
                    }
                }
            }
        }
    }
    else cout << "ERROR while opening file" << endl;
    f.close();
}

//Renvoie la quantit� de cet objet dans l'inventaire (faux si absent) et sa position dans l'inventaire.
//Si l'objet est absent de l'inventaire, indice_inv contient l'indice du premier emplacement libre.
bool Personnage::possedeObjet(const string nomObjet, unsigned int *quantite_inv, unsigned int *indice_inv) const{
    return m_inventaire.contient(nomObjet,quantite_inv,indice_inv);
}

// Ajouter un objet dans l'inventaire
void Personnage::ajouterObjetInventaire(const std::string nomNouvelObjet, const type_objet typeNouvelObjet, const unsigned int quantite){
    m_inventaire.ajouterObjet(nomNouvelObjet,typeNouvelObjet,quantite);
    cout << "Ajoute " << quantite << "x" << nomNouvelObjet << " dans l'inventaire de " << m_nom << "." << endl;
}

// Supprimer un objet de l'inventaire
void Personnage::supprimerObjetInventaire(const std::string nomObjet, const unsigned int quantite){
    int n=m_inventaire.supprimerObjet(nomObjet,quantite);
    cout << "Supprime" << n << "x" << nomObjet << " de l'inventaire de " << m_nom << "." << endl;
}

// Affiche les caract�ristiques du personnage
void Personnage::afficherEtat() const{
    cout << "Nom : " << m_nom << endl;
    cout << "Niveau : " << m_niveau << " (" << m_XP << " XP)" << endl;
    cout << "Vie : " << m_vie << "/" << m_vie_max << endl;
    cout << "Mana : " << m_mana << "/" << m_mana_max << endl;
}

// Affiche les informations du personnage
void Personnage::afficherInfos() const{
    afficherEtat();
    cout << endl << "Arme : " << endl; m_arme.afficher_infos();
    cout << endl << "Coiffe : " << endl; m_coiffe.afficher_equip();
    cout << endl << "Plastron : " << endl; m_plastron.afficher_equip();
    cout << endl << "Cape : " << endl; m_cape.afficher_equip();
    cout << endl << "Anneau : " << endl; m_anneau.afficher_equip();
    cout << endl << "Ceinture : " << endl; m_ceinture.afficher_equip();
    cout << endl << "Jambieres : " << endl; m_jambieres.afficher_equip();
    cout << endl << "Chaussures : " << endl; m_chaussures.afficher_equip();
}

void Personnage::afficher_menu_sorts() const {
    string spell, type;
    char trash;
    ifstream f;
    unsigned int niveau, mana, puissance;
    f.open("Liste_Sorts.h");
    if (f){
        cout << "Liste des sorts : " << endl << endl;
        while(getline(f,spell)){
            getline(f,type);
            f >> niveau;
            f >> mana;
            f >> puissance;
            f.get(trash);   //Pour passer � la ligne suivante apr�s avoir lu des entiers
            if(m_niveau>=niveau){
                cout << spell << ": Niv." << niveau << endl;
                cout << "<type : "<< type << ">" << endl;
                cout << "Mana : " << mana;
                if(type == "REPAIR" or type == "VAPEUR"){
                    cout << "\tSoigne de " << puissance;
                }
                else cout << "\tInflige " << puissance << " degats";
                cout << endl << endl;
            }
        }
    }
    else {
        cout << "Erreur lors de l'ouverture du fichier : Liste_Sorts.h" << endl;
    }
    f.close();
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
