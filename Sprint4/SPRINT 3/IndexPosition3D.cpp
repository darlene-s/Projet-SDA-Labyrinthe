#include "IndexPosition3D.h"
#include <iostream>
#include <string>
using namespace std;

void initialiserPos(pileAriane& dragon, unsigned int line, unsigned int col, unsigned int face) {

	dragon.caseVisit.line = line;
	dragon.caseVisit.col = col;
	dragon.caseVisit.face = face;
}