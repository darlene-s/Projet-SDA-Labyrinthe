#include <assert.h>
#include "TableauMb.h"

void initialiser(TableauMb& tab, unsigned int line, unsigned int col) {
	assert(line > 0 & col > 0);
	tab.line = line;
	tab.col = col;

	tab.tabIt = new ItemMb * [line];

	// alloue col caractères + 3 caractères ('\0','\n','\r')
	for (unsigned int i = 0; i < line; ++i) {
		tab.tabIt[i] = new ItemMb[col+3];
	}

}

void detruire(TableauMb& tab) {
	for (unsigned int i = 0; i < tab.line; ++i) {
		delete[] tab.tabIt[i];
	}
	delete[] tab.tabIt;
}