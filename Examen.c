#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Se incluye las bibliotecas que se van a utilizar
//Se incluye string.h y stdlib.h para el uso de la funcion de gets para almacenar los nombres de los estudiantes

struct estudiante
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char materia[50];
    float nota;
    //Dentro de la estructura se asigna las diferente variables que se van a utilizar

} alumno[];
//Se crea la estructura de los alumnos



int main () {

    int boton;

    do
    {
        printf ("-Bienvenido al menu de opciones de los estudiantes-\n");
        printf ("Ingrese 1. para el ingreso de estudiantes\n");
        printf ("Ingrese 2. para mostrar a los estudiantes ingresados\n");
        printf ("Ingrese 3. para salir\n");
        scanf ("%d", &boton);
        switch (boton)
        {
        case 1:
            printf ("-Ingreso de estudiantes-\n");

            break;

        case 2:
            printf ("-Muestreo de estudiantes-\n");

            break;
        
        case 3:
            printf ("-Gracias por usar el programa-\n");
            break;

        default:
            printf ("-Error al ingresar el numero, intente de nuevo-\n");
            break;
        }
    } while (boton != 3);
    




    return 0;
}