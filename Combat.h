#ifndef DEF_COMBAT
#define DEF_COMBAT

#include <iostream>
#include <string>
#include <vector>

#include "Monstre.h"
#include "Personnage.h"

bool equipe_morte(std::vector<Entite *> & equipe);
void lancer_combat(std::vector<Entite *> & attaquants, std::vector<Entite *> & defenseurs);
void test_combat();

#endif
