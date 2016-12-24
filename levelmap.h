//
// Level Map
//

#ifndef __level_map_h__
#define __level_map_h__

#include <vector>
#include "salle.h"

using namespace std;

#define LEVEL_MAX_WIDTH 64
#define LEVEL_MAX_HEIGHT 50

#define MIN_SALLE_BY_LEVEL 3
#define MAX_SALLE_BY_LEVEL 9

class LevelMap
{
public :
	LevelMap();

	void initialize();

	void addSalle();

	void dump();

private :
	vector<Salle> _salles;
	int _nbSalles;	

	char _terrain[LEVEL_MAX_WIDTH][LEVEL_MAX_HEIGHT];

};

#endif
