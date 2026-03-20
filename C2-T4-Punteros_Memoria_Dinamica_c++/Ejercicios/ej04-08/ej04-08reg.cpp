// Ejercicio 08 del Tema 4 - ej04-08reg.cpp

#include <iostream>
#include <string>
using namespace std;
#include "ej04-08reg.h"
#include "checkML.h"


// subprogramas privados, auxiliares
string cad_estudios(tEstudios est) {
	string cad;
	switch (est) {
	case (ESO) : cad = "ESO"; break;
	case (Bachillerato) : cad = "Bachillerato"; break;
	case (FP_Medio) : cad = "F.P. de grado medio"; break;
	case (FP_Superior) : cad = "F.P. de grado superior"; break;
	case (Grado) : cad = "Grado"; break;
	case (Master) : cad = "Master"; break;
	case (Doctor) : cad = "Doctorado"; break;
	}
	return cad;
}

string cad_contrato(tTipoContrato cont) {
	string cad;
	switch (cont) {
	case (Fijo) : cad = "Contrato fijo"; break;
	case (Practicas) : cad = "Contrato en practicas"; break;
	case (Eventual) : cad = "Contrato eventual"; break;
	case (Becario) : cad = "Becario"; break;
	}
	return cad;
}

// subprogramas publicos

void mostrar(tEmpleado empleado) {
   cout << empleado.nombre << " (" << empleado.edad << ") - "
        << "Estudios: " << cad_estudios(empleado.estudios) << " - "
        << cad_contrato(empleado.contrato) << endl;
}

void construir(string nombre, int edad, tEstudios est, tTipoContrato cont, tEmpleado &empleado) {
   empleado.nombre = nombre;
   empleado.edad = edad;
   empleado.estudios = est;
   empleado.contrato = cont;
}

