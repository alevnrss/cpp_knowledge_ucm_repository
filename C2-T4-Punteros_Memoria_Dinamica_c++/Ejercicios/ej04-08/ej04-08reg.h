// Ejercicio 08 del Tema 4 - ej04-08reg.h

#ifndef EJ0408REG_H
#define EJ0408REG_H

#include <string>
using namespace std;

enum tEstudios { ESO, Bachillerato, FP_Medio, FP_Superior, Grado, Master, Doctor };

enum tTipoContrato {Fijo, Practicas, Eventual, Becario};

struct tEmpleado {
	string nombre;
	int edad;
	tEstudios estudios;
	tTipoContrato contrato;
};

typedef tEmpleado *tPtrEmp;		// Esto lo utilizamos en el modulo de la lista

void mostrar(tEmpleado empleado);
void construir(string nombre, int edad, tEstudios est, tTipoContrato cont, tEmpleado &empleado);

#endif