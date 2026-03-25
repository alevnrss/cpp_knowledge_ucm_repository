// Ejercicio 09 del Tema 4 - ej04-09reg.h

#ifndef EJ0409REG_H
#define EJ0409REG_H

#include "ej04-07estudios.h"
#include "ej04-07contratos.h"
#include <fstream>
#include <string>


struct tEmpleado {
	string nombre;
	int edad;
	tEstudios estudios;
	tTipoContrato contrato;
};

typedef tEmpleado *tPtrEmp;

void muestraEmpleado(tEmpleado empleado);
bool cargaEmpleado(std::ifstream& archivo, tEmpleado& empleado);
void construir(std::string nombre, int edad, tEstudios est, tTipoContrato cont, tEmpleado& empleado);


#endif