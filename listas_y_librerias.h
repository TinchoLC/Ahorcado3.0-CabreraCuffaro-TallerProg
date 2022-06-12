#ifndef LISTAS_Y_LIBRERIAS_H
#define LISTAS_Y_LIBRERIAS_H

#include <stdlib.h>
#include <stdio.h>

/* 
 * Usaremos la estructura SNodo
 * para trabajar con los datos
 */
typedef struct _SNodo {
	char *provincia;
	int v_habitadas;
	int v_deshabitadas;
	int v_colectivas;
	struct _SNodo *sig;
} SNodo; 

/* 
 * Como vamos a utilizar muchos punteros a Snodo, 
 * es efectivo crear una definición para estos.
 */
typedef SList *Snodo;

#endif