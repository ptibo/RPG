
#include "Combat.h"

using namespace std;

void test_combat(){
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
}
