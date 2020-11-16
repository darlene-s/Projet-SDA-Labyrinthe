#ifndef INDEXPOSITION3D_H_
#define INDEXPOSITION3D_H_
#include <stack>
#include <list>



typedef struct {
	unsigned int line, col, face;
}Position;

typedef struct {
	unsigned int face;
	unsigned int size;
	Position caseVisit;
	std::list<Position> filAriane;
	std::stack<Position> pile;
}pileAriane;

void initialiserPos(pileAriane& coord, unsigned int line, unsigned int col, unsigned int face);

#endif /* INDEXPOSITION3D_H_ */