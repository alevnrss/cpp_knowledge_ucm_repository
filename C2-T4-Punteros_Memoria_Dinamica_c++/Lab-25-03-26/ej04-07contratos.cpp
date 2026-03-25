#include "ej04-07contratos.h"

#include <string>
#include <iostream>
using namespace std;

void escribirContrato(tTipoContrato contrato) {

	string resultado;

	switch (contrato) {
	case Fijo: resultado = "Fijo"; break;
	case Practicas: resultado = "Practicas"; break;
	case Eventual: resultado = "Eventual"; break;
	case Becario: resultado = "Becario"; break;
	default: resultado = "Desconocido"; break;
	}

	cout << resultado;
}

