#ifndef TABLEAUMB_H_
#define TABLEAUMB_H_

#include "Item.h"


typedef struct {
	unsigned int line, col;
	ItemMb** tabIt;

}TableauMb;

void initialiser(TableauMb& tab, unsigned int line, unsigned int col);
void detruire(TableauMb& tab);


#endif /* TABLEAUMB_H_ */