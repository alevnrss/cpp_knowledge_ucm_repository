#include "empleado.h"
#include <iostream>
using namespace std;

void visualizarEmpleado(const tEmpleado &empleado)
{
    string grado, contrato;
    switch (empleado.tipoGrado)
    {
    case 0:
        grado = "ESO";
        break;
    case 1:
        grado = "BACHILLERATO";
        break;
    
    case 2:
        grado = "FP GRADO MEDIO";
        break;
        
    case 3:
        grado = "FP GRADO SUPERIOR";
        break;
        
    case 4:
        grado = "GRADO";
        break;
        
    case 5:
        grado = "MASTER";
        break;
        
    case 6:
        grado = "DOCTORADO";
        break;
    }

    switch (empleado.tipoContratacion)
    {
    case 0:
        contrato = "FIJO";
        break;
    case 1:
        contrato = "EN PRACTICAS";
        break;
    
    case 2:
        contrato = "EVENTUAL";
        break;
        
    case 3:
        contrato = "BECARIO";
        break;
    }

    cout << ": Nombre: " << empleado.nombre << " | Edad: " << empleado.edad << " | Estudios: " << grado << " | Contratacion: " << contrato << endl;
}