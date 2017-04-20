//
// Salle
//

// les murs ne sont pas inclus dans la dimension

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

void Salle::createPorte()
{
	int mur=alea(1,4);	// NESO
	Coord *porte=new Coord();
	switch(mur) 
		{
		case 1 :	// mur nord
			porte->first=alea(_x+1,_x+_w);
			porte->second=_y;
			break ;
		case 2 :	// mur est
			porte->first=_x+_w+1;
			porte->second=alea(_y+1,_y+_h);
			break ;
		case 3 :	// mur sud
			porte->first=alea(_x+1,_x+_w);
			porte->second=_y+_h+1;
			break ;
		case 4 :	// mur ouest
			porte->first=_x;
			porte->second=alea(_y+1,_y+_h);
			break ;
		}
			
	_portes.push_back(*porte);
}

Coord Salle::getPorte()
{
	// if (!_portes.empty())
		return _portes.at(0);
	// return NULL;	// defaut qui plante
}


