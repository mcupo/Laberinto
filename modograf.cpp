#include "modograf.h"

ModoGraf::ModoGraf(char * folder) 
{
	// prepara los atributos de la clase
	_gdriver = DETECT;
	initgraph(&_gdriver, &_gmode, folder);
	// lee el resultado de la inicialización
	_errorcode = graphresult();
	if (_errorcode != grOk) // pasó algo 
	{
		cout << "Error al pasar al modo gráfico:" << grapherrormsg(_errorcode) << "\n";
		cout << "Pulse una tecla para terminar:";
		getch();
	}
}

ModoGraf::~ModoGraf()
{
	closegraph();
}

/*
(20)|479
 y1	|.
 y2 |   .
	|
	 --------------
	  x1 x2 639 (40)
14x14
*/
