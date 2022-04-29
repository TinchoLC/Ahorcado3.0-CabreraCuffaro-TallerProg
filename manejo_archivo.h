#ifndef MANEJO_ARCHIVO_H
#define MANEJO_ARCHIVO_H

#include <time.h> // Generar numero aleatorio
#include <stdlib.h> // Generar numero aleatorio
#include <stdio.h> // Leer archivo
#include <string.h> // Copiar un string (strcpy)
#include <assert.h> // Verificar que el archivo se abra correctamente

#define LARGO_MAXIMO_PALABRA 20
#define LARGO_MAXIMO_LINEA 80
#define CANT_MAX_PALABRAS 100000
#define CANT_MAX_PARTIDAS 10

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
 * guardar_historial toma el nombre de archivo del historial, la cantidad de partidas jugadas y la 
 * estructura de las partidas jugadas, abre el archivo
 * y agrega cada caracteristica de estas al historial
 */
void guardar_historial(const char *historial, Partida* ult_part, int cant_partidas);

/*
 * mostrar_historial toma el nombre del historial, lo abre, y muestra
 * su contenido
 */
void mostrar_historial(Partida* ult_part, int cant_partidas);

#endif
