#ifndef AHORCADO_H
#define AHORCADO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define VIDAS_INICIALES 7
#define LARGO_ABC 28

#ifdef _WIN32_
  #define limpiar "cls"
#else // Linux o MacOS
  #define limpiar "clear"
#endif

  /*
   * Toma los argumentos estándar de C, verifica que se haya ingresado
   * exactamente 1 y devuelve el largo del argumento ingresado
   */
const int palabra_valida(int argc, char const *argv[]);

  /*
   * Toma un tablero y el largo de la palabra secreta *l* y devuelve
   * un array de *l* '-'
   */
void ocultar_palabra(char palabra[], int largo_palabra);

  /*
   * Verifica si la palabra en el tablero coincide con
   * la palabra secreta
   */
int ganadora(char tablero[], char palabra_secreta[]);

  /*
   * Verifica si la letra ingresada se ingresó con anterioridad
   */
int letra_repetida(char letra, char letras_jugadas[]);

  /*
   * Se encarga de pedir por consola una letra que no se haya
   * ingresado antes
   */
char pedir_letra(char letras_jugadas[]);

  /*
   * Se encarga de completar todas las ocurrencias de una letra en el
   * tablero. Además devuelve 1 si encontró por lo menos una ocurrencia
   * en el tablero, 0 en caso contrario.
   */
int rellenar_palabra(char letra, char tablero[], char palabra_secreta[]);

  /*
   * Se encarga de mostrar el tablero actual, el conjunto de letras
   * jugadas y la cantidad actual de vidas con un formato limpio
   */
void mostrar_tablero(char tablero[], char letras_jugadas[], int vidas);

  /*
   * jugar_ahorcado toma una palabra secreta y un tablero inicial
   * y simula una partida de ahorcado completa
   */
void jugar_ahorcado(char *palabra_secreta, char *tablero);

#endif