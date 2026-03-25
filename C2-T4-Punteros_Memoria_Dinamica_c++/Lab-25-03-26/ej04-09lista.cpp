// Ejercicio 09 del Tema 4 - ej04-09lista.cpp

#include <iostream>
#include <fstream>
using namespace std;
#include "ej04-09lista.h"
#include "checkML.h"

	

void inicializar(tPlantilla& plantilla) {
	// impleméntalo...

}


void destruir(tPlantilla& plantilla) {
	// impleméntalo...

}


// PRIVADO
// Redimensiona la lista y la deja con los mismos datos.
// Si el incremento es positivo, se amplia la lista. Si es negativo, se reduce
// Lo usarán insertarFinal, eliminarUltimo y eliminarTodos
void redimensionar(tPlantilla &plantilla, int incremento)  {
	// impleméntalo...
	
}


void insertarFinal(tPlantilla &plantilla, tEmpleado empleado) {
	// impleméntalo...

}



void eliminarUltimo(tPlantilla &plantilla) {
	// implementalo...

}



void eliminarTodos(tPlantilla &plantilla) {
	// implementalo...

}


void mostrar(const tPlantilla &plantilla) {
   cout << "Plantilla:" << endl;
   for (int i = 0; i < plantilla.numEmpleados; i++)
      muestraEmpleado(plantilla.empleados[i]);
   cout << plantilla.numEmpleados << " / " << plantilla.capacidad << endl << endl;
}



bool cargarEmpleadosFichero(string nombreArchivo, tPlantilla& plantilla) {
	ifstream archivo;
	bool ok = true;
	tEmpleado empleado;

	inicializar(plantilla);
	archivo.open(nombreArchivo);
	if (!archivo.is_open())
		ok = false;
	else {
		// no hace falta controlar que la lista se llene porque el subprograma de inserción redimensiona
		while (cargaEmpleado(archivo, empleado))
			insertarFinal(plantilla, empleado);
		archivo.close();
	}
	return ok;
}