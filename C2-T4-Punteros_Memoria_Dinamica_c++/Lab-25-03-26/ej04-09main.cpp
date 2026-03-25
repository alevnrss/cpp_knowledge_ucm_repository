// Ejercicio 09 del Tema 4 - ej04-09main.cpp

#include <iostream>
using namespace std;
#include "ej04-09reg.h"
#include "ej04-09lista.h"
#include "checkML.h"

const string nombreArchivo = "plantilla.txt";


int main(){
	// instruccion para detectar fugas de memoria en VS
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF ); 


	tPlantilla  plantilla;

	if (cargarEmpleadosFichero(nombreArchivo, plantilla)) {
		mostrar(plantilla);

		// introducir aqui codigo para probar el resto de subprogramas

	}


	return 0;
}

