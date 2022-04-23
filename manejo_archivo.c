#include "manejo_archivo.h"

typedef struct {
  int n_partida;
  char *palabra_secreta;
  char ganada[3];
  float porcentaje_ganadas;
} Partida;


FILE* abrir_archivo(const char *nombre_archivo, char *modo) {
  FILE *archivo = fopen(nombre_archivo, modo);
  assert(archivo != NULL);
  
  return archivo;
}

int leer_palabras(FILE *archivo_objeto, char **palabras_validas) {
  char linea[LARGO_MAXIMO_LINEA]; // se usara de buffer

  int cant_palabras = 0;
  int largo_linea = 0;
  for(int i = 0; EOF != fscanf(archivo_objeto, "%s\n", linea); i++) {
    largo_linea = strlen(linea);
    palabras_validas[i] = malloc(sizeof(char) * (largo_linea + 1));
    strncpy(palabras_validas[i], linea, largo_linea);
    palabras_validas[i][largo_linea] = '\0';
    cant_palabras++;
  }

  return cant_palabras;
}

void liberar_array_bidimensional(char **palabras_validas, int cant_palabras){
  for (int i = 0; i < cant_palabras; free(palabras_validas[i++]));
  free(palabras_validas);
}

void mostrar_palabras(char **palabras, int cant_palabras){
  for (int i = 0; i < cant_palabras; printf("%s\n", palabras[i++]));
}

void guardar_historial(FILE *historial, Partida ultima_partida){
  fprintf("Numero de partida: %d", ultima_partida.n_partida);
  fprintf("Palabra Secreta: %s", ultima_partida.palabra_secreta);
  fprintf("Partida ganada: %s", ultima_partida.ganada);
  fprintf("Porcentaje de partidas ganadas: %.2f%%", ultima_partida.porcentaje_ganadas);
}
