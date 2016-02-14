
#include "Inventaire.h"

using namespace std;

Inventaire::Inventaire()
{}

//Renvoie la quantité de cet objet dans l'inventaire (faux si absent) et sa position dans l'inventaire.
//Si l'objet est absent de l'inventaire, indice_inv contient l'indice du premier emplacement libre.
bool Inventaire::contient(const string nomObjet, unsigned int *quantite_inv, unsigned int *indice_inv) const{
    unsigned int i=0;
    string nom_inv;
    bool found=false;
    while(i<m_objets.size() && !found){
        nom_inv=m_objets[i].getNom();
        if(nom_inv == nomObjet){
            *quantite_inv=m_quantite[i];  //Si on trouve, on renvoie la quantité correspondante
            *indice_inv=i;
            found=true;
        }
        i++;
    }
    return found;
}

// Ajouter un objet dans l'inventaire
void Inventaire::ajouterObjet(const string nomNouvelObjet, const type_objet typeNouvelObjet, const unsigned int quantite){
    string line;
    unsigned int quantite_inv, indice_inv;
    bool ok;
    ifstream f;
    switch (typeNouvelObjet){ //Ouverture de la liste des equipements
        case ARME : f.open("Liste_Armes.h"); break;
        case COIFFE : f.open("Liste_Coiffes.h"); break;
        case PLASTRON : f.open("Liste_Plastrons.h"); break;
        case CAPE : f.open("Liste_Capes.h"); break;
        case ANNEAU : f.open("Liste_Anneaux.h"); break;
        case CEINTURE : f.open("Liste_Ceintures.h"); break;
        case JAMBIERES : f.open("Liste_Jambieres.h"); break;
        case CHAUSSURES : f.open("Liste_Chaussures.h"); break;
        case RESSOURCE : f.open("Liste_Ressources.h"); break;
        default : break;
    }
    if(f){
        do{ //On cherche l'objet demandé
            ok=getline(f,line);
        }while(ok && line != nomNouvelObjet);
        if(ok){ //si il existe, on l'ajoute dans l'inventaire
            if(this->contient(nomNouvelObjet, &quantite_inv, &indice_inv)){
                m_quantite[indice_inv]+=quantite;
            }
            else{
                m_quantite.push_back(quantite);
                m_objets.push_back(Objet(nomNouvelObjet,typeNouvelObjet));
            }
        }
    }
    else cout << "ERROR while opening file" << endl;
    f.close();
}

// Supprimer un objet de l'inventaire, renvoie la quantite effectivement supprimée
int Inventaire::supprimerObjet(const string nomObjet, const unsigned int quantite){
    unsigned int indice_inv, quantite_inv;
    if(this->contient(nomObjet, &quantite_inv, &indice_inv)){
        if(quantite_inv<=quantite){
            m_quantite.erase(m_quantite.begin()+indice_inv);
            m_objets.erase(m_objets.begin()+indice_inv);
            return quantite_inv;
        }
        else{
            m_quantite[indice_inv]-=quantite;
            return quantite;
        }
    }
    return 0;
}
