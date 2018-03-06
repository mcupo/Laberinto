#include "modograf.h"

ModoGraf::ModoGraf(char * folder) 
{
	// prepara los atributos de la clase
	_gdriver = DETECT;
	initgraph(&_gdriver, &_gmode, folder);
	// lee el resultado de la inicializaci�n
	_errorcode = graphresult();
	if (_errorcode != grOk) // pas� algo 
	{
		cout << "Error al pasar al modo gr�fico:" << grapherrormsg(_errorcode) << "\n";
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
