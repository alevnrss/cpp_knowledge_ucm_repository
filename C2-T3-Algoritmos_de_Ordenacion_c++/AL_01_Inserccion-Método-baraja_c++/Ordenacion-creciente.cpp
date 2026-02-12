#include <iostream>
using namespace std;

// Valores globales
const int N = 10;

// Estructuras
typedef int tArray[N];

// subprogramas principales
void mostrarArray(const tArray a);

// Prototipos
void ordenarArrayCrecientemente(tArray array);

int main()
{
    tArray a = {7, 14, 2, 4, 2, 45, 20, 23, 65, 14};

    mostrarArray(a);
    ordenarArrayCrecientemente(a);
    cout << "\nArray ordenado de manera Creciente: " << endl;
    mostrarArray(a);
    return 0;
}

void mostrarArray(const tArray a)
{
    cout << "[ ";
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << "]";
}

void ordenarArrayCrecientemente(tArray array)
{
    int nuevo, pos;

    for (int i = 1; i < N; i++)
    {            // Recorrermos desde el segundo elemento hasta el ultimo(Parte desordenada)
        pos = 0; // La posicion 0 es el primer elemento de la parte Ordenada
        while (pos < i && array[pos] <= array[i])
        { // Buscamos en zona ordenada && El primer mayor que el elemento a colocar
            pos++;
        }

        // Si sale del bucle es que ya tenemos el valor de la posicion (indice mayor). Entonces haremos hueco -> DESPLAZAMIENTO A LA DERECHA
        nuevo = array[i];
        for (int j = i; j > pos; j--)
        {
            array[j] = array[j - 1];
        }
        array[pos] = nuevo;
    }
}