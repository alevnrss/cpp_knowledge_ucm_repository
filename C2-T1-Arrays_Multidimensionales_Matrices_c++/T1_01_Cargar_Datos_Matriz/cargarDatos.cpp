#include <iostream>
#include <fstream>
using namespace std;

const int MESES = 12;
const int DIAS = 31;            // suponiendo que todos los meses tienen 31 dias

typedef double tMatriz[MESES][DIAS];

void mostrarMatriz(const tMatriz& m1);
void cargarDatos(ifstream& archivo, tMatriz& m1);
bool exito(ifstream& archivo);

int main(){

    tMatriz m1;
    bool exitoAbrir;
    ifstream archivo;
    exitoAbrir = exito(archivo);
    if(!exitoAbrir){
        cout << "No se ha logrado abrir el archivo correctamente" << endl;
    }else{
        cout << "El archivo se ha abierto correctamente" << endl;
        cargarDatos(archivo, m1);
        mostrarMatriz(m1);
    }

    archivo.close();
}

void mostrarMatriz(const tMatriz& m1){
    for(int fila = 0; fila < MESES; fila++){
        for(int columna = 0; columna < DIAS; columna++){
            cout << m1[ fila ][ columna ] << " ";
        }
        cout << endl;
    }
}

void cargarDatos(ifstream& archivo, tMatriz& m1){
    for(int mes = 0; mes < MESES; mes++){
        for(int dia = 0; dia < DIAS; dia++){
            archivo >> m1[ mes ][ dia ];
        }
    }
}

bool exito(ifstream& archivo){
    archivo.open("datos.txt");
    return archivo.is_open();
}