#include "rectangulo.h"

Rectangulo::Rectangulo()
{
	_x1=0;
	_y1=0;
	_x2=0;
	_y2=0;
}

Rectangulo::Rectangulo(int x1,int y1,int x2,int y2)
{
	_x1=x1;
	_y1=y1;
	_x2=x2;
	_y2=y2;
}

void Rectangulo::setX1(int x1)
{
	_x1=x1;
}

int Rectangulo::getX1()
{
	return _x1;
}

void Rectangulo::setY1(int y1)
{
	_y1=y1;
}

int Rectangulo::getY1()
{
	return _y1;
}

void Rectangulo::setX2(int x2)
{
	_x2=x2;
}

int Rectangulo::getX2()
{
	return _x2;
}

void Rectangulo::setY2(int y2)
{
	_y2=y2;
}

int Rectangulo::getY2()
{
	return _y2;
}

int Rectangulo::getAncho()
{
	return _x2-_x1;
}

int Rectangulo::getAlto()
{
	return _y2-_y1;
}

void Rectangulo::dibujar()
{
	bar3d(_x1,_y1,_x2,_y2,0,0);
}

char Rectangulo::getTipo()
{
	return 'R';
}