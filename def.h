#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graphics.h"

using namespace std;

#define MAXCHAR2		255
#define	MAXTEXT			50
#define ALTO_LAB		20
#define ANCHO_LAB		40
#define LADO			15
#define RADIO			4
#define MAXLINEA 		255
#define TITULO			"El juego del laberinto"
#define randomize() (srand( (unsigned)time( NULL )) )
#define random(range) (rand() % (range))

enum estado
{
	LIBRE=0, 
	VISITADO,
	DESCARTADO
};