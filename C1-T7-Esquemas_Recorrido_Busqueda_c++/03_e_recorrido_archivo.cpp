/**
 * Calcular la suma total de los numeros ubicados en un archivo mediante un esquema de recorrido.
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void abrirArchivo(ifstream& archivo, bool& ok);
int calcularSecuencia(ifstream& archivo);

int main(){
    ifstream archivo;
    int suma;
    bool ok;
    

    abrirArchivo(archivo, ok);
    if(ok){
        cout << "Archivo abierto correctamente" << endl;
        suma = calcularSecuencia(archivo);
        cout << "La suma total es: " << suma << endl;
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

int calcularSecuencia(ifstream& archivo){
    int numero, suma = 0;
    archivo >> numero;
    while(numero != -1){
        suma = suma + numero;
        archivo >> numero;
    }

    return suma;
}