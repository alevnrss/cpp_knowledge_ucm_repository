#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// variables constantes implementadas
const int MAX_FILAS = 10;
const int MAX_COLUMNAS = 10;
const int incF[4] = {1, -1, 1, -1};
const int incC[4] = {-1, 1, -1, 1};

// estructuras implementadas
struct tMatriz
{
    int matriz[MAX_FILAS][MAX_COLUMNAS];
    int nfila, ncolumna;
};

// subprogramas a implementar
void mostrar_diagonales(const tMatriz &m, int fila, int col);
int buscar_suma_par(const tMatriz &m);

// subprogramas implementados
void cargar_Matriz(tMatriz &m, ifstream &archivo); // para cargar la matriz desde el archivo
void mostrar(const tMatriz &m);                    // para visualizar la matriz por pantalla

int main()
{
    tMatriz m;
    ifstream archivo;
    archivo.open("matriz.txt");
    // archivo.open("matriz2.txt");
    if (archivo.is_open())
    {
        cargar_Matriz(m, archivo);
        archivo.close();
        mostrar(m);

        // solicitud de posicion [fila, columna] desde la que se quieren mostrar las diagonales
        int fila, columna;
        cout << "Introduce la fila y la columna de un punto: " << endl;
        cout << "Fila ";
        cin >> fila;
        cout << "Columna ";
        cin >> columna;

        // Invocacion de subprogramas a realizar
    }
    else
    {
        cout << "Archivo inexistente\n";
    }
    return 0;
}

void mostrar_diagonales(const tMatriz &m, int fila, int col)
{
    int cont, f, c;
    for (int dir = 0; dir < 4; dir++)
    {
        cout << "Diagonal " << dir + 1 << endl;
        // Calculo la posicion [f , c] del elemento
        cont = 1;
        f = fila + incF[dir] * cont;
        c = col + incC[dir] * cont;

        // Mientras [f , c] esten dentro de la matriz
        while (f >= 0 && fila < m.nfila && c >= 0 && col < m.ncolumna)
        {
            // Visualizacion del elemento en posicion (f,c)
            cout << m.matriz[f][c] << " ";
            // Calculo de la siguiente posicion (f,c)
            cont++;
            f = fila + incF[dir] * cont;
            c = col + incC[dir] * cont;
        }
        cout << endl;
    }
    cout << endl;
}

void mostrar(const tMatriz &m)
{
}

//
