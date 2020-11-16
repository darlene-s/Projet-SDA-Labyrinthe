#include "DragonGame.h"
#include <iostream>
#include <string>
using namespace std;

int Dir[][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

void initialiser(pileAriane& dragon) {
	dragon.tabAriane = new Position[dragon.pile.size()];

}

void detruire(pileAriane& dragon) {
	
}

void testMoveRelat(LabyrintheMb& lab, pileAriane& dragon, int d) {
	
	if (
		(dragon.caseVisit.line + Dir[d][1]) >=0 &&
		(dragon.caseVisit.col + Dir[d][0]) >=0 &&
		(dragon.caseVisit.line + Dir[d][1]) < lab.face[dragon.caseVisit.face].line &&
		(dragon.caseVisit.col + Dir[d][0]) < lab.face[dragon.caseVisit.face].col &&
		lab.face[dragon.caseVisit.face].tabIt[dragon.caseVisit.line + Dir[d][1]][dragon.caseVisit.col + Dir[d][0]] == '+')
	{
		Position caseValide;
		caseValide.line = dragon.caseVisit.line + Dir[d][1];
		caseValide.col = dragon.caseVisit.col + Dir[d][0];
		caseValide.face = dragon.face;
		
		dragon.pile.push(caseValide);
		
	}
}

void MissionDragonSp2(LabyrintheMb& lab, pileAriane& dragon) {
	
	initialiserPos(dragon, lab.entree.line, lab.entree.col, lab.entree.face);
		dragon.caseVisit.line = lab.entree.line;
		dragon.caseVisit.col = lab.entree.col;
		dragon.caseVisit.face = lab.entree.face;
		dragon.face = lab.entree.face;


	dragon.pile.push(dragon.caseVisit);
	for (unsigned int i = 0; i < 10; i++) {
		char num = i + '0';
		lab.face[dragon.caseVisit.face].tabIt[dragon.caseVisit.line][dragon.caseVisit.col] = num;

		for (int j = OUEST; j <= NORD_OUEST; j++)
			testMoveRelat(lab, dragon,j);

		initialiserPos(dragon, dragon.pile.top().line, dragon.pile.top().col, dragon.pile.top().face);
		if (i < 9) {
			dragon.pile.pop();
		}
	}
	initialiser(dragon);
	dragon.size = dragon.pile.size() - 1;
	for (unsigned int i = 0; i < dragon.size; ++i) {
		dragon.tabAriane[i] = dragon.pile.top();
		dragon.pile.pop();
	}
}