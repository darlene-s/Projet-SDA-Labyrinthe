#include "DragonGame.h"
#include <iostream>
#include <string>
using namespace std;

int Dir[][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

void initialiser(pileAriane& dragon) {
	
}

void detruire(pileAriane& dragon) {
	
}



bool estConnexe(LabyrintheMb& lab,pileAriane& dragon, Position& caseVisit) {

	if (!dragon.filAriane.empty())
	{
		
		for (int d = OUEST; d <= NORD_OUEST; d++)
		{

			int l = dragon.filAriane.front().line + Dir[d][1];
			int c = dragon.filAriane.front().col + Dir[d][0];
			int f = dragon.filAriane.front().face;

			if (c < 0)
			{
				c = lab.face[dragon.caseVisit.face].col - 1;
				l = dragon.caseVisit.line;
				f = (f + 1) % 2;
			}

			if (c >= lab.face[dragon.caseVisit.face].col)
			{
				c = 0;
				l = dragon.caseVisit.line;
				f = (f + 1) % 2;
			}

			if (c == caseVisit.col && l == caseVisit.line && caseVisit.face == f) return true;
		}
	}

	return false;
}

void testMoveRelat(LabyrintheMb& lab, pileAriane& dragon) {

	dragon.pile.push(dragon.caseVisit);

	dragon.plans_du_monde_trouvee = false;
	
	while (
			 dragon.plans_du_monde_trouvee == false &&
			!dragon.pile.empty()
		)
	{
		initialiserPos(dragon, dragon.pile.top().line, dragon.pile.top().col, dragon.pile.top().face);
		dragon.pile.pop();

		while (!dragon.filAriane.empty() && !estConnexe(lab,dragon, dragon.caseVisit)) 
			dragon.filAriane.pop_front();

		dragon.filAriane.push_front(dragon.caseVisit);

		for (int d = OUEST; d <= NORD_OUEST; d++)
		{
			int l = dragon.caseVisit.line + Dir[d][1];
			int c = dragon.caseVisit.col + Dir[d][0];
			int f = dragon.caseVisit.face;

			if (c < 0)
			{
				c = lab.face[dragon.caseVisit.face].col - 1;
				l = dragon.caseVisit.line;
				f = (f + 1) % 2;
			}

			if (c >= lab.face[dragon.caseVisit.face].col)
			{
				c = 0;
				l = dragon.caseVisit.line;
				f = (f + 1) % 2;
			}

			if (
				l >= 0 &&
				c >= 0 &&
				l < lab.face[dragon.caseVisit.face].line &&
				c < lab.face[dragon.caseVisit.face].col )
				
			{
				if (lab.face[f].tabIt[l][c] == '+' || lab.face[f].tabIt[l][c] == 'P')
				{
					Position caseValide;
					caseValide.line = l;
					caseValide.col = c;
					caseValide.face = f;

					dragon.pile.push(caseValide);

				}

				
				
			}

		}


		if (lab.face[dragon.caseVisit.face].tabIt[dragon.caseVisit.line][dragon.caseVisit.col] == 'P')
			dragon.plans_du_monde_trouvee = true;
		

		lab.face[dragon.caseVisit.face].tabIt[dragon.caseVisit.line][dragon.caseVisit.col] = 'V';

	
	}
	

	
	
}

void MissionDragonSp5(LabyrintheMb& lab, pileAriane& dragon) {
	
	initialiserPos(dragon, lab.entree.line, lab.entree.col, lab.entree.face);
		dragon.caseVisit.line = lab.entree.line;
		dragon.caseVisit.col = lab.entree.col;
		dragon.caseVisit.face = lab.entree.face;
		dragon.face = lab.entree.face;

	

	testMoveRelat(lab, dragon);

}

