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

void ingreso()
{

    int i;

    char direccion[] = "D:\\Programacion RH\\3er_Progreso\\Herrera_Examen_-Progreso3\\alumnos.txt";
    // Direccion del archivo, puede ser editable

    archivo = fopen(direccion, "a");
    // Se crea una asignacion para que los datos se vayan al archivo asignado

    if (archivo == NULL)
    {
        printf("Error al ingresar en el archivo\n");
        // Error si el arcihvo no se encuentra
    }

    printf("-Ingrese la matricula del estudiante-\n");
    scanf("%d", &alumno[i].matricula);
    // Ingreso tipo entero de la matricula dentro de la estructura alumno
    fflush(stdin);
    // Se limpia el buffer para no tener problemas al ingresar los datos

    printf("-Ingrese el nombre del estudiante-\n");
    gets(alumno[i].nombre);
    // Ingreso del nombre del estudiante mediante la funcion gets en la estructura alumno
    fflush(stdin);
    // Se limpia el buffer para no tener problemas al ingresar los datos

    printf("-Ingrese la direcion del estudiante-\n");
    gets(alumno[i].direccion);
    // Ingreso de la direccion del estudiante mediante la funcion gets en la estructura alumno
    fflush(stdin);
    // Se limpia el buffer para no tener problemas al ingresar los datos

    printf("-Ingrese la materia del estudiante-\n");
    gets(alumno[i].materia);
    // Ingreso de la materia del estudiante mediante la funcion gets en la estructura alumno
    fflush(stdin);
    // Se limpia el buffer para no tener problemas al ingresar los datos

    printf("-Ingrese la nota del estudiante-\n");
    scanf("%f", &alumno[i].nota);
    // Ingreso de tipo flotante de la nota del estudiante de la estructura del alumno
    fflush(stdin);
    // Se limpia el buffer para no tener problemas al ingresar los datos

    printf("MATRICULA: %d\n", alumno[i].matricula);
    printf("NOMBRE: %s\n", alumno[i].nombre);
    printf("DIRECCION: %s\n", alumno[i].direccion);
    printf("CARRERA: %s\n", alumno[i].materia);
    printf("NOTA: %.2f\n", alumno[i].nota);
    // Se imprime los valores ingresados recientemente

    fprintf(archivo, "ESTUDIANTES MATRICULADOS\n");
    fprintf("%d \t", alumno[i].matricula);
    fprintf("%s \t", alumno[i].nombre);
    fprintf("%s \t", alumno[i].direccion);
    fprintf("%s \t", alumno[i].materia);

    fclose(archivo);
}
// Funcion "ingreso" para ingresar las veces que sea, los estudiantes y sus diferentes datos: matricula, nombre,etc.

void visualizar()
{
    char direccion[] = "D:\\Programacion RH\\3er_Progreso\\Herrera_Examen_-Progreso3\\alumnos.txt";
    // Direccion del archivo, puede ser editable

    int ayudante;
    archivo = fopen(direccion, "r");
    if (archivo == NULL)
    {
        printf("Error al ingresar en el archivo\n");
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
}

void agregar()
{
    char direccion[] = "D:\\Programacion RH\\3er_Progreso\\Herrera_Examen_-Progreso3\\alumnos.txt";
    // Direccion del archivo, puede ser editable

    int respuesta, i = 1;

    archivo = fopen(direccion, "a");
    // Se crea una asignacion para que los datos se vayan al archivo asignado

    if (archivo == NULL)
    {
        printf("Error al ingresar en el archivo\n");
        //Error si no encuentra el archivo que se quiere ingresar los datos
    }
    printf("Creando base de datos\n");
    fprintf(archivo, "ESTUDIANTES MATRICULADOS\n");

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

        printf("MATRICULA: %d\n", alumno[i].matricula);
        printf("NOMBRE: %s\n", alumno[i].nombre);
        printf("DIRECCION: %s\n", alumno[i].direccion);
        printf("CARRERA: %s\n", alumno[i].materia);
        printf("NOTA: %.2f\n", alumno[i].nota);
        // Se imprime los valores ingresados recientemente

        fprintf(archivo, "%d\t", alumno[i].matricula);
        fprintf(archivo, "%s\t", alumno[i].nombre);
        fprintf(archivo, "%s\t", alumno[i].direccion);
        fprintf(archivo, "%s\t", alumno[i].materia);
        fprintf(archivo, "%.2f\n", alumno[i].nota);

        printf("¿Desea salir? (1. para salir, Cualquier otro numero para continuar)\n");
        scanf("%d", &respuesta);
        getchar();
    } while (respuesta != 1);
    //Se crea un bucle dowhile para el conteo de cuantos alumnos se esta ingresando
    
    fclose(archivo);
    //Se cierra el archivo
}

int main()
{

    int boton;

    do
    {
        printf("-Bienvenido al menu de opciones de los estudiantes-\n");
        printf("Ingrese 1. para el ingreso de estudiantes\n");
        printf("Ingrese 2. para mostrar a los estudiantes ingresados\n");
        printf("Ingrese 3. para salir\n");
        scanf("%d", &boton);
        switch (boton)
        {
        case 1:
            printf("-Ingreso de estudiantes-\n");
            agregar();
            break;

        case 2:
            printf("-Muestreo de estudiantes-\n");
            visualizar();
            break;

        case 3:
            printf("-Gracias por usar el programa-\n");
            break;

        default:
            printf("-Error al ingresar el numero, intente de nuevo-\n");
            break;
        }
    } while (boton != 3);
    // Creacion del menu con bucle dowhile hasta que el usuario oprima el numero 3, ademas se implemento la funcion switch para el muestreo y adicion de datos de los estudiantes

    return 0;
}