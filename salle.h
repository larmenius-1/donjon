#ifndef __salle_h__
#define __salle_h__

#include <vector>
#include <stdbool.h>

using namespace std;


typedef pair<int,int> Coord;

#define SALLE_MAX_WIDTH 8
#define SALLE_MAX_HEIGHT 8

class Salle
{
public :
	Salle();
	
	void setPosition(int x, int y, int w, int h);

	int getX();
	int getY();
	int getW();
	int getH();

	bool deborde(Salle salle);

private:
	int _x;
	int _y;
	int _w;
	int _h;
	vector<Coord> _portes;
};

#endif
