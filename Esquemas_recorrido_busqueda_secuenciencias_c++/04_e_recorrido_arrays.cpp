/**
 * Calcular la suma total del array a traves de un esquema de recorrido.
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 2;

typedef int tArray[MAX];

void abrirArchivo(ifstream& archivo, bool& ok);
void guardarSecuencia(ifstream& archivo, tArray a);
void mostrarSecuencia(const tArray a);

int main(){
    ifstream archivo;
    int suma;
    tArray array;
    bool ok;

    abrirArchivo(archivo, ok);
    if(ok){
        cout << "Archivo abierto correctamente" << endl;
        guardarSecuencia(archivo, array);
        mostrarSecuencia(array);
    }

    return 0;
}

void abrirArchivo(ifstream& archivo, bool& ok){
    archivo.open("numeros.txt");
    if(!archivo.is_open()){
        ok = false;
    }else{
        ok = true;
    }
}

void guardarSecuencia(ifstream& archivo, tArray a){
    int indice = 0;
    archivo >> a[indice];
    while(indice < MAX && a[indice] != -1){
        indice++;
        archivo >> a[indice];
    }
}

void mostrarSecuencia(const tArray a){
    for(int i = 0; i < MAX; i++){
        cout << " " << a[i];
    }   
}