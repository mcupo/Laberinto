#include "laberinto.h"
#include "archivo.h"
#include "modograf.h"

class Interfaz
{
private:
	Laberinto	*_l;
	Archivo		*_a;
	ModoGraf	*_mg;
	FILE		*_ArchE;
	FILE		*_ArchS;
	char		_opcion;
	char		_opcion2;
	int			_mapaTexto[ALTO_LAB][ANCHO_LAB];

public:
	Interfaz();
	~Interfaz();
	void menu();
	void subMenu();
};