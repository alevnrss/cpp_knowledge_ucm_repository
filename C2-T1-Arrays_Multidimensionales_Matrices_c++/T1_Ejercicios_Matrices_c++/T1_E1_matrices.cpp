#include <iostream>
using namespace std;

// variables globales
const int FILAS = 2;
const int COLUMNAS = 2;

// Estructuras
typedef int tMatriz[FILAS][COLUMNAS];

// Prototipos
void rellenarMatriz(tMatriz m);
void mostrarMatriz(tMatriz m);
void sumarMatrices(tMatriz m1, tMatriz m2, tMatriz mr);
void restarMatrices(tMatriz m1, tMatriz m2, tMatriz mr);
void multiplicarMatrices(tMatriz m1, tMatriz m2, tMatriz mr);

int main()
{

    tMatriz m1, m2, mr;

    cout << "Rellena la matriz m1: " << endl;
    rellenarMatriz(m1);
    cout << "Rellena la matriz m2: " << endl;
    rellenarMatriz(m2);

    cout << "Mostrando matriz 1:" << endl;
    mostrarMatriz(m1);
    cout << "Mostrando matri< 2: " << endl;
    mostrarMatriz(m2);

    sumarMatrices(m1, m2, mr);
    cout << "\nRESULTADO FINAL DE SUMA DE MATRICES: " << endl;
    mostrarMatriz(mr);

    restarMatrices(m1, m2, mr);
    cout << "\nRESULTADO FINAL DE RESTA DE MATRICES: " << endl;
    mostrarMatriz(mr);

    multiplicarMatrices(m1, m2, mr);
    cout << "\nRESULTADO FINAL DE MULTIPLICACION DE MATRICES: " << endl;
    mostrarMatriz(mr);

    return 0;
}

void rellenarMatriz(tMatriz m)
{
    int numeroUser;

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            cout << "Agrega valor en la FILA : " << i << " COLUMNA : " << j << endl;
            cin >> numeroUser;
            m[i][j] = numeroUser;
        }
    }
}
void mostrarMatriz(tMatriz m)
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void sumarMatrices(tMatriz m1, tMatriz m2, tMatriz mr)
{
    int valorm1, valorm2, valormr = 0;
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            valorm1 = m1[i][j];
            valorm2 = m2[i][j];
            valormr = valorm1 + valorm2;
            mr[i][j] = valormr;
        }
    }
}

void restarMatrices(tMatriz m1, tMatriz m2, tMatriz mr)
{
    int valorm1, valorm2, valormr = 0;
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            valorm1 = m1[i][j];
            valorm2 = m2[i][j];
            valormr = valorm1 - valorm2;
            mr[i][j] = valormr;
        }
    }
}

void multiplicarMatrices(tMatriz m1, tMatriz m2, tMatriz mr)
{
    int valorm1, valorm2, valorMultiplicacion, valormr = 0;

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
        }
    }
}
