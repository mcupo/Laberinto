#include "laberinto.h"
#include "posicion.h"

Laberinto::Laberinto()
{
	_texto=new char[MAXTEXT];
	strcpy(_texto,TITULO);
	_left=0;
	_top=0;
	_right=0;
	_bottom=0;
	_f=0;
	_c=0;
	_x=1;
	_random=0;
	_alto_lab=ALTO_LAB;
	_ancho_lab=ANCHO_LAB;
	for(_f=0;_f<ALTO_LAB;_f++)
	{
		for(_c=0;_c<ANCHO_LAB;_c++)
		{
			_mapa[_f][_c]=NULL;
		}
	}
	_listo=false;
	_ingreso=false;
	_entrada=false;
	_salida=false;
}

Laberinto::~Laberinto()
{
	if(_texto)delete[]_texto;
	for(_f=0;_f<ALTO_LAB;_f++)
	{
		for(_c=0;_c<ANCHO_LAB;_c++)
		{
			if(_mapa[_f][_c]) delete _mapa[_f][_c];
		}
	}
}

void Laberinto::limpiar()
{
	_listo=false;
	_ingreso=false;
	_entrada=false;
	_salida=false;
	_x=1;

	cleardevice();

	for (int _f=0;_f<ALTO_LAB;_f++)
	{
		for(int _c=0;_c<ANCHO_LAB;_c++)
		{
			if(_mapa[_f][_c])
			{
				delete _mapa[_f][_c];
				_mapa[_f][_c] = NULL;
			} 
		} 
	}
}

void Laberinto::mostrarTexto()
{
	setcolor(GREEN);
	outtextxy(250,40,_texto);
}

void Laberinto::mostrarTextoSalida()
{
	outtextxy(250,400,"YOU WIN!");
}

void Laberinto::mostrarTextoSinSalida()
{
	outtextxy(250,400,"GAME OVER");
}

void Laberinto::cargarFijo(Laberinto*l,int mapaTexto[][ANCHO_LAB])
{
	mostrarTexto();
	_top=80;
	_bottom=95;
	for(_f=0;_f<ALTO_LAB;_f++)
	{
		_left=10;
		_right=25;
		for(_c=0;_c<ANCHO_LAB;_c++)
		{
			if(mapaTexto[_f][_c]==0)
			{
				_mapa[_f][_c]=new Pared(l,_c,_f);
				_mapa[_f][_c]->dibujar();
				/*Para testear la creación de los objetos
				cout<<_mapa[_f][_c]->getTipo();*/
			}
			else
			{
				_mapa[_f][_c]=new Camino(l,_c,_f);
				/*Para testear la creación de los objetos
				cout<<_mapa[_f][_c]->getTipo();*/
			}
			_left=_right;
			_right=_left+15;
		}
		cout<<"\n";
		_top=_bottom;
		_bottom=_bottom+15;
	}
}

void Laberinto::cargarRandom(Laberinto*l,int mapaTexto[][ANCHO_LAB])
{
	mostrarTexto();
	randomize();

	//Borde superior
	for(_c=0;_c<ANCHO_LAB;_c++)
	{
		_mapa[0][_c] = new Pared(l,_c,0);
		_mapa[0][_c]->dibujar();
	}

	//Borde inferior
	for(_c=0;_c<ANCHO_LAB;_c++)
	{
		_mapa[ALTO_LAB-1][_c] = new Pared(l,_c,ALTO_LAB-1);
		_mapa[ALTO_LAB-1][_c]->dibujar();
	}

	//Borde izquierdo
	for(_f=1;_f<ALTO_LAB-1;_f++)
	{
		_random = (rand() % 100) + 1;

		//Obligo a generar entrada
		if(!_entrada && _f==ALTO_LAB-2) 
		{ 
			_mapa[_f][0] = new Camino(l,0, _f);
		} 
		else
		{
			//Si arriba hay pared
			if(_mapa[_f-1][0]->getTipo()=='P')
			{
				if(_random<20)
				{ 
					_mapa[_f][0] = new Camino(l,0, _f);
					_entrada = true;
				}
				else
				{ 
					_mapa[_f][0] = new Pared(l,0, _f);
					_mapa[_f][0]->dibujar();
				}
			}else
			{
				//Evito 2 entradas juntas
				_mapa[_f][0] = new Pared(l,0, _f);
				_mapa[_f][0]->dibujar();
			}
		}
	}

	//Centro
	for(_c=1;_c<ANCHO_LAB-1;_c++)
	{
		for(_f=1; _f<ALTO_LAB-1;_f++)
		{
			_random = rand() % 100;
			if(_random>15)
			{
				//Evito generar mucho camino
				if(_mapa[_f-1][_c]->getTipo()=='C' 
				&& _mapa[_f-1][_c-1]->getTipo()=='C' 
				&& _mapa[_f][_c-1]->getTipo()=='C')
				{
					_mapa[_f][_c] = new Pared(l,_c, _f);
					_mapa[_f][_c]->dibujar();
				}
				else
				{
					_mapa[_f][_c] = new Camino(l,_c, _f);
				}
			}
			else
			{
				_mapa[_f][_c] = new Pared(l,_c, _f);
				_mapa[_f][_c]->dibujar();
			}
		}
	} 

	//Borde derecho
	for(_f=1;_f<ALTO_LAB-1;_f++)
	{
		_random = (rand() % 100) + 1;
		
		//Evito laberinto sin salida
		if(!_salida && _f == ALTO_LAB-2)
		{
			//_mapa[_f][ANCHO_LAB-1] = new Camino(l,ANCHO_LAB-1, _f);
		}
		else
		{
			//Si a la izquierda hay pared
			if(_mapa[_f][ANCHO_LAB-2]->getTipo()=='P')
			{
				_mapa[_f][ANCHO_LAB-1] = new Pared(l,ANCHO_LAB-1, _f);
				_mapa[_f][ANCHO_LAB-1]->dibujar();
			}
			else
			{
				if(!_salida && _random<20)
				{
					_mapa[_f][ANCHO_LAB-1] = new Camino(l,ANCHO_LAB-1, _f);
					_salida = true;
				}
				else
				{
					_mapa[_f][ANCHO_LAB-1] = new Pared(l,ANCHO_LAB-1, _f);
					_mapa[_f][ANCHO_LAB-1]->dibujar();
				}
			}
		}
	}

	//Guardo el laberinto generado
	for(int _f=0;_f<ALTO_LAB;_f++)
	{
		for(int _c=0;_c<ANCHO_LAB;_c++)
		{
			if(_mapa[_f][_c]->getTipo()=='P')
			{
				mapaTexto[_f][_c]=0;
			}
			else
			{
				mapaTexto[_f][_c]=1;
			}
		}
	}
}

