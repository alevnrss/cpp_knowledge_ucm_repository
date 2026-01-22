// Para declarar un array como tipo de dato definido por el usuario, lo definiremos mediante TYPEDEF TIPO tNombre[];
#include <iostream>
#include <cstdlib>
using namespace std;

// Variables Globales
const int CAPACIDAD_MAXIMA = 10;

// Estructuras
typedef int tArray[CAPACIDAD_MAXIMA];

// Prototipos
void rellenarArray(tArray a);
void mostrarDatosArray(const tArray a);

int main(){
    srand(time(NULL));
    tArray a;
    rellenarArray(a);
    mostrarDatosArray(a);

    return 0;
}

// FUNCION RELLENAR ARRAY.
// Rellenar array con numeros aleatorios. (1 - 10)
void rellenarArray(tArray a){
    for(int i = 0; i < CAPACIDAD_MAXIMA; i++){
        a[i] = (1 + (rand()%(10 + 1 - 1))) ;
    }
}

// FUNCION MOSTRAR DATOS ARRAY
// Mostrar todos los datos rellenados anteriormente de nuestro array de tipo entero.
void mostrarDatosArray(const tArray a){
    for(int i = 0; i < CAPACIDAD_MAXIMA; i++){
        cout <<"Pos "<< i << " : " << a[i] << endl;
    }
}