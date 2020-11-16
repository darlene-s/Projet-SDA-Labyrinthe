#include "LabyrintheMb.h"
#include "DragonGame.h"

int main(int argc, char* argv[]) {
	LabyrintheMb lab;
	pileAriane dragon;
	initialiser(lab, argc, argv);
	MissionDragonSp4(lab, dragon);
	afficherSp4(lab, dragon);
	detruire(lab);
	return 0;
}