#ifndef MENU_H
#define MENU_H

#include <time.h> // Generar numero aleatorio
#include <stdlib.h> // Generar numero aleatorio
#include <stdio.h> // Leer archivo
#include <string.h> // Copiar un string (strcpy)
#include <assert.h> // Verificar que el archivo se abra correctamente

#define LARGO_MAXIMO_PALABRA 20
#define LARGO_MAXIMO_LINEA 50
#define CANT_MAX_PALABRAS 100000

/*
 * numero_aleatorio toma 2 enteros (min, max) y devuelve
 * un número aleatorio en el intervalo [min, max]
 */
int generar_numero_aleatorio(int minimo, int maximo);

/*
 * abrir_archivo toma la ruta de un archivo y el modo en el que
 * se quiere abrir y devuelve el archivo objeto resultado de
 * abrirlo en dicho modo
 */
FILE* abrir_archivo(const char *nombre_archivo, char *modo);

/*
 * leer_palabras toma un archivo objeto y un array bidimensional
 * vacio de palabras y guarda cada linea del archivo asociado
 * en el array. Devuelve la cantidad de lineas leidas
 */
int leer_palabras(FILE *archivo_objeto, char **palabras_validas);

/*
 * liberar_array_bidimensional toma un array bidimensional dinámico y
 * una de sus dimensiones y libera la memoria pedida
 */
void liberar_array_bidimensional(char **palabras_validas, int cant_palabras);

/*
 * mostrar_palabras toma un array bidimensional dinámico y
 * una de sus dimensiones y muestra por salida estandar las palabras
 */
void mostrar_palabras(char **palabras, int cant_palabras);

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
char** elegir_palabra(const char *nombre_archivo);


/* 
 * Se ingresa un número del 1 al 3. 
 * Si es 1 llama a eleccionPalabra(). 
 * Si es 2 llama a mostrarHistorial(). 
 * Si es 3 finaliza la partida y guarda en el historial.
 */
int menu();
#endif

