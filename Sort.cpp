
#include "Sort.h"

using namespace std;

Sort::Sort(): m_nom("Undefined"), m_type(NIL), m_niveau(0), m_puissance(0), m_cout(0)
{}
Sort::Sort(const std::string nom, const type_sort type, const unsigned int niveau, const unsigned int puissance, const unsigned int leCout): m_nom(nom), m_type(type), m_niveau(niveau), m_puissance(puissance), m_cout(leCout)
{}

void Sort::afficher_infos() const{
    cout << m_nom << " (Niv." << m_niveau << ")" <<endl << "Type : ";
    switch (m_type){
        case NIL : cout << "Noob skills" <<endl; break;
        case FEU : cout << "FEU"<<endl; break;
        case ELEC : cout << "ELEC"<<endl; break;
        case VAPEUR : cout << "VAPEUR"<<endl; break;
        case REPAIR : cout << "REPAIR"<<endl; break;
        case DESTR : cout << "DESTR"<<endl; break;
        default : break;
    }
    cout << "Puissance : "<< m_puissance<<endl;
    cout << "Cout : "<<m_cout<<endl;
}

std::string Sort::get_nom() const{
    return m_nom;
}

type_sort Sort::get_type() const{
    return m_type;
}

unsigned int Sort::get_niveau() const{
    return m_niveau;
}

unsigned int Sort::get_puissance() const{
    return m_puissance;
}

unsigned int Sort::get_cout() const{
    return m_cout;
}

/* Récupère la sort de nom nomSort dans le répertoire de sort */
/* Renvoie la sort voulue et dans le cas échéant renvoie NIL */
Sort Sort::recuperer_sort(const string nomSort){
    bool ok(true);
    type_sort type(NIL);
    unsigned int niveau(0),puissance(0),leCout(0);
    string line;
    ifstream f;

    f.open("Liste_Sorts.h");
    if(f){
        do{
        ok=getline(f,line);
        }while(ok && line!=nomSort);
        if(ok){
            getline(f,line);
            if(line=="FEU") type=FEU;
            else if(line=="ELEC") type=ELEC;
            else if(line=="VAPEUR") type=VAPEUR;
            else if(line=="REPAIR") type=REPAIR;
            else if(line=="DESTR") type=DESTR;
            f>>niveau;
            f>>puissance;
            f>>leCout;
        }
    }
    else {
        cout <<"ERREUR lors de l'ouverture du fichier" << endl;
    }
    return Sort(nomSort,type,niveau,leCout,puissance);
}
