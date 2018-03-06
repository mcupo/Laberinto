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
	//Pasa a modo gr�fico. Necesita el path donde est� el driver.
	ModoGraf(char * folder);
	// cierra el modo gr�fico y vuelve a texto.
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