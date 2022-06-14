#include "main.h"

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    printf("Uso del ejecutable: %s <lemario> <historial>\n", argv[0]);
    return 1;
  }
  srand(time(NULL));
  menu(argv[1], argv[2]);

  return 0;
}
