#include "main.h"

int main(int argc, char const *argv[]) {

  if (argc != 3) {
    printf("Uso del ejecutable: %s <lemario> <historial>\n", argv[0]);
    return 1;
  }

  FILE *lemario = abrir_archivo(argv[1], "r");
  char **palabras_validas = malloc(sizeof(char*) * CANT_MAX_PALABRAS);
  int cant_palabras = leer_palabras(lemario, palabras_validas);
  fclose(lemario);
  
  int numero_aleatorio = generar_numero_aleatorio(0, cant_palabras);
  printf("%d - %d\n", numero_aleatorio, cant_palabras);
  // mostrar_palabras(palabras_validas, cant_palabras);

  int largo_palabra_secreta = strlen(palabras_validas[numero_aleatorio]);
  char *palabra_secreta = malloc(sizeof(char) * (largo_palabra_secreta + 1));
  strcpy(palabra_secreta, palabras_validas[numero_aleatorio]);

  /* char *tablero = malloc(sizeof(char) * (largo_palabra_secreta + 1));
  inicializar_tablero(tablero, largo_palabra_secreta); */
  
  jugar_ahorcado(palabra_secreta, tablero);
  
  free(palabra_secreta);
  free(tablero);
  liberar_array_bidimensional(palabras_validas, cant_palabras);//liberar memoria de la palabra secreta y del tablero
}
