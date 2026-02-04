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
bool filaConfortable(const tMatriz m, int fila );
int exploraMatriz(const tMatriz m);

int main()
{
    tMatriz m;
    ifstream archivo;
    bool exito, encontrado;
    int totalConfortables;

    cargarMatriz(m, archivo, exito);

    if (!exito) // funcion para cargar matriz
        cout << "ERROR al cargar la matriz" << endl;
    else
    {
        mostrarMatriz(m);
        encontrado = filaConfortable(m, 5);
        if(!encontrado){
            cout << "No es confortable" << endl;
        }else{
            cout << "Es confortable" << endl;
        }

        totalConfortables = exploraMatriz(m);
        cout << "Hay un total de " << totalConfortables << " arboles confortables";
        
    }
    return 0;
}

// Implementacion de funciones.

// subprograma para la carga de la matriz con respecto a la
void cargarMatriz(tMatriz m, ifstream& archivo, bool& exito){
    archivo.open("matriz1.txt");
    if(!archivo.is_open()){
        exito = false;
    }else{
        exito = true;
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
        archivo.close();
    }

}

// Subprograma para saber si el arbol seleccionado es confortable o no lo es.
bool filaConfortable(const tMatriz m, int fila ){
    
    int indiceColumna = 0, sumatorio = 0;
    bool encontrado = false;
    while(indiceColumna < NUMPAJAROS && !encontrado){
        sumatorio = sumatorio + m[fila][indiceColumna];
        if(sumatorio >= 30){
            encontrado = true;
        }else{
            indiceColumna++;
        }
    }

    return encontrado;
}

// Subprograma para devolver el numero de arboles que son confortables.
int exploraMatriz(const tMatriz m){
    int total = 0;
    for(int i = 0; i < NUMARBOLES; i++){
        if(filaConfortable(m, i)){
            total++;
        }
    }
    return total;
}

// subprograma para la visualizacion de matrices
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
