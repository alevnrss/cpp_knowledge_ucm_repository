#include "empresa.h"
#include <fstream>
#include <iostream>
using namespace std;

// g++ main.cpp empresa.cpp empleado.cpp -o main
// .\main

// prototipos
int menu();
void formularioEmpleado(tEmpleado &empleado);

int main()
{

    tListaEmpleados lista;
    tEmpleado empleado;
    bool exito;
    int posicion = 0; 

    inicializarLista(lista);
    int opcion = menu();
    while (opcion != 11)
    {
        switch (opcion)
        {
        case 1:
            formularioEmpleado(empleado);
            exito = añadirEmpleado_AlFinal(lista, empleado);
            if (exito)
            {
                cout << "Empleado anadido correctamente al final de la lista." << endl;
            }
            else
            {
                cout << "Error" << endl;
            }
            break;

        case 2:
            formularioEmpleado(empleado);
            exito = añadirEmpleado_AlInicio(lista, empleado);
            if (exito)
            {
                cout << "Empleado anadido correctamente al inicio de la lista." << endl;
            }
            else
            {
                cout << "Error" << endl;
            }
            break;
        case 3:
            formularioEmpleado(empleado);
            cout << "Introduce la posicion: ";
            cin >> posicion;
            exito = añadirEmpleado_EnPosicion(lista, empleado, posicion);
            if (exito)
            {
                cout << "Empleado anadido correctamente en la posicion "<< posicion << " de la lista." << endl;
            }else{
                cout << "Error" << endl;
            }

            break;

        case 7:
            eliminarTodos(lista);
            inicializarLista(lista);
            cout << "Lista vaciada correctamente" << endl; 
            break;

        case 8:
            cout << "----------------------------------  PLANTILLA  --------------------------" << endl;
            visualizarPlantilla(lista);
            break;
        
        default:
            break;
        }

        opcion = menu();
    }

    eliminarTodos(lista);                       // Aqui lo que hacemos es el delete[] y dejar el puntero vacio.
    cout << "Saliendo del programa" << endl;

    return 0;
}

int menu()
{
    int opcion = -1;
    while (opcion < 1 || opcion > 11)
    {
        cout << "Elige una de las siguientes opciones: " << endl;
        cout << "Opcion 1: Anadir nuevo empleado al FINAL de la lista" << endl;
        cout << "Opcion 2: Anadir nuevo empleado al INICIO de la lista" << endl;
        cout << "Opcion 3: Anadir nuevo empleado en una POSICION ESPECIFICA" << endl;
        cout << "Opcion 4: Eliminar el ULTIMO empleado de la lista " << endl;
        cout << "Opcion 5: Eliminar el PRIMER empleado de la lista" << endl;
        cout << "Opcion 6: Eliminar el empleado en una POSICION ESPECIFICA" << endl;
        cout << "Opcion 7: Eliminar TODOS los empleados -> VACIAR e INICIALIZAR" << endl;
        cout << "Opcion 8: Visualizar plantilla por pantalla" << endl;
        cout << "Opcion 9: Cargar la plantilla desde archivo de texto" << endl;
        cout << "Opcion 10: Guardar la plantilla en un archivo de texto" << endl;
        cout << "Opcion 11: Salir del programa... " << endl;
        cin >> opcion;
        if (opcion < 1 || opcion > 11)
        {
            cout << "La opcion elegida es incorrecta..." << endl;
        }
    }

    return opcion;
}

void formularioEmpleado(tEmpleado &empleado)
{
    int grado, contrato;
    cout << "Nombre del Empleado: ";
    cin >> empleado.nombre;
    cout << "Edad del Empleado: ";
    cin >> empleado.edad;
    cout << "Grado de estudios del Empleado: 0 = ESO, 1 = BACHILLERATO, 2 = FP_GRADO_MEDIO, 3 = FP_GRADO_SUPERIOR, 4 = GRADO, 5 = MASTER, 6 = DOCTORADO :";
    cin >> grado;
    empleado.tipoGrado = tGradoEstudios(grado);
    cout << "Contrato del empleado: 0 = FIJO, 1 = EN_PRACTICAS, 2 = EVENTUAL, 3 = BECARIO :";
    cin >> contrato;
    empleado.tipoContratacion = tTipoContratacion(contrato);
}