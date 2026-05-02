#include <iostream>
using namespace std;
int main()
{

    // Declaración de punteros y variables normales.
    int *p, *x, i = 10, j = 20;

    p = &i; // Asignamos la direccion de memoria de la variable i a nuestro puntero p.
    x = &j; // Asignamos la direccion de memoria de la variable j a nuestro puntero p.

    // Comprobación de las diferentes salidas del puntero p y variable i
    cout << "Variable i | puntero p" << endl;
    cout << *p << endl;     // Imprime el valor de la dirección al que apunta
    cout << p << endl;      // Imprime la direccion al que apunta
    cout << &i << endl;     // Imprime la direccion de la variable i
    cout << &p << endl;     // Imprime la direccion de la variable puntero p.

    // Comprobación de las diferentes salidas del puntero x y variable j
    cout << "\nVariable j | puntero x" << endl;
    cout << *x << endl;     // Imprime el valor de la direccion al que apunta
    cout << x << endl;      // Imprime la direccion al que apunta
    cout << &j << endl;     // Imprime la direccion de la variable j

    return 0;
}