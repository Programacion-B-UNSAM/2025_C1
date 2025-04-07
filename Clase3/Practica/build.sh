gcc -c main.c -o main.o
gcc -c funciones.c -o funciones.o
gcc main.o funciones.o -o my_programa -lm
./my_programa

# Alternativamente 
# gcc -o program main.c funciones.c -lm
# .\program
# lm se utiliza para la libreria de math

