#include "filtros.h"

SNodo* filter_listas(SNodo* lista, Predicado p){
	SNodo* nodo_nuevo = NULL;
	for(; lista != NULL; lista = lista->sig){
		if(p(lista))
			slist_agregar_final(nodo_nuevo, lista->provincia, lista->v_habitadas, lista->v_deshabitadas, lista->v_colectivas);
	}
	return nodo_nuevo;
}

int mayor_mil_v_deshabitadas(SNodo* Nodo){
	return Nodo->v_deshabitadas > 1000;
}



SNodo* filter_fold_listas(*SNodo lista, Predicado p, Operador o){
	return o(filter_listas(lista, p));
}

int mayor_mil_v_colectivas(SNodo* Nodo){
	return Nodo->v_colectivas > 1000;
}

int suma_viviendas_totales(*SNodo lista){
	int suma;
	for(; lista != NULL;  lista = lista->sig){
		suma += lista->v_habitadas;
		suma += lista->v_deshabitadas;
	}
	return suma;
}
