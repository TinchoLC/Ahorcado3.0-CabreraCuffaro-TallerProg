#include "main.h"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("Uso del ejecutable: %s <archivo_csv>\n", argv[0]);
    return 1;
  }
  srand(time(NULL));
  menu(argv[1], argv[2]);

  return 0;
}