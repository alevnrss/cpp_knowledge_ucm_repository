#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_FILAS = 10;
const int MAX_COL = 10;

const int incF[4] = {1, -1, -1, 1};
const int incC[4] = {1, 1, -1, -1};
typedef struct tMatriz
{
    int matriz[MAX_FILAS][MAX_COL];
    int fila, col;
};

void mostrardiagonales(const tMatriz &m, int f, int c);
void buscar_suma_par(const tMatriz &m);
// subprogramas ya implementados
void cargar_Matriz(tMatriz &m, ifstream &archivo); // para cargar la matriz desde archivo
void mostrar(const tMatriz &m);                    // para visualizar la matriz por pantalla
int main()
{
    tMatriz m;
    ifstream archivo;
    // archivo.open("matriz1.txt");
    archivo.open("matriz1.txt");
    if (archivo.is_open())
    {
        cargar_Matriz(m, archivo);
        archivo.close();
        mostrar(m);
        // solicitud de posición [fila, columna] desde la que se quieren mostrar las diagonales
        int fila, columna;
        cout << "Introduce la fila y la columna de un punto: " << endl;
        cout << "Fila ";
        cin >> fila;
        cout << "Columna ";
        cin >> columna;

        // INVOCA AQUÍ a mostrar_diagonales PREVIA COMPROBACIÓN DE LA VALIDEZ DE [fila, columna]
        mostrardiagonales(m, fila, columna);
        // INVOCA AQUÍ a buscar_suma_par Y VISUALIZA POR PANTALLA LO QUE DEVUELVE
        buscar_suma_par(m);
    }
    else
    {
        cout << "Archivo inexistente\n";
    }
    return 0;
}

void mostrardiagonales(const tMatriz &m, int f, int c)
{
    int indiceF = f;
    int indiceC = c;
    int indice = 0;
    int sumadorF, sumadorC;

    for (int i = 0; i < 4; i++)
    {
        cout << "Diagonal " << i + 1 << endl;
        sumadorF = incF[i];
        sumadorC = incC[i];
        indiceF = f + sumadorF;
        indiceC = c + sumadorC;
        while (indiceC < m.col && indiceC > -1 && indiceF > -1 && indiceF < m.fila)
        {
            cout << m.matriz[indiceF][indiceC] << " ";
            indiceF += sumadorF;
            indiceC += sumadorC;
        }
        cout << "\n"
             << endl;
    }
}

void buscar_suma_par(const tMatriz &m)
{
    int cont = 0;
    int indiceC = 0;
    int indiceResultado;
    bool e = false;

    while (!e && indiceC < m.col)
    {
        cont = 0;
        for (int fila = 0; fila < m.fila; fila++)
        {
            cont += m.matriz[fila][indiceC];
        }
        if (cont % 2 == 0 && cont > 0)
        {
            e = true;
            indiceResultado = indiceC;
        }
        else
        {
            indiceC++;
        }
    }

    if (!e)
    {
        indiceResultado = -1;
    }

    cout << "La primera columna con suma para>0 es la " << indiceResultado;
}

void cargar_Matriz(tMatriz &m, ifstream &archivo)
{
    archivo >> m.fila >> m.col;
    for (int i = 0; i < m.fila; ++i)
    {
        for (int j = 0; j < m.col; ++j)
            archivo >> m.matriz[i][j];
    }
}

void mostrar(const tMatriz &m)
{
    for (int i = 0; i < m.fila; ++i)
    {
        for (int j = 0; j < m.col; ++j)
        {
            cout << setw(2) << m.matriz[i][j] << " ";
        }
        cout << endl;
    }
}
