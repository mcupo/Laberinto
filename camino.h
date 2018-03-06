#include "posicion.h"
#include "circulo.h"

class Camino : public Posicion
{
private:
	Figura *_pc;
	estado _estado;
	int	_xInicial;
	int _yInicial;


public:
	Camino(Laberinto * _l, int _x, int _y);
	~Camino();
	void cambiarEstado(estado nuevoEstado);
	void dibujar();
	bool esValida();
	char getTipo();
	int getEstado();
	
};