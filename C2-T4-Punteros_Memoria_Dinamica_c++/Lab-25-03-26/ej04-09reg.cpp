// Ejercicio 09 del Tema 4 - ej04-09reg.cpp

#include <iostream>
using namespace std;
#include "ej04-09reg.h"
#include "checkML.h"

void muestraEmpleado(tEmpleado empleado) {
	cout << "Nombre: " << empleado.nombre;
	cout << " - ";
	cout << "Titulacion: ";
	escribirEstudios(empleado.estudios);
	cout << " - ";
	cout << "Edad: " << empleado.edad;
	cout << " - ";
	cout << "Contrato: ";
	escribirContrato(empleado.contrato);
	cout << endl;
}

bool cargaEmpleado(ifstream& archivo, tEmpleado& empleado) {
	int estudiosAux;
	int contratoAux;
	bool ok = true;

	getline(archivo, empleado.nombre);
	if (empleado.nombre != "XXX") {
		archivo >> empleado.edad;
		archivo >> estudiosAux;
		empleado.estudios = tEstudios(estudiosAux);
		archivo >> contratoAux;
		empleado.contrato = tTipoContrato(contratoAux);
		archivo.ignore();
	}
	else ok = false;
	return ok;
}


void construir(string nombre, int edad, tEstudios est, tTipoContrato cont, tEmpleado& empleado) {
	empleado.nombre = nombre;
	empleado.edad = edad;
	empleado.estudios = est;
	empleado.contrato = cont;
}