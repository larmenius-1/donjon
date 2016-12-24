//
// Salle
//

#include "salle.h"

Salle::Salle()
{
}

void Salle::setPosition(int x, int y, int w, int h){
	_x=x;
	_y=y;
	_w=w;
	_h=h;
}

int Salle::getX()
{
	return _x;
}

	int Salle::getY()
{
	return _y;
}

	int Salle::getW()
{
	return _w;
}

	int Salle::getH()
{
	return _h;
}

bool Salle::deborde(Salle salle)
{
	// murs non inclus dans la dimension
	if ((_x+_w+2) < salle.getX())
		return false;
	if (_x > (salle.getX()+salle.getW()+2))
		return false;
	if ((_y+_h+2) < salle.getY())
		return false;
	if (_y > (salle.getY()+salle.getH()+2))
		return false;
	return true;
}
