#include <iostream>
#include <string>
#include <SFML/Audio.hpp>

#include "Personnage.h"
#include "Monstre.h"
#include "Combat.h"

using namespace std;

void test_inventaire(){

    Personnage Fanel("Fanel", HOMME, 23, 666);
    Monstre Slime("Slime", 4, 75, 23);
    Fanel.changerEquipement(ARME, "Dague Cassee");
    Fanel.changerEquipement(COIFFE, "Coiffe du Samourai Debutant");
    Fanel.changerEquipement(PLASTRON, "Cotte de Mailles");
    Fanel.changerEquipement(CAPE, "Cape Eritif");
    Fanel.changerEquipement(ANNEAU, "Bague Rose");
    Fanel.changerEquipement(CEINTURE, "Ceinture en Cuir");
    Fanel.changerEquipement(JAMBIERES, "Jambieres en Fer");
    Fanel.changerEquipement(CHAUSSURES, "Spartiates");

    Fanel.afficherInfos();
    cout << endl << endl << endl;
    Slime.afficherEtat();
    cout << endl << endl;
    Fanel.afficherEtat();
    cout << endl << endl;
    Fanel.auto_attack(Slime);
    cout << endl << endl;
    Slime.afficherEtat();
    cout << endl << endl;

    unsigned int a,b;
    Fanel.ajouterObjetInventaire("Dague Cassee", ARME, 42);
    if(Fanel.possedeObjet("Dague Cassee", &a, &b)) cout << "> Dague : indice " << b << ", quantite " << a << endl;
    else cout << "> Pas de Dague trouvee !" << endl;
    cout << endl;
    Fanel.ajouterObjetInventaire("Coiffe du Samourai Debutant", COIFFE, 23);
    if(Fanel.possedeObjet("Coiffe du Samourai Debutant", &a, &b)) cout << "> Coiffe : indice " << b << ", quantite " << a << endl;
    else cout << "> Pas de Coiffe trouvee !" << endl;
    cout << endl;
    Fanel.supprimerObjetInventaire("Coiffe du Samourai Debutant", 22);
    if(Fanel.possedeObjet("Coiffe du Samourai Debutant", &a, &b)) cout << "> Coiffe : indice " << b << ", quantite " << a << endl;
    else cout << "> Pas de Coiffe trouvee !" << endl;
    cout << endl;
    Fanel.supprimerObjetInventaire("Dague Cassee", 66);
    if(Fanel.possedeObjet("Dague Cassee", &a, &b)) cout << "> Dague : indice " << b << ", quantite " << a << endl;
    else cout << "> Pas de Dague trouvee !" << endl;
    cout << endl;
    if(Fanel.possedeObjet("Coiffe du Samourai Debutant", &a, &b)) cout << "> Coiffe : indice " << b << ", quantite " << a << endl;
    else cout << "> Pas de Coiffe trouvee !" << endl;
    cout << endl;
    Fanel.supprimerObjetInventaire("Coiffe du Samourai Debutant", 1);
    if(Fanel.possedeObjet("Coiffe du Samourai Debutant", &a, &b)) cout << "> Coiffe : indice " << b << ", quantite " << a << endl;
    else cout << "> Pas de Coiffe trouvee !" << endl;
}

void test_sort(){
    Personnage Fanel("Fanel", HOMME, 23, 666);
    Monstre Slime("Slime", 4, 75, 23);
    Fanel.afficherInfos();
    cout << endl << endl << endl;
    Fanel.afficherEtat();
    cout << endl << endl << endl;
    Slime.afficherEtat();
    cout << endl << endl;
    cout << endl << endl;
    Fanel.utiliser_sort("Firaga",Slime);
    cout << endl << endl;
    Slime.afficherEtat();
    cout << endl << endl;
    Fanel.utiliser_sort("Fatale foudre",Slime);
    cout << endl << endl;
    Slime.afficherEtat();
    cout << endl << endl;
    Fanel.utiliser_sort("Speed-",Slime);
    cout << endl << endl;
    Slime.afficherEtat();
    cout << endl << endl;
    Fanel.utiliser_sort("Heal",Slime);
    cout << endl << endl;
    Slime.afficherEtat();
    cout << endl << endl;
    Fanel.utiliser_sort("Heal",Fanel);
    Fanel.afficherEtat();
    cout << endl << endl;
    Slime.afficherEtat();
    cout << endl << endl;
    Fanel.utiliser_sort("Firaga",Fanel);
    cout << endl << endl;
    Slime.afficherEtat();
    cout << endl << endl;
    Fanel.utiliser_sort("Sabite",Slime);
    cout << endl << endl;
    Slime.afficherEtat();
    cout << endl << endl;

}

int main()
{
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("Musique_Anouche.ogg")){
        cout<<"Erreur durant le chargement de la musique"<< endl;
        return EXIT_FAILURE; // On ferme le programme
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);
    sound.play();
    test_inventaire();
    //test_sort();
    //test_combat();
    return 0;
}
