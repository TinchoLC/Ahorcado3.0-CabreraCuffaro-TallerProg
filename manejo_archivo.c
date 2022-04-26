#include "manejo_archivo.h"

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

void guardar_historial(const char *historial, Partida ult_part){
  FILE *hist = abrir_archivo(historial, "W+");
  fprintf(hist, "+-------------------+-------------------------+--------+--------------------+\n");
  fprintf(hist, "| %17d | %23s |   %s   | %.2f%%              |\n", ult_part.n_partida, ult_part.palabra_secreta, ult_part.ganada, ult_part.porcentaje_ganadas);
  fclose(hist);
}

void mostrar_historial(const char *historial){
  char **lineas;
  FILE *hist = abrir_archivo(historial, "r");
  int cant_lineas = leer_palabras(hist, lineas);
  
  printf("+-------------------+-------------------------+--------+--------------------+\n"); //70 caracteres
  printf("| Numero de partida |     Palabra Secreta     | Ganada | Porcentaje Ganadas |\n");
  for(int a = 0; a < cant_lineas; printf("%s", *lineas), lineas++, a++);
  printf("+-------------------+-------------------------+--------+--------------------+\n");
}
