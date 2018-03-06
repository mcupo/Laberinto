#include "interfaz.h"

Interfaz::Interfaz()
{
	_opcion='\0';
	_opcion2='\0';
	_a=NULL;
	_l=NULL;
	_mg=NULL;
	_ArchE=NULL;
	_ArchS=NULL;
	_a=new Archivo;
	_l=new Laberinto;
	menu();
}

Interfaz::~Interfaz()
{
	cout<<"¿Desea guardar el ultimo laberinto generado (S/N)?:";
	cin>>_opcion;
	_opcion=toupper(_opcion);
	if(_opcion=='S')
	{
		if(_a->AbrirArchEscritura(_ArchS))
		{
			_l->contenidoAString(_ArchS,_mapaTexto);
			_a->CerrarArch(_ArchS);
			cout<<"El archivo se guardo correctamente!\n";
		}
	}
	if(_a)delete _a;
	if(_l)delete _l;
	if(_mg)delete _mg;
}

void Interfaz::menu()
{
	do
	{
		cout<<"1. Para leer un laberinto desde el disco.\n";
		cout<<"2. Para generar un laberinto al azar.\n";
		cout<<"3. Para guardar el laberinto generado(luego de haber generado un laberinto).\n";
		cout<<"4. Para salir.\n";
		cout<<"Ingrese una opcion:";
		cin>>_opcion;
		switch(_opcion)
		{
			case '1':
			case '2':
				subMenu();
				break;

			case '3':
				if(_a->AbrirArchEscritura(_ArchS))
				{
					_l->contenidoAString(_ArchS,_mapaTexto);
					_a->CerrarArch(_ArchS);
					cout<<"El archivo se guardo correctamente!\n";
				}
				break;
		}
	}
	while(_opcion!='4');
}

void Interfaz::subMenu()
{
	do
	{
		cout<<"1. Para recorrer el laberinto utilizando el metodo 1(Derecha, arriba y abajo).\n";
		cout<<"2. Para recorrer el laberinto utilizando el metodo 2(Arriba, derecha y abajo).\n";
		cout<<"3. Para recorrer el laberinto utilizando el metodo 3(Abajo, arriba y derecha).\n";
		cout<<"0. Para volver al menu principal\n";
		cout<<"Ingrese una opcion:";
		cin>>_opcion2;
		if(_opcion2!='0'&&(_opcion2=='1')||(_opcion2=='2')||(_opcion2=='3'))
		{
			if(_mg)delete _mg;
			_mg=new ModoGraf("C:\\Taller\Cmasmas\T3\TPFINAL\bgi");

			if(_opcion=='1')
			{
				_a->AbrirArchLectura(_ArchE);
				_a->parser(_ArchE,_mapaTexto);
				_a->CerrarArch(_ArchE);
				_l->cargarFijo(_l,_mapaTexto);
				_l->recorrer(_opcion2);
			}
			if(_opcion=='2')
			{
				_l->cargarRandom(_l,_mapaTexto);
				_l->recorrer(_opcion2);
			}
			cout<<"Presione una tecla para continuar.\n";
			cin.get();
			_l->limpiar();
		}
	}
	while(_opcion2!='0');
}