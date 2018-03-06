#pragma once
#include "def.h"

class Laberinto;

class Posicion
{
private:
	Laberinto	*_l;
	int			_x;
	int			_y;

public:
	Posicion(Laberinto * l,int x, int y);
	virtual ~Posicion(){}
	virtual void dibujar()=0;
	virtual bool esValida()=0;
	virtual char getTipo()=0;
	int getx();
	int gety();
};