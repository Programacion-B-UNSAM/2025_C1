gcc -c main.c -o main.o
gcc -c funciones.c -o funciones.o
gcc -c funciones2.c -o funciones2.o
gcc main.o funciones.o funciones2.o -o project_example
./project_example
