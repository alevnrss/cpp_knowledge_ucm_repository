#include <iostream>
#include <fstream>
using namespace std;

const int MESES = 12;
const int DIAS = 31;            // suponiendo que todos los meses tienen 31 dias

typedef double tMatriz[MESES][DIAS];
struct tCoordenadas{            // Estructura para manejar las coordendas de los valores buscados.
    int fila, columna;
};

// Prototipos
void mostrarMatriz(const tMatriz& m1);
void cargarDatos(ifstream& archivo, tMatriz& m1);
bool exito(ifstream& archivo);

// ESQUEMAS DE BUSQUEDA
bool primerValorMayor(const tMatriz& m1, tCoordenadas& posicion);
bool buscarPrimerDescanso(const tMatriz& m1, tCoordenadas& posicion);
bool buscarEnRango(const tMatriz& m1, tCoordenadas& posicion);

int main(){

    tMatriz m1;
    tCoordenadas cor;
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

    if(primerValorMayor(m1, cor)){
        cout << "Se ha encontrado un valor mayor a 1000 en fila: " << cor.fila << " y en columna: " << cor.columna << " , su valor es : " << m1[cor.fila][cor.columna]<< endl;
    } else { cout << "No se ha encontrado un valor mayor a 1000"; }
    
    if(buscarPrimerDescanso(m1, cor)){
        cout << "Se ha encontrado el primer valor nulo en fila: " << cor.fila << " y en columna: " << cor.columna << " , su valor es : " << m1[cor.fila][cor.columna] << endl;
    }else{ cout << "No se ha encontrado ningun valor nulo"; }

    if(buscarEnRango(m1, cor)){
        cout << "Se ha encontrado un valor mayor a 700 en fila: " << cor.fila << " y en columna: " << cor.columna << " , su valor es : " << m1[cor.fila][cor.columna]<< endl;
    } else { cout << "No se ha encontrado un valor mayor a 1000"; }


    archivo.close();

    return 0;
}

// 1.- Cargar datos de un archivo.txt a una matriz -> suponiendo que cada mes tiene 31 dias
void cargarDatos(ifstream& archivo, tMatriz& m1){
    for(int mes = 0; mes < MESES; mes++){
        for(int dia = 0; dia < DIAS; dia++){
            archivo >> m1[ mes ][ dia ];
        }
    }
}

// 2.- Buscar el PRIMER valor mayor a 1000 euros -> SOLUCIÓN: mes 6 (junio)
bool primerValorMayor(const tMatriz& m1, tCoordenadas& posicion){
    bool encontrado = false;
    posicion.fila = 0;
    while(posicion.fila < MESES && !encontrado){
        posicion.columna = 0;
        while(posicion.columna < DIAS && !encontrado){
            if(m1[posicion.fila][posicion.columna] > 1000.0 ){
                encontrado = true;
            }else{
                posicion.columna++;
            }
        }
        if(!encontrado) posicion.fila++;
    }
    return encontrado;
}

// 3.- Buscar el PRIMER valor nulo (descanso de ventas) -> SOLUCIÓN: mes 12 dia 31
bool buscarPrimerDescanso(const tMatriz& m1, tCoordenadas& posicion){
    bool encontrado = false;
    posicion.fila = 0;
    while(posicion.fila < MESES && !encontrado){
        posicion.columna = 0;
        while(posicion.columna < DIAS && !encontrado){
            if(m1[posicion.fila][posicion.columna] == 0.0){
                encontrado = true;
            }else{
                posicion.columna++;
            }
        }

        if(!encontrado) posicion.fila++;
    }

    return encontrado;
}

// 4.- Buscar el PRIMER valor mayor a 700 euros en un rango determinado (mes 3 a 5)

bool buscarEnRango(const tMatriz& m1, tCoordenadas& posicion){
    bool encontrado = false;
    posicion.fila = 2;
    while(posicion.fila < 6 && !encontrado){
        posicion.columna = 0;
        while(posicion.columna < DIAS && !encontrado){
            if(m1[posicion.fila][posicion.columna] > 700.0){
                encontrado = true;
            }else{
                posicion.columna++;
            }
        }

        if(!encontrado) posicion.fila++;
    }

    return encontrado;
}

// SUBPROGRAMAS PRINCIPALES (PLANTILLA PRINCIPAL)
void mostrarMatriz(const tMatriz& m1){
    for(int fila = 0; fila < MESES; fila++){
        for(int columna = 0; columna < DIAS; columna++){
            cout << m1[ fila ][ columna ] << " ";
        }
        cout << endl;
    }
}
bool exito(ifstream& archivo){
    archivo.open("ventas.txt");
    return archivo.is_open();
}