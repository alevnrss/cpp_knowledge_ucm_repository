// Esquema de recorrido sobre una secuencia explicita leida por teclado
// Secuencia de numeros positivos
#include <iostream>
#include <string>
using namespace std;

/**
 * Esta secuencia trata de sumar todos los numeros positivos que vaya ingresando el usuario de manera que finalice
 * cuando el usuairo introduzca el numero negativo '-1' (centinela)
 */

int main(){

    double d, suma = 0;
    cout << "Introduce el numero positivo. (-1 termina la secuencia): ";
    cin >> d;                                                                       // inicializacion(Primer elemento)
    while(d != -1){                                                                 // Mientras no sea el centinela
        suma = suma + d;                                                            // procesar elemento
        cout << "Introduce el numero positivo. (-1 termina la secuencia): ";
        cin >> d;                                                                   // siguiente elemento.
    }
    cout << "\nSuma total de todos los numeros introducidos por el usuario: " << suma << endl;

    return 0;
}