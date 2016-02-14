
#include "Personnage.h"
#include "Monstre.h"
#include "Combat.h"

using namespace std;

void test_inventaire(){

    Personnage Fanel("Fanel", HOMME, 23, 666);
    Fanel.changerEquipement(Dague_Cassee);
    Fanel.changerEquipement(Coiffe_du_Samourai_Debutant);
    Fanel.changerEquipement(Cotte_de_Mailles);
    Fanel.changerEquipement(Cape_Eritif);
    Fanel.changerEquipement(Bague_Rose);
    Fanel.changerEquipement(Ceinture_en_Cuir);
    Fanel.changerEquipement(Jambieres_en_Fer);
    Fanel.changerEquipement(Spartiates);
    Fanel.afficherInfos();

    unsigned int a,b;
    Fanel.ajouterObjetInventaire(Dague_Cassee,42);
    if(Fanel.possedeObjet(Dague_Cassee, &a, &b)) cout << "> Dague : indice " << b << ", quantite " << a << endl;
    else cout << "> Pas de Dague trouvee !" << endl;
    cout << endl;
    Fanel.ajouterObjetInventaire(Coiffe_du_Samourai_Debutant, 23);
    if(Fanel.possedeObjet(Coiffe_du_Samourai_Debutant, &a, &b)) cout << "> Coiffe : indice " << b << ", quantite " << a << endl;
    else cout << "> Pas de Coiffe trouvee !" << endl;
    cout << endl;
    Fanel.supprimerObjetInventaire(Coiffe_du_Samourai_Debutant, 22);
    if(Fanel.possedeObjet(Coiffe_du_Samourai_Debutant, &a, &b)) cout << "> Coiffe : indice " << b << ", quantite " << a << endl;
    else cout << "> Pas de Coiffe trouvee !" << endl;
    cout << endl;
    Fanel.supprimerObjetInventaire(Dague_Cassee, 66);
    if(Fanel.possedeObjet(Dague_Cassee, &a, &b)) cout << "> Dague : indice " << b << ", quantite " << a << endl;
    else cout << "> Pas de Dague trouvee !" << endl;
    cout << endl;
    if(Fanel.possedeObjet(Coiffe_du_Samourai_Debutant, &a, &b)) cout << "> Coiffe : indice " << b << ", quantite " << a << endl;
    else cout << "> Pas de Coiffe trouvee !" << endl;
    cout << endl;
    Fanel.supprimerObjetInventaire(Coiffe_du_Samourai_Debutant, 1);
    if(Fanel.possedeObjet(Coiffe_du_Samourai_Debutant, &a, &b)) cout << "> Coiffe : indice " << b << ", quantite " << a << endl;
    else cout << "> Pas de Coiffe trouvee !" << endl;
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
    //sound.play();

    test_combat();
    test_inventaire();
    return 0;
}
