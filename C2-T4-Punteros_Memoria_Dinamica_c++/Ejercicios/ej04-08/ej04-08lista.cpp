// Ejercicio 08 del Tema 4 - ej04-08reg.cpp

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "ej04-08lista.h"
#include "checkML.h"

void inicializar(tPlantilla &plantilla)
{
	plantilla.numEmpleados = 0;							// Arrancamos con una lista vacia
	plantilla.empleados = new tEmpleado[MAX_EMPLEADOS]; // Reservamos espacio para el array dinamico. No es array de datos dinamicos
}

void insertarUltimo(tPlantilla &plantilla, tEmpleado empleado)
{
	if (plantilla.numEmpleados < MAX_EMPLEADOS)
	{
		plantilla.empleados[plantilla.numEmpleados] = empleado;
		plantilla.numEmpleados++;
	}
}

void eliminarTodos(tPlantilla &plantilla) // Este subprograma no es para hacer desaparecer el array sino para quitar todos los elementos de ese array dinamico
{
	plantilla.numEmpleados = 0;
}

void eliminarAlUltimo(tPlantilla &plantilla) 
{
	if(plantilla.numEmpleados >  0){
		plantilla.numEmpleados--;
	}
}

void destruir(tPlantilla &plantilla)
{
	// implementar
	delete [] plantilla.empleados;		// Eliminamos el array apuntado por ese puntero
	plantilla.empleados = NULL; 		// Por seguridad ponemos el puntero a NULL
	plantilla.numEmpleados = 0;			// Tambien podemos llamar a eliminarTodos(plantilla.empleados);	que poner su contador a 0

}

void mostrar(const tPlantilla &plantilla)
{
	cout << "Plantilla:" << endl;
	for (int i = 0; i < (plantilla.numEmpleados); i++)
	{
		mostrar(plantilla.empleados[i]);
	}
	cout << "numempleados " << (plantilla.numEmpleados);
}

bool cargarEmpleadosFichero(tPlantilla &plantilla)
{
	ifstream archivo;
	bool ok = true;
	char c;
	int estudiosAux;
	int contratoAux;
	tEmpleado empleado;
	string nombre;
	int edad;
	tEstudios estudios;
	tTipoContrato contrato;

	archivo.open("plantilla.txt");

	if (!archivo.is_open())
	{
		ok = false;
	}
	else
	{
		// implementar
	}

	archivo.close();
	return ok;
}