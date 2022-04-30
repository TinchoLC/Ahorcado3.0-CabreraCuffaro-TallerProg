# Ahorcado en C 3.0 - Martin Cabrera, Ayrton Cuffaro - 5to Informática

## Compilación

gcc main.c manejo_archivo.c menu.c ahorcado.c

## Explicación de decisiones durante del programa

- Copiamos ahorcado.c para ahorrarnos tiempo y poder centrarnos en otras caracteristicas de nuestro programa como lo son el manejo del historial o el menú. Sin embargo, cambiamos la función de jugar_ahorcado de una void a int ya que de esta manera nos es más sencillo luego poder contabilizar la cantidad de partidas ganadas o perdidas (al devolver esta función un 1 si gana o un 0 si pierde).

- Por qué hacemos -cant+1 en menu (guardar y mostrar historial)

- Por qué los for de mostrar y guardar historial empiezan en 1

- Creamos el termino "ERROR" ya que nos pareció una manera simple de cortar el flujo del programa y volver al menú al verificar si las variables contenian dicho valor. En otras palabras, "ERROR" hace alusión a que (como lo indica el nombre) ocurrio un error durante la selección de palabras ya sea durante la elección de una de las cinco palabras o durante la confirmación de esta. (capaz crear constante ERROR)
