#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Se incluye las bibliotecas que se van a utilizar
// Se incluye string.h y stdlib.h para el uso de la funcion de gets para almacenar los nombres de los estudiantes

FILE *archivo;
// Creacion y asignacion del archivo donde se guardaran los datos

struct estudiante
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char materia[50];
    float nota;
    // Dentro de la estructura se asigna las diferente variables que se van a utilizar

} alumno[];
// Se crea la estructura de los alumnos

void agregar()
{
    char direccion[] = "D:\\Programacion RH\\3er_Progreso\\Herrera_Examen_-Progreso3\\alumnos.txt";
    // Direccion del archivo, puede ser editable

    int respuesta, i = 1;
    //Se asigna las variables "respuesta" para pedir al usiario cerrar el bucle do-while y la de "i" para contar los alumnos ingresados

    archivo = fopen(direccion, "a");
    // Se crea una asignacion para que los datos se vayan al archivo asignado

    if (archivo == NULL)
    {
        printf("Error al ingresar en el archivo\n");
        // Error si no encuentra el archivo que se quiere ingresar los datos
    }

    do
    {
        printf("-Ingrese la matricula del estudiante-\n");
        scanf("%d", &alumno[i].matricula);
        fflush(stdin);
        printf("-Ingrese el nombre del estudiante-\n");
        gets(alumno[i].nombre);
        fflush(stdin);
        printf("-Ingrese la direcion del estudiante-\n");
        gets(alumno[i].direccion);
        fflush(stdin);
        printf("-Ingrese la materia del estudiante-\n");
        gets(alumno[i].materia);
        fflush(stdin);
        printf("-Ingrese la nota del estudiante-\n");
        scanf("%f", &alumno[i].nota);
        fflush(stdin);
        // Se pide al usuario que ingrese los datos pertientes para cada variable de la estructura
        // Ademas, se utiliza el fflush para limpiar el buffer y no tener problemas al ingreso de datos

        printf("MATRICULA: %d\n", alumno[i].matricula);
        printf("NOMBRE: %s\n", alumno[i].nombre);
        printf("DIRECCION: %s\n", alumno[i].direccion);
        printf("CARRERA: %s\n", alumno[i].materia);
        printf("NOTA: %.2f\n", alumno[i].nota);
        // Se imprime los valores ingresados recientemente

        fprintf(archivo, "%d\t\t", alumno[i].matricula);
        fprintf(archivo, "%s\t\t", alumno[i].nombre);
        fprintf(archivo, "%s\t\t", alumno[i].direccion);
        fprintf(archivo, "%s\t\t", alumno[i].materia);
        fprintf(archivo, "%.2f\n", alumno[i].nota);

        printf("¿Desea salir? (1. para salir, Cualquier otro numero para continuar)\n");
        scanf("%d", &respuesta);
        // Se pregunta al usuario si desea salir del bucle de ingreso de estudiantes

    } while (respuesta != 1);
    // Se crea un bucle do-while para el conteo de cuantos alumnos se esta ingresando

    fclose(archivo);
    // Se cierra el archivo
}

void visualizar()
{
    char direccion[] = "D:\\Programacion RH\\3er_Progreso\\Herrera_Examen_-Progreso3\\alumnos.txt";
    // Direccion del archivo, puede ser editable

    int ayudante;
    // Asignacion de la variable entera ayudante

    archivo = fopen(direccion, "r");
    // Se abre el archivo y se asigna la direccion "r" de read

    if (archivo == NULL)
    {
        printf("Error al ingresar en el archivo\n");
        // Error si no encuentra el archivo que se quiere ingresar los datos
    }
    while ((ayudante = fgetc(archivo)) != EOF)
    {
        if (ayudante == '\n')
        {
            printf("\n");
        }
        else
        {
            putchar(ayudante);
        }
    }
    fclose(archivo);
    //Se cierra el archivo
}

int main()
{

    int boton;
    // Se asigna la variable boto para el uso de la funcion switch

    do
    {
        printf("-Bienvenido al menu de opciones de los estudiantes-\n");
        printf("Ingrese 1. para el ingreso de estudiantes\n");
        printf("Ingrese 2. para mostrar a los estudiantes ingresados\n");
        printf("Ingrese 3. para salir\n");
        scanf("%d", &boton);
        //Se muetras las opciones al usuario y le pide que ingrese la opcion

        switch (boton)
        {
        case 1:
            printf("-Ingreso de estudiantes-\n");
            agregar();
            //En el caso 1 se usa la funcion agregar para la asignacion de datos de estudiantes

            break;

        case 2:
            printf("-Muestreo de estudiantes-\n");
            visualizar();
            //En el caso 2 se usa la funcion visualizar para ver los estudiantes que esten agregados de manera horizontal

            break;

        case 3:
            printf("-Gracias por usar el programa-\n");
            //Se agradece al usuario de usar el programa y se cerrara el programa en el caso 3

            break;

        default:
            printf("-Error al ingresar el numero, intente de nuevo-\n");
            //Salta un error si el usuario no ingresa los numeros pedidos

            break;
        }
    } while (boton != 3);
    // Creacion del menu con bucle dowhile hasta que el usuario oprima el numero 3, ademas se implemento la funcion switch para el muestreo y adicion de datos de los estudiantes

    return 0;
}