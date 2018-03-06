#include "posicion.h"
#include "laberinto.h"

Posicion::Posicion(Laberinto * l,int x, int y)
{
	_l=l;
	_x=x;
	_y=y;
}

int Posicion::getx()
{
	return _x;
}

int Posicion::gety()
{
	return _y;
}