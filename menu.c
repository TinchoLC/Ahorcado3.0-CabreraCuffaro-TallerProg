#include "main.h"

int generar_numero_aleatorio(int min, int max){
  int tamano_intervalo = max - min + 1;
  return ( ( rand() + rand() + rand() ) % tamano_intervalo) + min;
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

  int indice_palabra_aleatoria, largo_palabra_aleatoria, i=0;
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

  if(opcion>0 && opcion<6)
    return opciones[opcion-1];
  else
    return "ERROR";
}

int menu(const char *nombre_lemario, const char *nombre_historial){
  char *palabra;
  int opcion;
  printf("Seleccione:\n1) Elegir una palabra\n2) Mostrar historial\n3) Salir\n\n");
  printf("Ingrese una opcion: "); scanf("%d", &opcion);
  switch (opcion) {
  
    case 1: // Elegir una palabra
      palabra = elegir_palabra( cinco_palabras(nombre_lemario) );
        if ( strcmp(palabra,"ERROR") ){
          int largo_palabra = strlen(palabra);
          char *palabra_oculta = malloc(sizeof(char) * (largo_palabra + 1));
          ocultar_palabra(palabra_oculta, largo_palabra);
          jugar_ahorcado(palabra, palabra_oculta);
        }
        menu(nombre_lemario, nombre_historial);
  break;

  case 2: // Mostrar el historial 
    mostrar_historial(nombre_historial); /////////////////////////////////////////
    menu(nombre_lemario, nombre_historial);
  break;

  case 3: // Finalizar y guardar en el historial
    // guardar_historial(nombre_historial);
    return 0; // Si retorna 0 el main finaliza
  break;

  default: // Volver al menu
    // system(limpiar);
    printf("No ingreso una opcion valida, ingrese una:\n\n");
    menu(nombre_lemario, nombre_historial);
  }
}
