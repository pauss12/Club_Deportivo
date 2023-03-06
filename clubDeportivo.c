#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Incluir la "biblioteca" donde estan las estructuras y las cabeceras de las funciones
#include "clubDeportivo.h"

// FUNCIONES --------------------------------------------------------------------------
 // Funcion para mostrar el menu
void mostrarMenu(){
    printf("Introduzca la siguiente opcion: \n");
    printf("1.Introducir un equipo \n");
    printf("2.Mostrar la lista de equipos \n");
    printf("3.Salir \n");
}

//Funcion para mostrar el segundo menu, para seleccionar el tipo de equipo
void mostrarMenuTipoEquipo(){
    printf("Elige el tipo de Equipo: \n");
    printf("1.Futbol \n");
    printf("2.Formula 1 \n");
    printf("3.Natacion \n");
}

// Funcion para comparar los String----------------------------------------------------
int compareString(char str1[], char str2[]){
    // Variables
    int iguales = 0;
    int i = 0;

    while (iguales == 0 && str1[i] != '\0'){
        if (str1[i] != str2[i]) {
            iguales = 1;
        }
        i++;
    }

    return iguales;
}

//Funcion para pedir los datos para un equipo de futbol
futbol_t pedirDatosFutbol(){

    // Variables
    char categoria[TAM_MAX];
    futbol_t futbol;
    int i = 0;

    printf("Introduce el numero de jugadores: \n");
    scanf("%d", &futbol.numeroJugadores);

    printf("Introduce el ratio: \n");
    scanf("%f", &futbol.ratio);

    printf("Introduce la posicion en la liga: \n");
    scanf("%s", &futbol.posicionLiga);

    printf("Introduce una categoria (cadete, infantil, junior o senior): \n");
    scanf("%s", categoria);

    if (compareString(categoria, "cadete") == 0){
        futbol.categoriaFutbol = CA;
    }else if (compareString(categoria, "infantil") == 0){
        futbol.categoriaFutbol = INF;
    }else if (compareString(categoria, "junior") == 0){
        futbol.categoriaFutbol = JUN;
    }else if (compareString(categoria, "senior") == 0){
        futbol.categoriaFutbol = SEN;
    }else{
        printf("No se ha introducido un tipo de equipo valido\n");
    }

    return futbol;
}

// Funcion para pedir los datos para un equipo de formula 1
formula1_t pedirDatosFormula1(){

    // Variables
    formula1_t formula1;
    int i = 0;
    int j = 0;

    printf("Introduce el numero de pilotos: \n");
    scanf("%d", &formula1.numeroPiloto);

    for (i = 0; i < formula1.numeroPiloto; i++){
        printf("Introduce el nombre del piloto: \n");
        scanf("%s", &formula1.pilotos[i].nombre);

        printf("Introduce la edad del piloto: \n");
        scanf("%d", &formula1.pilotos[i].edad);

        printf("Introduce el numero de victorias del piloto: \n");
        scanf("%d", &formula1.pilotos[i].numeroVictorias);
    }

    printf("Introduce el tamaño del motor: \n");
    scanf("%d", &formula1.tamanioMotor);

    return formula1;
}

// Funcion para pedir los datos para un equipo de natacion
natacion_t pedirDatosNatacion(){

    // Variables
    char categoria[TAM_MAX];
    natacion_t natacion;

    printf("Introduce el numero de nadadores: \n");
    scanf("%d", &natacion.numeroNadadores);

    printf("Introduce el precio de la inscripcion: \n");
    scanf("%.2f", &natacion.precioInscripcion);

    printf("Introduce una categoria (cadete, infantil, junior o senior): \n");
    scanf("%s", categoria);

    if (compareString(categoria, "cadete") == 0){
        natacion.categoriaNatacion = CA;
    }else if (compareString(categoria, "infantil") == 0){
        natacion.categoriaNatacion = INF;
    }else if (compareString(categoria, "junior") == 0){
        natacion.categoriaNatacion = JUN;
    }else if (compareString(categoria, "senior") == 0){
        natacion.categoriaNatacion = SEN;
    }else{
        printf("No se ha introducido un tipo de equipo valido\n");
    }

    return natacion;
}

// Funcion para pedir los datos del equipo
equipo_t pedirDatos(){

    // Variables
   equipo_t equipo;

   printf("\nIntroducir un equipo \n");
   mostrarMenuTipoEquipo();
   scanf("%x", &equipo.tipo);

   printf("\nIntroduce el nombre del equipo: \n");
   scanf("%s", equipo.nombreEquipo);

   switch (equipo.tipo){
   // PEDIR DATOS FUTBOL
   case 1:
        printf("\nPedir datos de Futbol ----------------\n");
        equipo.info.futbol = pedirDatosFutbol();
    break;

    // PEDIR DATOS FORMULA 1
    case 2:
        printf("\nPedir datos de Formula 1  ----------------\n");
        equipo.info.formula1 = pedirDatosFormula1();
    break;

    // PEDIR DATOS NATACION
    case 3:
        printf("\nPedir datos de Natacion  ----------------\n");
        equipo.info.natacion = pedirDatosNatacion();
    break;

    default:
        printf("\ntNo se ha introducido un tipo de equipo valido\n");
        break;
    }

    return equipo;
}

