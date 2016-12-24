#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "levelmap.h"


int main()
{
	printf("main\n");
	srand (time(NULL));
//	printf("Level max %dx%d", LevelMap::MAX_WIDTH, LevelMap::MAX_HEIGHT);
	LevelMap level;
	level.initialize();
	level.addSalle();
	level.addSalle();
	level.addSalle();
	level.addSalle();
	level.addSalle();
	level.addSalle();
	level.dump();
}
