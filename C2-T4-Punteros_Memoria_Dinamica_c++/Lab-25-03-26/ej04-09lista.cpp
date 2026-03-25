// Ejercicio 09 del Tema 4 - ej04-09lista.cpp

#include <iostream>
#include <fstream>
using namespace std;
#include "ej04-09lista.h"
#include "checkML.h"

	

void inicializar(tPlantilla& plantilla) {
	plantilla.numEmpleados = 0;
	plantilla.empleados = new tEmpleado[MAX_EMPLEADOS];	
	plantilla.capacidad = MAX_EMPLEADOS;
}


void destruir(tPlantilla& plantilla) {
	delete [] plantilla.empleados;		// Liberamos la memoria para que no haya fugas
	plantilla.numEmpleados = 0;			// De aqui hacia adelante es por seguridad.
	plantilla.empleados = nullptr;
	plantilla.capacidad = 0;

}

// PRIVADO
// Redimensiona la lista y la deja con los mismos datos.
// Si el incremento es positivo, se amplia la lista. Si es negativo, se reduce
// Lo usaron insertarFinal, eliminarUltimo y eliminarTodos
void redimensionar(tPlantilla &plantilla, int incremento)  {
	tPtrEmp aux;
	plantilla.capacidad = plantilla.capacidad + incremento;
	aux = new tEmpleado[plantilla.capacidad];

	for(int i = 0; i < plantilla.numEmpleados ; i++){		// Si llamamaos a redimensionar es porque el contador tmbn nos indica cuantos empleados habia
		aux[i] = plantilla.empleados[i];
	}
	
	delete [] plantilla.empleados;		// Borramos la antigua direccion de memoria
	plantilla.empleados = aux;			// Copiamos a nuestro puntero la nueva direccion de memoria
}


void insertarFinal(tPlantilla &plantilla, tEmpleado empleado) {
	if(plantilla.numEmpleados == plantilla.capacidad){
		redimensionar(plantilla, MAX_EMPLEADOS);					// Crece en dos
	}
	plantilla.empleados[plantilla.numEmpleados]	 = empleado;
	plantilla.numEmpleados++;
}


void eliminarUltimo(tPlantilla &plantilla) {
	if(plantilla.numEmpleados > 0){
		plantilla.numEmpleados--;
		if((plantilla.capacidad - plantilla.numEmpleados) >= 2*MAX_EMPLEADOS ){
			redimensionar(plantilla, -MAX_EMPLEADOS);
		}
	}
}


void eliminarTodos(tPlantilla &plantilla) {
	plantilla.numEmpleados = 0;
	if(plantilla.capacidad > 2*MAX_EMPLEADOS){
		redimensionar(plantilla, -MAX_EMPLEADOS);
	}	
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
		// no hace falta controlar que la lista se llene porque el subprograma de insercion redimensiona
		while (cargaEmpleado(archivo, empleado))
			insertarFinal(plantilla, empleado);
		archivo.close();
	}
	return ok;
}