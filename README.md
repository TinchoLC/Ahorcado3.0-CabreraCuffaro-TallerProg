# Ahorcado en C 3.0 - Martin Cabrera, Ayrton Cuffaro - 5to Informática

## Compilación

gcc main.c manejo_archivo.c menu.c ahorcado.c

## Explicación de decisiones durante del programa

- Utilizamos ahorcado.c del programa Ahorcado 2.0 para ahorrarnos tiempo y poder centrarnos en otras caracteristicas de nuestro programa como lo son el manejo del historial o el menú. Sin embargo, cambiamos la función de jugar_ahorcado de una void a int ya que de esta manera nos es más sencillo luego poder contabilizar la cantidad de partidas ganadas o perdidas (al devolver esta función un 1 si gana o un 0 si pierde).

- Dentro de menu.c al llamar la funcion de guardar y mostrar historial pasamos como argumento partidas-cant_partidas ya que previamente dentro del for incrementamos la dirección del puntero a la estructura partidas unas cant_partidas veces. Por lo tanto cuando restamos al puntero la cantidad de partidas, lo que hacemos es devolver al puntero a su posición original sin ningún incremento.

- Creamos el termino "ERROR" ya que nos pareció una manera simple de cortar el flujo del programa y volver al menú al verificar si las variables contenian dicho valor. En otras palabras, "ERROR" hace alusión a que (como lo indica el nombre) ocurrio un error durante la selección de palabras ya sea durante la elección de una de las cinco palabras o durante la confirmación de esta.
