#pragma once
#include "def.h"
#include "circulo.h"
#include "rectangulo.h"

class ModoGraf
{
private:
	int _gdriver;  
	int _gmode;
	int _errorcode;
	
public:
	//Pasa a modo gráfico. Necesita el path donde está el driver.
	ModoGraf(char * folder);
	// cierra el modo gráfico y vuelve a texto.
	~ModoGraf();
};

/*

		y
		|
top		| .
bottom	|      .
		|
		-------------- x
		left right
*/