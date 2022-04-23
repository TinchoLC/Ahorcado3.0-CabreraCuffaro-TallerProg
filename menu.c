#include "menu.h"

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

int generar_numero_aleatorio(int min, int max){
  srand(time(NULL));

  int tamano_intervalo = min - max + 1;
  return (rand() % tamano_intervalo) + min;
}

void liberar_array_bidimensional(char **palabras_validas, int cant_palabras){
  for (int i = 0; i < cant_palabras; free(palabras_validas[i++]));
  free(palabras_validas);
}

void mostrar_palabras(char **palabras, int cant_palabras) {
  for (int i = 0; i < cant_palabras; printf("%s\n", palabras[i++]));
}

int palabra_repetida(char **palabras, int cant_palabras, char *palabra){
  int h = 0;
  for(; h < cant_palabras && strcmp(palabras[h], palabra); h++);
  return !strcmp(palabras[h], palabra);
}


char** elegir_palabra(const char *nombre_archivo){
  char **palabras_totales = malloc(sizeof(char) * CANT_MAX_PALABRAS);

  char **palabras_opcion = malloc(sizeof(char) * 5);

  int indice_palabra_aleatoria;

  FILE *archivo_objeto = abrir_archivo(nombre_archivo, "r");
  int cant_palabras = leer_palabras(archivo_objeto, palabras_totales);
  fclose(archivo_objeto);

  for (int i = 0; i < 5; i++) {
    indice_palabra_aleatoria = numero_aleatorio(0, cant_palabras);

    if ( palabra_repetida(**palabras_opcion, i , palabras_totales[indice_palabra_aleatoria]) ) {
      i--; // Como la palabra se repite, hace otra iteracion
    }
    else{ // La palabra solamente se guarda si no es repetida
    int largo_palabra_aleatoria = strlen(palabras_totales[indice_palabra_aleatoria]);
    palabras_opcion[i] = malloc(sizeof(char) * (largo_palabra_aleatoria + 1));
    strcpy(palabras_opcion[i], palabras_totales[indice_palabra_aleatoria]);
    }
  }
  liberar_palabras(palabras_totales, CANT_MAX_PALABRAS);
  return palabras_opcion;
}

// para agregar funcion




int menu(){
  int opcion;
  printf("Seleccione:\n1) Elegir una palabra\n2) Mostrar historial\n3) Salir\n\n");
  printf("Ingrese una opcion: "); scanf("%d", &opcion);

  switch (opcion) {
  
    case 1: // Elegir una palabra
    // eleccionPalabra();  /////////////////////////////////////////
  break;

  case 2: // Mostrar el historial 
    // mostrarHistorial(); /////////////////////////////////////////
  break;

  case 3: // Finalizar y guardar en el historial
    // guardarHistorial();
    return 0; // Si retorna 0 el main finaliza
  break;

  default: // Volver al menu
    // system(limpiar);
    printf("No ingreso una opcion valida, ingrese una:\n\n");
    menu();
    }
  }