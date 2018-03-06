#include "posicion.h"
#include "pared.h"
#include "camino.h"

class Laberinto
{
private:	
	Posicion	*_mapa[ALTO_LAB][ANCHO_LAB];
	char		*_texto;
	int			_alto_lab;
	int			_ancho_lab;
	bool		_listo;
	bool		_ingreso;
	int			_left;
	int			_top;
	int			_right;
	int			_bottom;
	int			_f;
	int			_c;
	int			_x; 
	int			_random;
	bool		_entrada;
	bool		_salida; 
	
public:
	Laberinto();
	~Laberinto();
	void cargarFijo(Laberinto*l,int mapaTexto[][ANCHO_LAB]);
	void cargarRandom(Laberinto*l,int mapaTexto[][ANCHO_LAB]);
	void contenidoAString(FILE *&Arch,int mapaTexto[][ANCHO_LAB]);
	void recorrer(char opcion);
	void mostrarTexto();
	void mostrarTextoSalida();
	void mostrarTextoSinSalida();
	bool visitar(int x, int y);
	bool visitar2(int x, int y);
	bool visitar3(int x, int y);
	void limpiar();
};