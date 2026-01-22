// Esquema de recorrido sobre una secuencia explicita leida por teclado
// Secuencia de longitud de caracteres
#include <iostream>
#include <string>
using namespace std;

/**
 * Esta secuencia trata de sumar los caracteres o calcular la longitud de nuestra secuencia (cadena) de manera que se vaya ingresando 
 * hasta que el usuario finalice introduciendo el centinela, que seria el punto '.' (centinela).
 * 
 * Importante: Con el extractor >> no cuenta espacios. Con cin.get(c) si los cuenta.
 */

int main(){

    char c;
    int longitud = 0;
    cout << "Cadena. (-1 termina la secuencia): ";
    cin >> c;                                                                       // inicializacion(Primer elemento)
    while(c != '.'){                                                                 // Mientras no sea el centinela
        longitud = longitud + 1 ;                                                            // procesar elemento
        cin >> c;                                                                   // siguiente elemento.
    }
    cout << "\nLongitud total de la cadena: " << longitud << endl;

    return 0;
}