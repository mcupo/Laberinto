#pragma once
#include "figura.h"

class Circulo : public Figura
{
private:
	int		_x;
	int		_y;
	int		_radio;

public:
	Circulo(){}
	Circulo( int x, int y, int radio);
	~Circulo(){}
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	void setRadio(int radio);
	int getRadio();
	void dibujar();
	char getTipo();
};