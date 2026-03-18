#include "empresa.h"
#include "empleado.h"
#include <iostream>
using namespace std;

// Subprogramas privados
void redimensionar(tListaEmpleados &lista)
{
    lista.capacidad *= 2; // Duplicamos el tamaño de la lista

    tEmpleado *nuevaLista = new tEmpleado[lista.capacidad]; // Pedimos una lista mas grande

    for (int i = 0; i < lista.contador; i++)
    { // Copiamos de nuestra antigua lista a la nueva
        nuevaLista[i] = lista.listaEmpleados[i];
    }

    delete[] lista.listaEmpleados; // Borramos la antigua lista

    lista.listaEmpleados = nuevaLista; // nuestra "lista empleados" sera la nueva lista. Apuntamos a la nueva lista.
}

// Subprogramas publicos
void inicializarLista(tListaEmpleados &lista)
{
    lista.capacidad = 10;
    lista.contador = 0;
    lista.listaEmpleados = new tEmpleado[lista.capacidad];
}

bool añadirEmpleado_AlFinal(tListaEmpleados &lista, const tEmpleado &empleado)
{
    if (lista.capacidad == lista.contador)
    {
        redimensionar(lista);
    }

    lista.listaEmpleados[lista.contador] = empleado;
    lista.contador++;

    return true;
}

bool añadirEmpleado_AlInicio(tListaEmpleados &lista, const tEmpleado &empleado)
{
    if (lista.capacidad == lista.contador)
    {
        redimensionar(lista);
    }
    for (int i = lista.contador; i > 0; i--)
    {
        lista.listaEmpleados[i] = lista.listaEmpleados[i - 1];
    }

    lista.listaEmpleados[0] = empleado;
    lista.contador++;

    return true;
}

bool añadirEmpleado_EnPosicion(tListaEmpleados &lista, const tEmpleado &empleado, int posicion)
{
    if (posicion < 0 || posicion > lista.contador)
    {
        return false;
    }

    if (lista.contador == lista.capacidad)
    {
        redimensionar(lista);
    }

    for (int i = lista.contador; i > posicion; i--)
    {
        lista.listaEmpleados[i] = lista.listaEmpleados[i - 1];
    }

    lista.listaEmpleados[posicion] = empleado;
    lista.contador++;

    return true;
}
bool eliminarEmpleado_AlFinal(tListaEmpleados &lista);
bool eliminarEmpleado_AlInicio(tListaEmpleados &lista);
bool eliminarEmpleado_EnPosicion(tListaEmpleados &lista, int posicion);
void eliminarTodos(tListaEmpleados &lista){
    if(lista.listaEmpleados != nullptr){
        delete[] lista.listaEmpleados;
        lista.listaEmpleados = nullptr;
    }
    lista.capacidad = 0;
    lista.contador = 0;
}
void visualizarPlantilla(const tListaEmpleados &lista)
{
    for (int i = 0; i < lista.contador; i++)
    {
        cout << i ;
        visualizarEmpleado(lista.listaEmpleados[i]);
    }

    cout << "Capacidad de la plantilla: " << lista.capacidad << endl;
    cout << "Numero de empleados en plantilla: " << lista.contador << endl;
}
void cargarDeFichero(tListaEmpleados &lista, ifstream &archivo);
void guardarEnFichero(const tListaEmpleados &lista);
