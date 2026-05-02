#include <iostream>
#include <fstream>

using namespace std;

// Variables constantes
const int MaxDías = 31;
const int MED = 2; 

// Estructuras 
typedef double tTemp[MaxDías][MED];

// Prototipos
bool abrirArchivo(ifstream& archivo);
void cargarDatos(ifstream& archivo, tTemp& temp);
void mostrar(const tTemp& temp);
void calcularMedia(const tTemp& temp, double& tMaxMedia, double& tMinMedia);
void calcularMediaAbsoluta(const tTemp& temp, double& tMaxMedia, double& tMinMedia, double& tMinAbs, double& tMaxAbs);


int main(){
    ifstream archivo;
    tTemp temp;
    double tMaxMedia = 0, tMinMedia = 0, tMaxAbs = -100, tMinAbs = 100;

    if(!abrirArchivo(archivo)){
        cout << "No se ha podido abrir el archivo correctamente" << endl;
    }else{
        cout << "Archivo abierto correctamente" << endl;
        cargarDatos(archivo, temp);
        mostrar(temp);

        calcularMedia(temp, tMaxMedia, tMinMedia);
        calcularMediaAbsoluta(temp, tMaxMedia, tMinMedia, tMinAbs, tMaxAbs);

        cout << "La media de todas las temperaturas MAXIMAS del mes es : " << tMaxMedia << endl;
        cout << "La media de todas las temperaturas MINIMAS del mes es : " << tMinMedia << endl;
        cout << "La media absoluta de todas las temperaturas MINIMAS del mes es : " << tMaxAbs << endl;
        cout << "La media absoluta de todas las temperaturas MAXIMAS del mes es : " << tMinAbs<< endl;
    
    }

    archivo.close();

    return 0;
}

bool abrirArchivo(ifstream& archivo){
    archivo.open("temperaturas.txt");
    return archivo.is_open();
}

void cargarDatos(ifstream& archivo, tTemp& temp){
    for(int dia = 0; dia < MaxDías; dia++){
        for(int temperatura = 0; temperatura < MED; temperatura++){
            archivo >> temp[dia][temperatura];
        }
    }
}

void mostrar(const tTemp& temp){
    for(int fila = 0; fila < MaxDías ; fila++){
        cout << "Dia " << fila + 1 << ": "; 
        for(int columna = 0; columna < MED; columna++){
            cout << temp[fila][columna] << "     ";
        }
        cout << endl;
    }
}

// 1.- Calcular la media de las temperaturas MAXIMAS y MINIMAS del mes
void calcularMedia(const tTemp& temp, double& tMaxMedia, double& tMinMedia){
    for(int dia = 0; dia < MaxDías ; dia++){
        tMaxMedia += temp[dia][1];
        tMinMedia += temp[dia][0];
    }
}

// Comentario: Podemos hacer todo en un mismo bucle pero en este caso lo divido para verlo mejor
// 2.- Calcular la temperatura MINIMA ABSOLUTA y MAXIMA ABSOLUTA del mes

void calcularMediaAbsoluta(const tTemp& temp, double& tMaxMedia, double& tMinMedia, double& tMinAbs, double& tMaxAbs){
    for(int dia = 0; dia < MaxDías ; dia++){
        tMaxMedia += temp[dia][1];
        tMinMedia += temp[dia][0];

        // Comparacion para Maxima Absoluta
        if(temp[dia][1] > tMaxAbs){
            tMaxAbs = temp[dia][1];
        }

        // Comparacion para Minima Absoluta
        if(temp[dia][0] < tMinAbs){
            tMinAbs = temp[dia][0];
        }
    }

}
