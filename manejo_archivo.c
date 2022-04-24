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

void guardar_historial(const char *historial, Partida ultima_partida){
  FILE *hist = abrir_archivo(historial, "W+");
  fprintf(hist, "Numero de partida: %d", ultima_partida.n_partida);
  fprintf(hist, "Palabra Secreta: %s", ultima_partida.palabra_secreta);
  fprintf(hist, "Partida ganada: %s", ultima_partida.ganada);
  fprintf(hist, "Porcentaje de partidas ganadas: %.2f%%", ultima_partida.porcentaje_ganadas);
  fclose(hist);
}

void copiar_desde(char* cadena1, char* cadena2, int posicion){
    for(; posicion < strlen(cadena2); *cadena1 = cadena2[posicion++], cadena1++);
    *cadena1 = '\0';
}

void mostrar_historial(const char *historial){
  char **lineas, **n_partidas, **palabra_secreta, **ganada, **porcentaje_ganadas;
  int pos_linea;
  FILE *hist = abrir_archivo(historial, 'r');
  int cant = leer_palabras(hist, lineas);
  for (int a = 0; a < cant; a++, lineas++) {
    pos_linea = a % 4;
    switch (pos_linea):
    
    case 0:
      copiar_desde(*n_partidas, *lineas, 19);
      n_partidas++;
      break;
    case 1:
      copiar_desde(*palabra_secreta, *lineas, 17);
      palabra_secreta++;
      break;
    case 2:
      copiar_desde(*ganada, *lineas, 16);
      ganada++;
      break;
    case 3:
      copiar_desde(*porcentaje_ganadas, *lineas, 32);
      porcentaje_ganadas++;
      break;
  }
}
