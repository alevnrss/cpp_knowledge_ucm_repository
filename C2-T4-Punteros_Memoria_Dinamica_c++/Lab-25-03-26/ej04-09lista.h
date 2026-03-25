// Ejercicio 09 del Tema 4 - ej04-09lista.h

#ifndef EJ0409LISTA_H
#define EJ0409LISTA_H

#include "ej04-09reg.h"
#include <string>

const int MAX_EMPLEADOS = 2;

struct tPlantilla {
	int numEmpleados;
	int capacidad;   //Se debe conocer la capacidad de la lista en cada momento 
	tPtrEmp empleados;
};

void inicializar(tPlantilla &plantilla);
void insertarFinal(tPlantilla& plantilla, tEmpleado empleado);
void eliminarUltimo(tPlantilla &plantilla);
void eliminarTodos(tPlantilla &plantilla);
void mostrar(const tPlantilla &plantilla);
void destruir(tPlantilla &plantilla);
bool cargarEmpleadosFichero(std::string nombreArchivo, tPlantilla& plantilla);

#endif