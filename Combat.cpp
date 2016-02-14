
#include "Combat.h"

using namespace std;

bool equipe_morte(vector<Entite *> & equipe){
    for(unsigned int i=0;i<equipe.size();i++){
        if(equipe[i]->estVivant()) return false;
    }
    return true;
}

void lancer_combat(vector<Entite *> & attaquants, vector<Entite *> & defenseurs){
    unsigned int n_att=0,n_def=0;
    bool fin;
    while(!fin && !equipe_morte(attaquants) && !equipe_morte(defenseurs)){
        fin=attaquants[n_att]->jouer_tour(attaquants,defenseurs);
        do{
            n_att=(n_att+1)%attaquants.size();
        }while(!attaquants[n_att]->estVivant());
        cout << endl;
        if(!fin && !equipe_morte(defenseurs) && !equipe_morte(attaquants)){
            fin=defenseurs[n_def]->jouer_tour(defenseurs,attaquants);
            do{
                n_def=(n_def+1)%defenseurs.size();
            }while(!defenseurs[n_def]->estVivant());
            cout << endl;
        }
    }
}

void test_combat(){
    vector<Entite *> personnages, monstres;
    Personnage Fanel("Fanel", HOMME, 9, 642);
    Monstre Magicarpe("Magicarpe", 1, 100, 11);
    Fanel.changerEquipement(ARME, "Dague Cassee");
    personnages.push_back(&Fanel);
    monstres.push_back(&Magicarpe);
    lancer_combat(personnages,monstres);
}

/*void test_combat(){
    Personnage Fanel("Fanel", HOMME, 9, 642);
    Monstre Magicarpe("Magicarpe", 1, 100, 11);
    string choice("Buanderie"),mag("Firaga"),cible("Pomme sur la tête du fils de Guillaume Tell");
    bool fin_combat = false;
    Fanel.changerEquipement(ARME, "Dague Cassee");
    //Fanel.afficherInfos();
    cout << "SIMULATION D'UN COMBAT FULL BOLOSSAGE DE FANEL" << endl << "Press q to quit"<<endl;
    cout << endl << endl;
    Fanel.afficherEtat();
    cout << endl << endl;
    Magicarpe.afficherEtat();
    cout << endl << endl;
    while (!fin_combat){
        cout << "***********************************************************"<< endl;
        cout << "Tour de Fanel : " << endl;
        cout << "***********************************************************"<< endl;
        cout << "'Sort' pour aggresser le Magicarpe fabuleusement\n'Attaquer' pour aggresser le Magicarpe sauvagement"<< endl;
        cout << "'Quit' ou 'q' pour ragequit\n\nQue faire? : ";
        getline(cin,choice);
        while (choice != "Sort" and choice!= "Attaquer" and choice!= "Quit" and choice!="q"){
            cout << endl << endl;
            cout << "Je n'ai pas bien compris votre choix" << endl;
            cout << "Choisissez : \n'Sort' pour aggresser le Magicarpe magicalement\n'Attaquer' pour aggresser le magicarpe physiquement"<<endl;
            cout << "'Quit' ou 'q' pour ragequit\nQue faire? : ";
            getline(cin,choice);
        }
        if (choice == "Quit" or choice == "q"){
            fin_combat = true;
        }
        else{
            if (choice == "Sort"){
                cout << endl;
                Fanel.afficher_menu_sorts();
                cout << "Nom du sort a utiliser : " ;
                getline(cin,mag);
                cout << endl;
                cout << "Cible : ";
                getline(cin,cible);
                cout << endl << endl;
                if(cible=="Magicarpe"){
                    Fanel.utiliser_sort(mag,Magicarpe);
                }
                else if (cible=="Fanel"){
                    Fanel.utiliser_sort(mag,Fanel);
                }
                cout << endl << endl;
            }
            else{
                cout << endl << endl;
                Fanel.auto_attack(Magicarpe);
                cout << endl << endl;
            }
            Magicarpe.afficherEtat();
            if (Magicarpe.estVivant()){
                cout << endl;
                cout << "***********************************************************"<< endl;
                cout << "Tour de Magicarpe-sensei : " << endl;
                cout << "***********************************************************"<< endl << endl;
                Magicarpe.auto_attack(Fanel);
                cout << endl;
                Fanel.afficherEtat();
                cout << endl;
            }
            else {
                cout << endl;
                cout << "Vous, Fanel, avez tue Magicarpe-sensei!!! Soyez maudit par la sainte pelle!" << endl;
                fin_combat = true;
            }
        }
    }
    cout << endl << endl;
    cout << "Merci d'avoir joue avec Fanel et Magicarpe-sensei *HUGS*" <<endl;
}*/
