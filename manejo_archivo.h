#ifndef MANEJO_ARCHIVO_H
#define MANEJO_ARCHIVO_H

#include <time.h> // Generar numero aleatorio
#include <stdlib.h> // Generar numero aleatorio
#include <stdio.h> // Leer archivo
#include <string.h> // Copiar un string (strcpy)
#include <assert.h> // Verificar que el archivo se abra correctamente

#define LARGO_MAXIMO_PALABRA 20
#define LARGO_MAXIMO_LINEA 50
#define CANT_MAX_PALABRAS 100000

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
 * Crea una estructura con todas las caracteristicas de una partida:
 * numero de partida, la palabra secreta, si se ganó o no y el porcentaje
 * de partidas ganadas hasta el momento
 */
typedef struct {
  int n_partida;
  char *palabra_secreta;
  char ganada[3];
  float porcentaje_ganadas;
} Partida;

/*
 * guardar_historial toma el archivo objeto de historial y la 
 * estructura de la ultima partida jugada y agrega cada caracteristica
 * de esta al historial
 */
void guardar_historial(FILE *historial, Partida ultima_partida){
#endif
