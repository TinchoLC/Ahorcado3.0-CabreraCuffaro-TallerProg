# TP 2 Listas (filtros) en C - Martin Cabrera, Ayrton Cuffaro - 5to Informática


## Compilación

gcc main.c manejo_archivo.c menu.c ahorcado.c


## Explicación de separación de archivos y uso de los mismos.

Planteamos un diagrama donde solo usaríamos 4 archivos que contengan código en C (con sus respectivas versiones .c y .h (uno de ellos solo tendrá .h)), además del archivo CSV que menciona el enunciad, el makefile y el mismo readme

### main
Se utiliza la función main y se llama a las funciones necesarias para la realización correcta del enunciado.

### archivos
Librería donde se va a trabajar con archivos y listas, contiene las funciones principales abrir_archivo y csv_a_lista (entre otras).

### filtros
Librería donde se van a ubicar todas las funciones puntero, y las funciones solicitadas de filter_listas y filter_fold_listas

### listas_y_librerias (solo header)
Librería donde se ubicaran todas las definiciones de listas y se incluirán las librerías que se van a utilizar en el programa
(la idea es que esta misma se incluya en los headers de archivos y filtros.

## Explicación de decisiones durante del programa



## Resolución de consignas:

