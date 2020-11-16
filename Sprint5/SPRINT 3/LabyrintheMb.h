#ifndef LABYRINTHEMB_H_
#define LABYRINTHEMB_H_

#include "TableauMb.h"
#include "IndexPosition3D.h"


typedef struct {
	enum { NB_FACES = 2 };
	Position entree;
	TableauMb* face;
}LabyrintheMb;

void initialiser(LabyrintheMb& lab, int argc, char* argv[]);
void detruire(LabyrintheMb& lab);
void afficherSp5(LabyrintheMb& lab, pileAriane& dragon);

#endif /* LABYRINTHEMB_H_ */