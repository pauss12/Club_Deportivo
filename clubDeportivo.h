#ifndef __CLUBDEPORTIVO__H
#define __CLUBDEPORTIVO__H

#define TAM 10
#define TAM_MAX 20
#define MAX 100

// Enumerado de la categoria --------------------------------------------------------------
typedef enum categoria_e{
    CA,  // Cadete
    INF, // Infantil
    JUN, // Junior
    SEN  // Senior
} categoria_e;

// Estructura de un futbol -----
typedef struct futbol_t{
    int numeroJugadores;
    float ratio;
    char posicionLiga[MAX];
    categoria_e categoriaFutbol;
} futbol_t;

// Estructura de piloto ------------------------
typedef struct piloto_t{
    char nombrePiloto[MAX];
    int edad;
    int numeroVictorias;
} piloto_t;

// Estructura para el formula 1 ------------------------
typedef struct formula1_t{
    // Array de pilotos
    piloto_t pilotos[MAX];
    int tamanioMotor;
    int numeroPiloto;
} formula1_t;

// Estructura para la natacion --------------------------
typedef struct natacion_t{
    int numeroNadadores;
    float precioInscripcion;
    categoria_e categoriaNatacion; // Enumerado de las categorias
} natacion_t;

// Informacion -------------------
typedef union informacion_u{
    futbol_t futbol;
    formula1_t formula1;
    natacion_t natacion;
} informacion_u;

// Estructura para un equipo ----------------------
typedef struct equipo_t{
    char nombreEquipo[MAX];
    int tipo;
    informacion_u info;
} equipo_t;

// ESTRUCTURA PARA GUARDAR LA  INFORMACION ------------------------------------------
typedef struct conjuntoEquipos_t{
    equipo_t equipo[TAM];
    int numeroEquipos;
} conjuntoEquipos_t;

// CABECERAS DE LAS FUNCIONES ----------------------------------------------------------------
void mostrarMenu();
void mostrarMenuTipoEquipo();
equipo_t pedirDatos();
void mostrarListaEquipos(conjuntoEquipos_t conjunto);
futbol_t pedirDatosFutbol();
formula1_t pedirDatosFormula1();
natacion_t pedirDatosNatacion();

#endif