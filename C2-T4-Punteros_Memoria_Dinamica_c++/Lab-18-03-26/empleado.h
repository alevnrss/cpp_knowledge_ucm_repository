#ifndef empleado_h
#define empleado_h

#include <iostream>
using namespace std;

// Enumerado para grado de estudios y tipo de contratacion
typedef enum {  ESO, BACHILLERATO, FP_GRADO_MEDIO, FP_GRADO_SUPERIOR, GRADO, MASTER, DOCTORADO } tGradoEstudios;
typedef enum { FIJO, EN_PRACTICAS, EVENTUAL, BECARIO } tTipoContratacion;

// Estructura para empleado.
typedef struct {
    string nombre;
    int edad;
    tGradoEstudios tipoGrado;
    tTipoContratacion tipoContratacion;
} tEmpleado;

void visualizarEmpleado(const tEmpleado& empleado);
#endif