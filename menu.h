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
 * que contiene palabras, la cantidad de palabras que contiene y además el puntero a una palabra.
 * Revisa que la palabra no se encuentre en el array.
 * devuelve 0 si no se encuentra.
 */
int palabra_repetida(char **palabras, int contador, char *palabra);

/* 
 * cinco_palabras toma el nombre de un archivo con palabras, lo abre
 * y devuelve un array bidimensional dinámico con 
 * 5 palabras aleatorias que se encuentren dentro del mismo
 */
char** cinco_palabras(const char *nombre_archivo);

/* 
 * elegir_palabra toma un array bidimensional que contiene 5 palabras
 * (se espera que tome el resultado de la función cinco_palabras),
 * muestra las 5 palabras y pregunta al usuario si desea elegir alguna
 * o prefiere volver al menu.
 * Si el usuario selecciona una palabra se devuelve un puntero a la palabra
 * que seleccione, caso contrario se devuelve "ERROR"
 */
char* elegir_palabra(char **opciones);

/* 
 * estar_seguro toma el puntero a una palabra 
 * (se espera que tome el resultado de la funcion elegir_palabra),
 * pregunta si el jugador esta seguro de elegir esa palabra:
 * en caso de que no, devuelve "ERROR"
 * en caso de que si, devuelve la misma palabra
 */
char* estar_seguro(char *palabra);

/*
 * palabra_final toma el nombre de un archivo y guarda en un puntero a char 
 * el resultado de la funcion elegir_palabra con el argumento de cinco_palabras
 * (al que se le da como argumento el nombre del archivo que se toma).
 * Si el resultado de elegir_palabra es "ERROR", devuelve "ERROR".
 * Si no, utiliza la funcion estar_seguro, y devuelve su resultado.
 */
char* palabra_final(const char *nombre_lemario);


/*
 * jugar_partida recibe el puntero a una palabra y prepara todo lo necesario para
 * luego utilizar la funcion jugar_ahorcado (de ahorcado.h) 
 */
int jugar_partida(char *palabra);

/* 
 * rellenar_campos toma un puntero a una variable de tipo Partida 
 * y rellena sus campos con ayuda de los datos proporcionados.
 * Además, suma 1 al contador de partidas ganadas hasta el momento
 */
void rellenar_campos(Partida *partidas, int ganada_perdida, int *cant_ganadas, int cant_partidas, char *palabra);

/* 
 * Se ingresa un número del 1 al 3. 
 *
 * Si es 1 llama a se da la opcion de seleccionar una palabra para jugar 
 * una partida con palabra_final, se juega la partida con jugar_partida
 * y se rellenan los campos de una estructura con rellenar_campos.
 * Luego se vuelve a ingresar un numero.
 *
 * Si es 2 llama a mostrar_historial (de manejo_archivo.h) con los argumentos necesarios. 
 * Luego se vuelve a ingresar un numero.
 *
 * Si es 3 guarda el historial en un archivo con guardar_historial (de manejo_archivo.h).
 * Luego finaliza la funcion menu.
 */
void menu(const char *nombre_lemario, const char *nombre_historial);
#endif