void Laberinto::contenidoAString(FILE *&Arch,int mapaTexto[][ANCHO_LAB]) 
{

	for(int _f=0;_f<ALTO_LAB;_f++)
	{
		for(int _c=0;_c<ANCHO_LAB;_c++)
		{
			if(_c==ANCHO_LAB-1)
			{
				fprintf(Arch,"%d\n",mapaTexto[_f][_c]);
			}
			else
			{
				fprintf(Arch,"%d,",mapaTexto[_f][_c]);
			}
		}
	}
}

void Laberinto::recorrer(char opcion)
{
	while (!_listo && _x < ALTO_LAB-1)
	{
		if (_mapa[_x][0]->esValida()) //Si la posicion es válida encontró una entrada
		{
			switch(opcion)
			{
				case '1':
				_listo = visitar(_x,0);
				break;

				case '2':
				_listo = visitar2(_x,0);
				break;

				case '3':
				_listo = visitar3(_x,0);
				break;
			}
		}
		_x++;
	}

	if(_listo) 
	{
		mostrarTextoSalida();
	} 
	else
	{
		mostrarTextoSinSalida();
	}
	cin.get();
}

bool Laberinto::visitar(int x, int y)
{
	delay(50);
		
	((Camino*)_mapa[x][y])->cambiarEstado(VISITADO);
	_mapa[x][y]->dibujar();
	
	if(y == ANCHO_LAB-1)
	{
	   _listo = true;
	}

	//Derecha
	if(!_listo && _mapa[x][y+1]->esValida())
	{
	  _listo = visitar(x, y+1);
	}

	//Arriba
	if(!_listo && _mapa[x-1][y]->esValida())
	{
	  _listo = visitar(x-1, y);
	}

	//Abajo
	if(!_listo && _mapa[x+1][y]->esValida())
	{
	   _listo = visitar(x+1, y);
	}

	//Atras
	if(!_listo && y -1 > 0)
	{ 
		if(!_listo && _mapa[x][y-1]->esValida())
		{
			_listo = visitar(x, y-1);
		}
	}

	if(!_listo)
	{
		((Camino*)_mapa[x][y])->cambiarEstado(DESCARTADO);
		delay(30);
		_mapa[x][y]->dibujar();
	}

	return _listo;
}

bool Laberinto::visitar2(int x, int y)
{
	delay(50);
		
	((Camino*)_mapa[x][y])->cambiarEstado(VISITADO);
	_mapa[x][y]->dibujar();
	
	if(y == ANCHO_LAB-1)
	{
	   _listo = true;
	}

	//Arriba
	if(!_listo && _mapa[x-1][y]->esValida())
	{
	  _listo = visitar2(x-1, y);
	}

	//Derecha
	if(!_listo && _mapa[x][y+1]->esValida())
	{
	  _listo = visitar2(x, y+1);
	}

	//Abajo
	if(!_listo && _mapa[x+1][y]->esValida())
	{
	   _listo = visitar2(x+1, y);
	}

	//Atras
	if(!_listo && y -1 > 0)
	{ 
		if(!_listo && _mapa[x][y-1]->esValida())
		{
			_listo = visitar2(x, y-1);
		}
	}

	if(!_listo)
	{
		((Camino*)_mapa[x][y])->cambiarEstado(DESCARTADO);
		delay(30);
		_mapa[x][y]->dibujar();
	}

	return _listo;
}

bool Laberinto::visitar3(int x, int y)
{
	delay(50);
		
	((Camino*)_mapa[x][y])->cambiarEstado(VISITADO);
	_mapa[x][y]->dibujar();
	
	if(y == ANCHO_LAB-1)
	{
	   _listo = true;
	}

	//Abajo
	if(!_listo && _mapa[x+1][y]->esValida())
	{
	   _listo = visitar3(x+1, y);
	}

	//Arriba
	if(!_listo && _mapa[x-1][y]->esValida())
	{
	  _listo = visitar3(x-1, y);
	}

	//Derecha
	if(!_listo && _mapa[x][y+1]->esValida())
	{
	  _listo = visitar3(x, y+1);
	}

	//Atras
	if(!_listo && y -1 > 0)
	{ 
		if(!_listo && _mapa[x][y-1]->esValida())
		{
			_listo = visitar3(x, y-1);
		}
	}

	if(!_listo)
	{
		((Camino*)_mapa[x][y])->cambiarEstado(DESCARTADO);
		delay(30);
		_mapa[x][y]->dibujar();
	}

	return _listo;
}