#ifndef empresa_h
#define empresa_h
#include "empleado.h"           

typedef struct {
    tEmpleado* listaEmpleados;   // puntero a tEmpleado
    int contador;       // contador de empleados
    int capacidad;      // cuanto espacio total hemos reservado con new
} tListaEmpleados;


void inicializarLista(tListaEmpleados& lista);
bool añadirEmpleado_AlFinal(tListaEmpleados& lista, const tEmpleado& empleado);
bool añadirEmpleado_AlInicio(tListaEmpleados& lista, const tEmpleado& empleado);
bool añadirEmpleado_EnPosicion(tListaEmpleados& lista, const tEmpleado& empleado, int posicion);
bool eliminarEmpleado_AlFinal(tListaEmpleados& lista);
bool eliminarEmpleado_AlInicio(tListaEmpleados& lista);
bool eliminarEmpleado_EnPosicion(tListaEmpleados& lista, int posicion);
void eliminarTodos(tListaEmpleados& lista);
void visualizarPlantilla(const tListaEmpleados& lista);
void cargarDeFichero(tListaEmpleados& lista, ifstream& archivo);
void guardarEnFichero(const tListaEmpleados& lista);


#endif
