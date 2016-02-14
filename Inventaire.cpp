
#include "Inventaire.h"

using namespace std;

Inventaire::Inventaire()
{}

//Renvoie la quantité de cet objet dans l'inventaire (faux si absent) et sa position dans l'inventaire.
//Si l'objet est absent de l'inventaire, indice_inv contient l'indice du premier emplacement libre.
bool Inventaire::contient(const Objet *objet, unsigned int *quantite_inv, unsigned int *indice_inv) const{
    unsigned int i=0;
    bool found=false;
    while(i<m_objets.size() && !found){
        if(m_objets[i] == objet){
            *quantite_inv=m_quantite[i];  //Si on trouve, on renvoie la quantité correspondante
            *indice_inv=i;
            found=true;
        }
        i++;
    }
    return found;
}

// Ajouter un objet dans l'inventaire
void Inventaire::ajouterObjet(const Objet *nouvelObjet, const unsigned int quantite){
    unsigned int quantite_inv, indice_inv;
    if(this->contient(nouvelObjet, &quantite_inv, &indice_inv)){
        m_quantite[indice_inv]+=quantite;
    }
    else{
        m_quantite.push_back(quantite);
        m_objets.push_back((Objet *)nouvelObjet);
    }
}

// Supprimer un objet de l'inventaire, renvoie la quantite effectivement supprimée
int Inventaire::supprimerObjet(const Objet *objet, const unsigned int quantite){
    unsigned int indice_inv, quantite_inv;
    if(this->contient(objet, &quantite_inv, &indice_inv)){
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
