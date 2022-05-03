#Makefile del programa

output: main.o manejo_archivo.o menu.o ahorcado.o
        gcc -std=c99 main.o manejo_archivo.o menu.o ahorcado.o -o Ahorcado

main.o: main.c main.h
        gcc -std=c99  -c main.c main.h

manejo_archivo.o: manejo_archivo.c manejo_archivo.h
        gcc -std=c99 -c manejo_archivo.c manejo_archivo.h

menu.o: menu.c menu.h
        gcc -std=c99 -c menu.c menu.h

ahorcado.o: ahorcado.c ahorcado.h
        gcc -std=c99 -c ahorcado.c ahorcado.h

clear: *.o Ahorcado
