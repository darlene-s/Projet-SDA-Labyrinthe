#include "LabyrintheMb.h"
#include "DragonGame.h"

int main(int argc, char* argv[]) {
	LabyrintheMb lab;
	pileAriane dragon;
	initialiser(lab, argc, argv);
	MissionDragonSp3(lab, dragon);
	afficherSp3(lab, dragon);
	detruire(lab);
	return 0;
}