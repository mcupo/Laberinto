#pragma once
#include "def.h"

class Figura
{
public:
	virtual ~Figura(){}
	virtual void dibujar()=0;
	virtual char getTipo()=0; 
};