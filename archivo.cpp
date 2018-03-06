#include "archivo.h"

Archivo::Archivo()
{
	_linea=NULL;
	_linea= new char[MAXCHAR2];
	_c=0;
	_f=0;
}

Archivo::~Archivo()
{
	if(_linea) delete []_linea;
}

int Archivo::AbrirArchLectura(FILE *&Arch)
{

	Arch=fopen("C:\\lab.txt","rt");
	if(Arch==NULL)
	{
		cout<<"No se pudo abrir el Archivo de Entrada.\n";
		return 0;
	}
	else
	{
		return 1;
	}
	
}

int Archivo::AbrirArchEscritura(FILE *&Arch)
{
	Arch=fopen("c:\\labNuevo.txt","wt");
	if(Arch==NULL)
	{
		cout<<"No se pudo abrir el Archivo de Salida.\n";
		return 0;
	}
	else
	{
		return 1;
	}
}

void Archivo::CerrarArch(FILE*&Arch)
{
	fclose(Arch);
}

void Archivo::parser(FILE*&Arch,int mapaTexto[][ANCHO_LAB])
{
	fgets(_linea,MAXLINEA,Arch);
	while (!feof(Arch))
	{
		_token = strtok(_linea,",");
		for(_c=0;_c<ANCHO_LAB;_c++)
		{
			mapaTexto[_f][_c] = atoi(_token);
			_token = strtok(NULL,",");
		}
		_f++;
		fgets(_linea,MAXLINEA,Arch);
	}

	/*Para testear el parser:
	for(_f=0;_f<ALTO_LAB;_f++)
	{
		for(_c=0;_c<ANCHO_LAB;_c++)
		{
			cout<<mapaTexto[_f][_c];
		}
		cout<<"\n";
	}*/
}