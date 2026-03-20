// Ejercicio 08 del Tema 4 - ej04-08lista.h

#ifndef EJ0408LISTA_H
#define EJ0408LISTA_H

#include "ej04-08reg.h"

const int MAX_EMPLEADOS = 100;

struct tPlantilla {
	int numEmpleados;
	tPtrEmp empleados;			// puntero a tipo tEmpleado -> 04-08reg.h
};

void inicializar(tPlantilla &plantilla); // sin implementar
bool cargarEmpleadosFichero(tPlantilla &plantilla);  // a falta de insertarUltimo
void insertarUltimo(tPlantilla &plantilla, tEmpleado empleado); // incompleto
void mostrar(const tPlantilla &plantilla); // implementado
void eliminarTodos(tPlantilla &plantilla); // sin implementar
void destruir(tPlantilla &plantilla);// sin implementar



//void insertarPrimero(tPlantilla &plantilla, tEmpleado empleado);
//void insertar(tPlantilla &plantilla, tEmpleado empleado, int posicion);
//void eliminarUltimo(tPlantilla &plantilla);
//void eliminarPrimero(tPlantilla &plantilla);
//void eliminar(tPlantilla &plantilla, int posicion);
//void guardarEmpleados(const tPlantilla &plantilla);

#endif