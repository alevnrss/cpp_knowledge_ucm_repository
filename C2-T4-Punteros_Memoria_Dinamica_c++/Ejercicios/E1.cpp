// Comprobar el resultado que sale con este esquema de punteros
#include <iostream>
using namespace std;

int main()
{
    int x = 5, y = 12, z;                    // Variables x e y inicializadas, z sin inicializar
    int *p1, *p2, *p3;                       // declaramos 3 punteros que guardaran datos de tipo entero
    p1 = &x;                                 // puntero 1 apunta a x  (5)
    p2 = &y;                                 // puntero 2 apunta a y  (12)
    z = *p1 * *p2;                           // z es igual a la multiplicacion de ambos (60)
    p3 = &z;                                 // puntero 3 apunta a ese nuevo valor de z  p3 = (60)
    (*p3)++;                                 // le sumamos uno a ese valor   p3 = 60+1
    p1 = p3;                                 // el puntero 1 va a ser igual al puntero 3  p1 = p3 = 61
    cout << *p1 << " " << *p2 << " " << *p3; // 61, 12, 61

    return 0;
}

void ejercicio_3()
{

    // ¿Qué problema hay en el siguiente código y cómo lo resolverías usandomemoria dinámica?
    double d = 5.4, e = 1.2, f = 0.9;
    double *p1, *p2, *p3;
    p1 = &d;
    (*p1) = (*p1) + 3;
    p2 = &e;
    (*p3) = (*p1) + (*p2); // El problema esta aqui, P3 no esta inicializado.
    cout << *p1 << " " << *p2 << " " << *p3;

    // Resolucion
    // Hay que asignarle espacio de memoria y para eso debo asignarle memoria dinamica
    double d = 5.4, e = 1.2, f = 0.9;
    double *p1, *p2, *p3;
    p1 = &d;
    (*p1) = (*p1) + 3;
    p2 = &e;
    p3 = new double; // Hay que ponerle new para usar memoria dinamica
    (*p3) = (*p1) + (*p2);
    cout << *p1 << " " << *p2 << " " << *p3;
    delete p3;

    // ¿Que problema hay en este otro?
    double d = 5.4, e = 1.2, f = 0.9;
    double *p1, *p2, *p3;
    p1 = new double(d + 3);
    p2 = new double(e);
    p3 = new double;
    (*p3) = (*p1) + (*p2);
    cout << *p1 << " " << *p2 << " " << *p3;            
    
    // El problema es que no hemos puesto el delete, es importante ponerlo por cada new creado.
    delete p1, p2, p3;
}
