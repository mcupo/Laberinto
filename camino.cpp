#include "camino.h"

Camino::Camino(Laberinto * l,int x, int y):Posicion(l,x,y)
{
	_estado=LIBRE;
	_xInicial=18;
	_yInicial=88;
	_pc=NULL;
}

Camino::~Camino()
{
	if(_pc)delete _pc;
}

char Camino::getTipo()
{
	return 'C';
}

bool Camino::esValida()
{
	if(_estado==LIBRE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Camino::getEstado()
{
	return _estado;
}

void Camino::cambiarEstado(estado nuevoEstado)
{
	_estado=nuevoEstado;
}

void Camino::dibujar()
{
	_pc=new Circulo(
	_xInicial+(LADO*getx()),
	_yInicial+(LADO*gety()),
	RADIO
	);
	if(_estado==VISITADO)
	{
		setcolor(GREEN);
		setfillstyle(1, GREEN);
		_pc->dibujar();
	}
	if(_estado==DESCARTADO)
	{
		setcolor(RED);
		setfillstyle(1, RED);
		_pc->dibujar();
	}
}