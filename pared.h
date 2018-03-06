#pragma once
#include "posicion.h"
#include "rectangulo.h"

class Pared : public Posicion
{
private:
	Figura *_pr;
	int _left;
	int _top;
	int _right; 
	int _bottom;

public:
	Pared(Laberinto * l, int x, int y);
	~Pared();
	void dibujar();
	bool esValida();
	char getTipo();
	void setLeft(int left);
	void setTop(int top);
	void setRight(int right);
	void setBottom(int bottom);
};