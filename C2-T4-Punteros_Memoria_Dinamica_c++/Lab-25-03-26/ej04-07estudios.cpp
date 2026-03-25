#include "ej04-07estudios.h"

#include <string>
#include <iostream>
using namespace std;

void escribirEstudios(tEstudios estudios) {

	string resultado;

	switch (estudios) {
	case ESO: resultado = "ESO"; break;
	case Bachillerato: resultado = "Bachillerato"; break;
	case FP_Medio: resultado = "FP Medio"; break;
	case FP_Superior: resultado = "FP Superior"; break;
	case Grado: resultado = "Grado"; break;
	case Master: resultado = "Master"; break;
	case Doctor: resultado = "Doctor"; break;
	default: resultado = "Desconocido"; break;
	}

	cout << resultado;
}