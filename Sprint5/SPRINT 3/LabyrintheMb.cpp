#include <assert.h>
#include <iostream>
#include <fstream>
#include "LabyrintheMb.h"

#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds


using namespace std;

void initialiser(LabyrintheMb& lab, int argc, char* argv[]) {
	
	if (argc == 1) return;
	
	lab.face = new TableauMb[lab.NB_FACES];

	unsigned int line, col = 0;

	ifstream myfile;
	char returnline[2];
	myfile.open(argv[1]);


	myfile >> col >> line;



	for (unsigned int i = 0; i < lab.NB_FACES; ++i)
		initialiser(lab.face[i], line, col);

	myfile.getline(returnline, 2);

	for (unsigned int i = 0; i < lab.NB_FACES; i++) {
		
			for (unsigned int k = 0; k < line; k++) {
				myfile.getline((char*)lab.face[i].tabIt[k], col+2);
				
				for (unsigned int l = 0; l < col; l++)
				{

					if (lab.face[i].tabIt[k][l] == 'D')
					{
						lab.entree.line = k;
						lab.entree.col = l;
						lab.entree.face = i;
					}
				}
			
			
		}
	
			myfile.getline(returnline, 2);
	}

	myfile.close();
}

void detruire(LabyrintheMb& lab) {
	for (unsigned int i = 0; i < lab.NB_FACES; ++i)
		detruire(lab.face[i]);

	delete[] lab.face;

}

void afficherSp5(LabyrintheMb& lab, pileAriane& dragon) {
	
	int stp = 0;

	

	if (dragon.plans_du_monde_trouvee)
	{ 
		for (auto v : dragon.filAriane)
		{
			lab.face[v.face].tabIt[v.line][v.col] = 'C';


		}
	}


	cout << lab.face[0].col << " " << lab.face[0].line << endl;
	
	for (unsigned int i = 0; i < lab.NB_FACES; i++) {
		for (unsigned int j = 0; j < lab.face[i].line; j++) {
			for (unsigned int k = 0; k < lab.face[i].col; k++) {

				if (dragon.plans_du_monde_trouvee)
				{
					if (lab.face[i].tabIt[j][k] == 'V') lab.face[i].tabIt[j][k] = '+';
				}
				else
				{
					if (lab.face[i].tabIt[j][k] == 'D') lab.face[i].tabIt[j][k] = '#';
					if (lab.face[i].tabIt[j][k] == '+') lab.face[i].tabIt[j][k] = '#';
					if (lab.face[i].tabIt[j][k] == 'V') lab.face[i].tabIt[j][k] = '#';
				}
				
				cout << lab.face[i].tabIt[j][k];
			}
			cout << endl;
		}
		cout << endl;
	}


	if (dragon.plans_du_monde_trouvee)
	{
		for (auto v : dragon.filAriane)
			cout << "C(" << v.col << "," << v.line << "," << v.face + 1 << ")" << "->";
	}

}