// Funcion para mostrar la lista de equipos
void mostrarListaEquipos(conjuntoEquipos_t conjunto){

    // Variables
    int i = 0;

    printf("\n-------- Mostrar la lista de equipos -------\n");

    for (i = 0; i < conjunto.numeroEquipos; i++){
        printf("El nombre del equipo es: %s\n", conjunto.equipo[i].nombreEquipo);

        switch (conjunto.equipo[i].tipo){
            case 1:
                printf("El tipo de equipo es futbol\n");
            break;

            case 2:
                printf("El tipo de equipo es formula 1\n");
            break;

            case 3:
                printf("El tipo de equipo es natacion\n");
            break;
            
            default:
                printf("No se ha introducido un tipo de equipo valido\n");
            break;
        }

        switch (conjunto.equipo[i].tipo){
        // MOSTRAR DATOS FUTBOL
        case 1:
            printf("\nMostrar datos de Futbol ----------------\n");
            printf("El numero de jugadores es: %d\n", conjunto.equipo[i].info.futbol.numeroJugadores);
            printf("El ratio es: %.2f\n", conjunto.equipo[i].info.futbol.ratio);
            printf("La posicion en la liga es: %s\n", conjunto.equipo[i].info.futbol.posicionLiga);

            //Mostrar la categoria
            switch (conjunto.equipo[i].info.futbol.categoriaFutbol){
                case CA:
                    printf("La categoria es Cadete\n");
                    break;
                case INF:
                    printf("La categoria es Infantil\n");
                    break;
                case JUN:
                    printf("La categoria es Junior\n");
                    break;
                case SEN:
                    printf("La categoria es Senior\n");
                    break;
                default:
                    printf("Categoría desconocida\n");
                break;
            }

            break;

        // MOSTRAR DATOS FORMULA 1
        case 2:
            printf("\nMostrar datos de Formula 1 ----------------\n");
            printf("El numero de pilotos es: %d\n", conjunto.equipo[i].info.formula1.numeroPiloto);
            printf("El tamanio del motor es: %d\n", conjunto.equipo[i].info.formula1.tamanioMotor);

            // MOSTRAR DATOS PILOTOS
            for (int j = 0; j < conjunto.equipo[i].info.formula1.numeroPiloto; j++){
                printf("El nombre del piloto es: %s\n", conjunto.equipo[i].info.formula1.pilotos[j].nombrePiloto);
                printf("La edad del piloto es: %d\n", conjunto.equipo[i].info.formula1.pilotos[j].edad);
                printf("El numero de victorias del piloto es: %d\n", conjunto.equipo[i].info.formula1.pilotos[j].numeroVictorias);
            }
        break;

        // MOSTRAR DATOS NATACION
        case 3:
            printf("\nMostrar datos de Natacion ----------------\n");
            printf("El numero de nadadores es: %d\n", conjunto.equipo[i].info.natacion.numeroNadadores);
            printf("El precio de la inscripcion es: %f\n", conjunto.equipo[i].info.natacion.precioInscripcion);

            //Mostrar la categoria
            switch (conjunto.equipo[i].info.natacion.categoriaNatacion){
                case CA:
                    printf("La categoria es Cadete\n");
                    break;
                case INF:
                    printf("La categoria es Infantil\n");
                    break;
                case JUN:
                    printf("La categoria es Junior\n");
                    break;
                case SEN:
                    printf("La categoria es Senior\n");
                    break;
                default:
                    printf("Categoría desconocida\n");
                break;
            }

        break;

        default:
            printf("\nNo se ha introducido un tipo de equipo valido\n");
            break;
        }
    }
}

// MAIN --------------------------------------------------------------------------------------
int main(int argc, char *argv[]){

    // Variables
    int opcion = 0;
    conjuntoEquipos_t conjunto;
    conjunto.numeroEquipos = 0;
    bool vacia;
    
    // inicializamos la variable vacia como true
    vacia = true;

    do{
        printf("\n");
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion){
        // INTRODUCIR UN EQUIPO ---------------------------------
        case 1:
            // Variables
            equipo_t equipo;
            if(conjunto.numeroEquipos < TAM){
                conjunto.equipo[conjunto.numeroEquipos] = pedirDatos();
                conjunto.numeroEquipos++;
            }else{
                printf("ERROR! No se pueden introducir mas equipos\n");
            }

            vacia = false;
        break;

        // MOSTRAR LA LISTA DE EQUIPOS --------------------------
        case 2:

            if (vacia){
                printf("ERROR! No hay equipos para mostrar\n");
            }else{
                mostrarListaEquipos(conjunto);
            }

        break;

        // SALIR ------------------------------------------------
        case 3:
            printf("Muchas gracias! Adiosss ;)\n");
            return 1;
        break;

        default:
            printf("Opcion no disponible \n");
            break;
        }
    } while (opcion != 3);

    return 0;
}