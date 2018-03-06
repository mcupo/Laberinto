#include "pared.h"

Pared::Pared(Laberinto * l,int x, int y):Posicion(l,x,y)
{
	setcolor(BROWN);
	setfillstyle(9, BROWN);
	_left=10;
	_top=80;
	_right=25; 
	_bottom=95;
	_pr=NULL;
	_pr=new Rectangulo(
	_left+(LADO*getx()),
	_top+(LADO*gety()),
	_right+(LADO*getx()),
	_bottom+(LADO*gety())
	);
}

Pared::~Pared()
{
	if(_pr)delete _pr;
}

void Pared::dibujar()
{
	_pr->dibujar();
}

char Pared::getTipo()
{
	return 'P';
}

void Pared::setLeft(int left)
{
	_left=left;
}

void Pared::setTop(int top)
{
	_top=top;
}

void Pared::setRight(int right)
{
	_right=right; 
}

void Pared::setBottom(int bottom)
{
	_bottom=bottom;
}

bool Pared::esValida()
{
	return false;
}