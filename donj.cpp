//
// Donjon
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "levelmap.h"
#include "util.h"


int main()
{
	printf("main\n");
	srand (time(NULL));
//	printf("Level max %dx%d", LevelMap::MAX_WIDTH, LevelMap::MAX_HEIGHT);
	LevelMap level;
	level.initialize();

	int nbSalles=alea(MIN_SALLE_BY_LEVEL,MAX_SALLE_BY_LEVEL);
	for (int i=0; i<nbSalles; i++)
		level.createSalle();

	level.dump();
}
