#include <iostream>
#include <fstream>
using namespace std;

const int NUMVISITAS = 30;
const int NUMARBOLES = 6;
const int NUMPAJAROS = 12;
typedef int tMatriz[NUMARBOLES][NUMPAJAROS];

// visualiza la matriz por pantalla
void mostrarMatriz(const tMatriz m);

// Prototipos
void cargarMatriz(tMatriz m, ifstream& archivo, bool& exito);
void filaConfortable(tMatriz m, int fila, bool& exito );

int main()
{
    tMatriz m;
    ifstream archivo;
    bool exito;

    cargarMatriz(m, archivo, exito);

    if (exito) // funcion para cargar matriz
        cout << "ERROR al cargar la matriz" << endl;
    else
    {
        mostrarMatriz(m);
        filaConfortable(m, 55, exito);
        if(!exito){
            cout << "No es confortable";
        }else{
            cout << "Es confortable";
        }
        

    }
    return 0;
}

// A�ADE AQU� LA IMPLEMENTACI�N DE TUS FUNCIONES

// subprograma para la carga de la matriz con respecto a la
void cargarMatriz(tMatriz m, ifstream& archivo, bool& exito){
    archivo.open("matriz1.txt");
    if(!archivo.is_open()){
        exito = false;
    }else{
        int i = 0;
        int j;
        while(i < NUMARBOLES && !archivo.eof()){
            j = 0;
            while(j < NUMPAJAROS){
                archivo >> m[i][j];
                j++;
            }
            i++;
        }
    }

}

// Subprograma para saber si el arbol seleccionado es confortable o no lo es.
void filaConfortable(tMatriz m, int fila, bool& exito ){
    
    int indiceColumna = 0, sumatorio = 0;
    exito = false;
    while(indiceColumna < NUMPAJAROS && !exito){
        sumatorio = sumatorio + m[fila][indiceColumna];
        if(sumatorio >= 30){
            exito = true;
        }else{
            indiceColumna++;
        }
    }
}

// subprograma para la visualizaci�n de matrices
void mostrarMatriz(const tMatriz m)
{
    cout << "MATRIZ" << endl;
    for (int f = 0; f < NUMARBOLES; f++)
    {
        for (int c = 0; c < NUMPAJAROS; c++)
            cout << m[f][c] << " ";
        cout << endl;
    }
    cout << endl;
}
