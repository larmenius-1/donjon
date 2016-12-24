#include "levelmap.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

LevelMap::LevelMap()
{
	_nbSalles=0;
	
	printf("create\n");
}

void LevelMap::initialize()
{
	printf("init\n");
	// murs sur le pourtour
	for(int i=0; i<LEVEL_MAX_WIDTH; i++)
		_terrain[i][0]=_terrain[i][LEVEL_MAX_HEIGHT-1]='#';
	for(int i=0; i<LEVEL_MAX_HEIGHT; i++)
		_terrain[0][i]=_terrain[LEVEL_MAX_WIDTH-1][i]='#';
	// terrain indéfini
	for(int i=1; i<LEVEL_MAX_WIDTH-1; i++)
		for(int j=1; j<LEVEL_MAX_HEIGHT-1; j++)
			_terrain[i][j]=' ';
}

void LevelMap::dump()
{
	printf("\n");
	for(int i=0; i<LEVEL_MAX_HEIGHT; i++)
		{
		for(int j=0; j<LEVEL_MAX_WIDTH; j++)
			printf("%c ",_terrain[j][i]);
		printf("\n");
		}
}

int alea(int min,int max)
{
//	return (new Random()).Next(min,max);
	return min+rand()%(max - min +1);
}

void LevelMap::addSalle()
{
	Salle *salle=new Salle();
	bool ok=false;
	int x,y,w,h;
	// coordonnees
	while (!ok)
		{
		x=alea(2,LEVEL_MAX_WIDTH-SALLE_MAX_WIDTH-2);
		y=alea(2,LEVEL_MAX_HEIGHT-SALLE_MAX_HEIGHT-2);
		w=alea(2,SALLE_MAX_WIDTH);
		h=alea(2,SALLE_MAX_HEIGHT);
		printf("%d %d\n",w,h);
		salle->setPosition(x,y,w,h);
		ok=true;

		for (int i=0;ok && i<_nbSalles;i++)
			if (salle->deborde(_salles.at(i)))
				ok=false;

		if (ok)
			{
			_salles.push_back(*salle);
			_nbSalles++;
				// murs sur le pourtour
			for(int i=x; i<x+w+2; i++)
				_terrain[i][y]=_terrain[i][y+h+1]='#';
			for(int i=y; i<y+h+2; i++)
				_terrain[x][i]=_terrain[x+w+1][i]='#';
			// terrain indéfini1
			for(int i=x+1; i<x+w+1; i++)
				for(int j=y+1; j<y+h+1; j++)
					_terrain[i][j]='.';
			}
		}
}

