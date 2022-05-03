# Ahorcado en C 3.0 - Martin Cabrera, Ayrton Cuffaro - 5to Informática

## Compilación

gcc main.c manejo_archivo.c menu.c ahorcado.c

## Explicación de decisiones durante del programa

- Utilizamos ahorcado.c del programa Ahorcado 2.0 para ahorrarnos tiempo y poder centrarnos en otras caracteristicas de nuestro programa como lo son el manejo del historial o el menú. Sin embargo, cambiamos la función de jugar_ahorcado de una void a int ya que de esta manera nos es más sencillo luego poder contabilizar la cantidad de partidas ganadas o perdidas (al devolver esta función un 1 si gana o un 0 si pierde).

- Dentro de menu.c al llamar la funcion de guardar y mostrar historial pasamos como argumento partidas-cant_partidas ya que previamente dentro del for incrementamos la dirección del puntero a la estructura partidas unas cant_partidas veces. Por lo tanto cuando restamos al puntero la cantidad de partidas, lo que hacemos es devolver al puntero a su posición original sin ningún incremento.

- Dentro de manejo_archivos.c en las funciones de guardar y mostrar historial, más especificamente en esta parte: "| %-17d | %-23s |   %s   | %.2f%%  \t    |\n", tiene esta combinación de letras y números que a simple vista son extraños pero que en realidad cumplen la función de darle un formato uniforme a cada fila sin importar los valores que se le ingrese. El %-17d está para que reciba un número entero de hasta 17 digitos (los cuales nunca se van a usar todos pero de otra manera habría que reemplazar el 17 por 17 espacios provocando que la linea sea practicamente ilegible). Se usa el %-23s ya que luego de buscar descubrimos que la palabra más larga del español tiene esa cantidad de letras. Por último, en la última columna, esa combinación de espacios y \t sirven para que tenga el mismo formato tanto el menor número (0.00) como el mayor (100.00).

- Creamos el termino "ERROR" ya que nos pareció una manera simple de cortar el flujo del programa y volver al menú al verificar si las variables contenian dicho valor. En otras palabras, "ERROR" hace alusión a que (como lo indica el nombre) ocurrio un error durante la selección de palabras ya sea durante la elección de una de las cinco palabras o durante la confirmación de esta.

- Dentro de menu.c en la primera linea se incluye al main.h ya que menu.c es el centro de nuestro programa y por lo tanto necesita de todas las funciones de los demás .h. Al incluir main.h a menu.c indirectamente estamos incluyendo el resto de .h debido a que todos están previamente incluidos dentro de main.h.

- Por último (fuera de las explicaciones sobre las decisiones hechas), queremos mostrar la manera en la que realizamos este trabajo la cuál es mediante un repositorio de GitHub (si desean ver el repositorio, envienos el nombre de su usuario para agregarlos) ya que lo consideramos más cómodo para poder ver las modificaciones que hacia el otro en el programa de manera simultanea y corregirlas o entenderlas en el momento en lugar de solamente dividir el trabajo para luego juntar todas las funciones y corregir todos los errores juntos.
