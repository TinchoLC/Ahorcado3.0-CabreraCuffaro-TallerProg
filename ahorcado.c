#include "ahorcado.h"

void ocultar_palabra(char palabra[], int largo_palabra) {
  for (int i = 0; i < largo_palabra; palabra[i++] = '-');
  palabra[largo_palabra] = '\0';
}

int ganadora(char tablero[], char palabra_secreta[]) {
  return strcmp(tablero, palabra_secreta) == 0;
}

int letra_repetida(char letra, char letras_jugadas[]) {
  int i = 0, cant_letras_jugadas = strlen(letras_jugadas);
  for (; i < cant_letras_jugadas && letras_jugadas[i] != letra; i++);

  return i != cant_letras_jugadas;
}

char pedir_letra(char letras_jugadas[]){
  char letra;

  printf("Ingrese una letra: ");
  scanf("%s", &letra);

  while (letra_repetida(letra, letras_jugadas)) {
    printf("Ingrese una letra que no haya ingresado antes: ");
    scanf("%s", &letra);
  }

  int cant_letras_jugadas = strlen(letras_jugadas);

  letras_jugadas[cant_letras_jugadas] = letra;
  letras_jugadas[cant_letras_jugadas + 1] = '\0';
  return letra;
}

int rellenar_palabra(char letra, char tablero[], char palabra_secreta[]) {
  int encontrada = 0;

  int largo_palabra = strlen(palabra_secreta);
  for (int i = 0; i < largo_palabra; i++) {
    if (palabra_secreta[i] == letra) {
      tablero[i] = letra;
      encontrada = 1;
    }
  }

  return encontrada;
}

void dibujo_ahorcado(int vidas){
  switch(vidas){
    case 7:
      printf("\n%c\n",179);
      printf("%c\n",179);
      printf("%c\n",179);
      printf("%c\n",179);
      printf("%c\n",179);
      printf("%c%c%c%c%c%c%c%c%c\n",193,196,196,196,196,196,196,196,196);
    break;
      
    case 6:
      printf("\n%c%c%c%c%c%c\n",218,196,196,196,196,196);
      printf("%c\n",179);
      printf("%c\n",179);
      printf("%c\n",179);
      printf("%c\n",179);
      printf("%c%c%c%c%c%c%c%c%c\n",193,196,196,196,196,196,196,196,196);
    break;
      
    case 5:
      printf("\n%c%c%c%c%c%c\n",218,196,196,196,196,191);
      printf("%c    %c\n",179,179);
      printf("%c    \n",179);
      printf("%c\n",179);
      printf("%c\n",179);
      printf("%c%c%c%c%c%c%c%c%c\n",193,196,196,196,196,196,196,196,196);
    break;
      
    case 4:
      printf("\n%c%c%c%c%c%c\n",218,196,196,196,196,191);
      printf("%c    %c\n",179,179);
      printf("%c    O\n",179);
      printf("%c\n",179);
      printf("%c\n",179);
      printf("%c%c%c%c%c%c%c%c%c\n",193,196,196,196,196,196,196,196,196);
    break;
    
    case 3:
      printf("\n%c%c%c%c%c%c\n",218,196,196,196,196,191);
      printf("%c    %c\n",179,179);
      printf("%c    O\n",179);
      printf("%c   /%c\n",179,179);
      printf("%c\n",179);
      printf("%c%c%c%c%c%c%c%c%c\n",193,196,196,196,196,196,196,196,196);
    break;
    
    case 2:
      printf("\n%c%c%c%c%c%c\n",218,196,196,196,196,191);
      printf("%c    %c\n",179,179);
      printf("%c    O\n",179);
      printf("%c   /%c%c\n",179,179,92);
      printf("%c\n",179);
      printf("%c%c%c%c%c%c%c%c%c\n",193,196,196,196,196,196,196,196,196);
    break;
    
    case 1:
      printf("\n%c%c%c%c%c%c\n",218,196,196,196,196,191);
      printf("%c    %c\n",179,179);
      printf("%c    O\n", 179);
      printf("%c   /%c%c\n",179,179,92);
      printf("%c   /\n",179);
      printf("%c%c%c%c%c%c%c%c%c\n",193,196,196,196,196,196,196,196,196);
    break;
    
    case 0:
      printf("\n%c%c%c%c%c%c\n",218,196,196,196,196,191);
      printf("%c    %c\n",179,179);
      printf("%c    O\n", 179);
      printf("%c   /%c%c\n",179,179,92);
      printf("%c   / %c\n",179,92);
      printf("%c%c%c%c%c%c%c%c%c\n",193,196,196,196,196,196,196,196,196);
    break;
      
    default:
      printf("\nDibujo no disponible\n");
    }
}

void mostrar_tablero(char tablero[], char letras_jugadas[], int vidas) {
  dibujo_ahorcado(vidas);
  printf("Cantidad de vidas restantes: %d\n", vidas);
  printf("Letras ingresadas: %s\n", letras_jugadas);
  printf("%s\n\n", tablero);
}

int jugar_ahorcado(char *palabra_secreta, char *tablero) {
  int vidas = VIDAS_INICIALES, encontrada = 0;
  char letra, letras_jugadas[LARGO_ABC];
  letras_jugadas[0] = '\0';

  while (vidas && !ganadora(tablero, palabra_secreta)) {
    // system(limpiar);
    mostrar_tablero(tablero, letras_jugadas, vidas);

    letra = pedir_letra(letras_jugadas);
    encontrada = rellenar_palabra(letra, tablero, palabra_secreta);

    if (!encontrada)
      vidas--;
  }

  if (vidas) {
    dibujo_ahorcado(vidas);
    printf("Felicitaciones! Ganaste\n");
    return 1;
  }
  dibujo_ahorcado(vidas);
  printf("Suerte la proxima! La palabra era %s\n", palabra_secreta);
  return 0;
}
