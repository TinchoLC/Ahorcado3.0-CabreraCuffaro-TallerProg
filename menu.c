#include "main.h"

int generar_numero_aleatorio(int min, int max){
  int tamano_intervalo = max - min + 1;
  return (( rand() + rand() + rand()) % tamano_intervalo) + min;
}

int palabra_repetida(char **palabras, int contador, char *palabra){
  int h = 0;
  for(; h < contador && palabras[h] != palabra; h++ );
  return !(palabras[h] != palabra);
}

char** cinco_palabras(const char *nombre_archivo){
  char **palabras_totales = malloc(sizeof(char*) * CANT_MAX_PALABRAS);
  char **palabras_opcion = malloc(sizeof(char*) * 5);

  FILE *archivo_objeto = abrir_archivo(nombre_archivo, "r");
  int cant_palabras = leer_palabras(archivo_objeto, palabras_totales);
  fclose(archivo_objeto);

  int indice_palabra_aleatoria, largo_palabra_aleatoria, i = 0;
  for (; i < 5; i++) {
    indice_palabra_aleatoria = generar_numero_aleatorio(0, cant_palabras);
    if ( palabra_repetida(palabras_opcion, i, palabras_totales[indice_palabra_aleatoria]) ) 
      i--; // Como la palabra se repite, hace otra iteracion
    else { // La palabra solamente se guarda si no es repetida
      largo_palabra_aleatoria = strlen(palabras_totales[indice_palabra_aleatoria]);
      palabras_opcion[i] = malloc(sizeof(char) * (largo_palabra_aleatoria + 1));
      strcpy(palabras_opcion[i], palabras_totales[indice_palabra_aleatoria]);
    }
  }

  liberar_array_bidimensional(palabras_totales, CANT_MAX_PALABRAS);
  return palabras_opcion;
}

char* elegir_palabra(char **opciones){
  int opcion;
  printf("\n\nSi no le agrada ninguna palabra, la opcion 0 lo devuelve al menu");
  printf("\nPalabras disponibles: \n1) %s\n2) %s\n3) %s\n4) %s\n5) %s", opciones[0], opciones[1], opciones[2], opciones[3], opciones[4]);
  printf("\n\nIngrese una opcion: "); scanf("%d", &opcion);

  if (opcion > 0 && opcion < 6)
    return opciones[opcion-1];
  else
    return "ERROR";
}

char* estar_seguro(char *palabra){
  printf("\nEstas seguro de que quieres seleccionar la palabra %s? |1) si |2) no |", palabra);
  int quiere_palabra; printf("\nIngrese su opcion: "); scanf("%d", &quiere_palabra);
  if (quiere_palabra-1)
    return "ERROR";
  return palabra;
}

char* palabra_final(const char *nombre_lemario){
  char *palabra;
  palabra = elegir_palabra( cinco_palabras(nombre_lemario) );
  if (palabra != "ERROR") // comprueba si no se selecciono una palabra, para volver al menu
    palabra = estar_seguro(palabra);
  return palabra;
}

int jugar_partida(char *palabra){
  int largo_palabra = strlen(palabra);

  char *palabra_oculta = malloc(sizeof(char) * (largo_palabra + 1));
  ocultar_palabra(palabra_oculta, largo_palabra);
          
  return jugar_ahorcado(palabra, palabra_oculta);
}

void rellenar_campos(Partida *partidas, int ganada_perdida, int *cant_ganadas, int cant_partidas, char *palabra){
  partidas->palabra_secreta = malloc(sizeof(char) * (strlen(palabra) + 1));
  partidas->palabra_secreta = palabra;

  if (ganada_perdida){
    (*cant_ganadas)++;
    strcpy(partidas->ganada,"Si");
  } else 
    strcpy(partidas->ganada,"No"); 

  partidas->n_partida = cant_partidas;

  partidas->porcentaje_ganadas = (float)*cant_ganadas/cant_partidas*100;
}

void menu(const char *nombre_lemario, const char *nombre_historial){
  int opcion;
  Partida* partidas;
  partidas = malloc(sizeof(Partida) * CANT_MAX_PARTIDAS);
  for (int cant_partidas = 1, cant_ganadas = 0; opcion != 3;){
    printf("Seleccione:\n1) Elegir una palabra\n2) Mostrar historial\n3) Salir\n\n");
    printf("Ingrese una opcion: "); scanf("%d", &opcion);

    switch (opcion) {
  
      case 1: // Elegir una palabra
      { char *palabra;
        palabra = palabra_final(nombre_lemario);
        if (palabra != "ERROR") { // vuelve al menu
          int ganada_perdida=jugar_partida(palabra);

          rellenar_campos(partidas, ganada_perdida, &cant_ganadas, cant_partidas, palabra);

          cant_partidas++, partidas++;
        }
      }
      break;

      case 2: // Mostrar el historial 
        mostrar_historial(partidas-cant_partidas+1, cant_partidas);
      break;

      case 3: // Finalizar y guardar en el historial
        guardar_historial(nombre_historial, partidas-cant_partidas+1, cant_partidas); // aclarar readme el +1
        free(partidas);
      break;

      default: // Volver al menu
        // system(limpiar);
        printf("No ingreso una opcion valida, ingrese una:\n\n");
    }
  }
}