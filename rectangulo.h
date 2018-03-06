#pragma once
#include "figura.h"

class Rectangulo : public Figura
{
private:
	int _x1;
	int _y1;
	int _x2;
	int _y2;

public:
	Rectangulo();
	Rectangulo(int x1,int y1,int x2,int y2);
	~Rectangulo(){}
	void setX1(int x1);
	int getX1();
	void setY1(int y1);
	int getY1();
	void setX2(int x2);
	int getX2();
	void setY2(int y2);
	int getY2();
	int getAncho();
	int getAlto();
	void dibujar();
	char getTipo();
};