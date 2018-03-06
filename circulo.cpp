#include "circulo.h"

Circulo::Circulo(int x,int y,int radio)
{
	_x=x;
	_y=y;
	_radio=radio;
}

void Circulo::setX(int x)
{
	_x=x;
}

int Circulo::getX()
{
	return _x;
}

void Circulo::setY(int y)
{
	_y=y;
}

int Circulo::getY()
{
	return _y;
}

void Circulo::setRadio(int radio)
{
	_radio=radio;
}

int Circulo::getRadio()
{
	return _radio;
}

void Circulo::dibujar()
{
	fillellipse(_x, _y, RADIO, RADIO);
}

char Circulo::getTipo()
{
	return 'C';
}