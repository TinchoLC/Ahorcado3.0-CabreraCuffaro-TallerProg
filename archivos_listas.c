#include "archivos_listas.h"

FILE* abrir_archivo(const char *nombre_archivo, char *modo) {
  FILE *archivo = fopen(nombre_archivo, modo);
  assert(archivo != NULL);
  
  return archivo;
}

char* sacar_string(char* csv_line, int* mover_linea, char* string){
  for(int i = 0 ; CSV_LINE_MOV !=',' ;){
    STRING_MOVI = CSV_LINE_MOV; // Se va copiando el contenido de la linea en un string, caracter por caracter
    MOV++; // Se aumenta el contador sobre la posicion de la linea del archivo
    i++; // El contador i se utiliza para viajar en la linea del nuevo string
    STRING_MOVI = '\0'; // Recordar, siempre hay que poner un terminador! (Lettieri enseñanzas)
  }
  MOV++; // Para ignorar la ','
  return string; // ACA FALTA UN FREE FALTA UN FREEEE
} 

int sacar_int(char* csv_line, int* mover_linea, char* string){
  return atoi(sacar_string(csv_line, mover_linea, string)); 
} 

SList slist_agregar_final(SList lista, char *provincia, int v_habitadas, int v_deshabitadas, int v_colectivas) {
  SList nuevo_nodo = malloc(sizeof(SNodo));
  int largo_nombre_provincia = strlen(provincia);
  nuevo_nodo->provincia = malloc(sizeof(char) * (largo_nombre_provincia + 1)); // aca un free
  strcpy(nuevo_nodo->provincia,provincia);
  nuevo_nodo->v_habitadas = v_habitadas;
  nuevo_nodo->v_deshabitadas = v_deshabitadas;
  nuevo_nodo->v_colectivas = v_colectivas;
  nuevo_nodo->sig = NULL;

  if (lista == NULL)
    return nuevo_nodo;

  SList nodo_temp = lista;
  for (; nodo_temp->sig != NULL; nodo_temp = nodo_temp->sig);

  nodo_temp->sig = nuevo_nodo;
  return lista;
}

void slist_destruir(SList lista) {
  SList nodo_a_eliminar;
  while (lista != NULL) {
    nodo_a_eliminar = lista;
    lista = lista->sig;
    free(nodo_a_eliminar->provincia);
    free(nodo_a_eliminar);
  }
}

void slist_imprimir(SList lista) {
  printf("+------------------------------------------------------+---------+--------+------+\n");
  for (SList nodo = lista; nodo != NULL; nodo = nodo->sig)
    printf("| %-52s | %-7d | %-6d | %-4d |\n", nodo->provincia, nodo->v_habitadas, nodo->v_deshabitadas, nodo->v_colectivas);
  printf("+------------------------------------------------------+---------+--------+------+\n");
}

SList csv_a_lista(char const* viviendas_provincia){
  SList lista = NULL;
  FILE* provincia_info = abrir_archivo(viviendas_provincia,"r");
  char *linea_de_csv = malloc(sizeof(char)*ESPACIO_MAX_LINEA_CSV), *provincia = malloc(sizeof(char)*ESPACIO_MAX_STRING), *string = malloc(sizeof(char)*ESPACIO_MAX_STRING);
  int v_habitadas, v_deshabitadas, v_colectivas, mover_linea;

  fscanf(provincia_info, "%[^\n] ", linea_de_csv); // Ignorar primera linea
  for(; EOF !=  fscanf(provincia_info, "%[^\n] ", linea_de_csv);){

    mover_linea=0;
    strcpy(provincia,sacar_string(linea_de_csv,&mover_linea,string));
    v_habitadas = sacar_int(linea_de_csv, &mover_linea,string);
    v_deshabitadas = sacar_int(linea_de_csv,&mover_linea,string);
    v_colectivas = sacar_int(linea_de_csv,&mover_linea,string);
    lista = slist_agregar_final(lista, provincia, v_habitadas, v_deshabitadas, v_colectivas);
  }
  
  free(linea_de_csv); free(provincia); free(string);
  fclose(provincia_info);

  return lista;
}
