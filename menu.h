#ifndef MENU_H
#define MENU_H

#include <time.h> // Generar numero aleatorio
#include <stdlib.h> // Generar numero aleatorio
#include <stdio.h> // Leer archivo
#include <string.h> // Copiar un string (strcpy)
#include <assert.h> // Verificar que el archivo se abra correctamente


/*
 * numero_aleatorio toma 2 enteros (min, max) y devuelve
 * un número aleatorio en el intervalo [min, max]
 */
int generar_numero_aleatorio(int minimo, int maximo);


/* 
 * palabra_no_repetida toma un array bidimensional dinámico
 * que contiene palabras, la cantidad de lapabras que contiene y además una palabra.
 * Revisa que la palabra no se encuentre en el array.
 * devuelve 0 si no se encuentra.
 */
int palabra_repetida(char **palabras, int cant_palabras, char *palabra);

/* 
 * elegir_palabra toma un archivo con palabras y devuelve 
 * un array bidimensional dinámico con 5 palabras aleatorias
 * que se encuentren dentro del mismo
 */
char** cinco_palabras(const char *nombre_archivo);


/* 
 * Se ingresa un número del 1 al 3. 
 * Si es 1 llama a eleccionPalabra(). 
 * Si es 2 llama a mostrarHistorial(). 
 * Si es 3 finaliza la partida y guarda en el historial.
 */
int menu();
#endif

