#include "main.h"

int main(int argc, char const *argv[]) {

  if (argc != 2) {
    printf("Uso del ejecutable: %s <archivo_csv>\n", argv[0]); 
    return 1;
  }

  SList viviendas_por_provincia = csv_a_lista(argv[1]); // Creamos la lista principal 
  printf("Demostramos la lectura correcta del archivo: \n\n");
  slist_imprimir(viviendas_por_provincia);

  SList provincias_mas_mil_deshabitadas = filter_listas(viviendas_por_provincia, mayor_mil_v_deshabitadas); // Consigna 4
  printf("\n\nEl listado de las provincias que poseen mas de mil viviendas deshabitadas es el siguiente (Consigna 4): \n\n");
  slist_imprimir(provincias_mas_mil_deshabitadas);
  slist_destruir(provincias_mas_mil_deshabitadas);

  int cantitad_total_viviendas_mas_mil_colectivas = filter_fold_listas(viviendas_por_provincia, mayor_mil_v_colectivas, suma_viviendas_totales); // Consigna 7
  printf("\n\nLa cantidad total de viviendas con mas de mil viviendas colectivas es (Consigna 7):  %d \n\n", cantitad_total_viviendas_mas_mil_colectivas);

  slist_destruir(viviendas_por_provincia);
  return 0;
}
