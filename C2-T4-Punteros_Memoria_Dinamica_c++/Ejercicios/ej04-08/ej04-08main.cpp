// Ejercicio 08 del Tema 4 - ej04-08main.cpp

#include <iostream>
using namespace std;
#include "ej04-08reg.h"
#include "ej04-08lista.h"
#include "checkML.h"



int main(){

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);  // para comprobar las fugas de memoria

		tPlantilla  plantilla;

		cargarEmpleadosFichero(plantilla);  // implementado parcialmente (falta subprograma al que invoca)

		cout << "Tras contratar...\n";
		mostrar(plantilla); // implementado

		cout << "Tras despedir a todos...\n"; 
		eliminarTodos(plantilla); // sin implementar

		mostrar(plantilla); // implementado

		destruir(plantilla); // sin implementar



	return 0;
}

