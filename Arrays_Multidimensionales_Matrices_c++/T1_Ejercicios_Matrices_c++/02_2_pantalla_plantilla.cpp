// Tema 1 - Ejercicio 2

#include <iostream>
using namespace std;

// Tipos de datos
const int NUM_FILAS = 25;
const int NUM_COLUMNAS = 80;
const int NUM_COLORES = 5;

enum tColor
{
    negro,
    azul,
    verde,
    amarillo,
    rojo
};

struct tPixel
{
    char caracter;
    tColor color, colorFondo;
    bool parpadea;
};

typedef tPixel tPantalla[NUM_FILAS][NUM_COLUMNAS];

typedef struct {
    tPantalla matrizVariable;
    int contadorFilas;
    int contadorColumnas;
} tListaVariable;

// Prototipos

tColor colorMasUtilizado(const tListaVariable pantallaVar, int fila);
void primerParpadeante(const tListaVariable pantallaVar, int &fila, int &columna);
void primerParpadeanteV2(const tListaVariable pantallaVar, int &fila, int &columna);

string aCadena(tColor color);
void borradoPantalla(tListaVariable& pantallaVar);
void colocacionDatosPrueba(tListaVariable& pantallaVar);

int main()
{
    tListaVariable pantallaVar;
    int fila, col;
    tColor maxColor;

    // IMPORTANTE SINO NO FUNCIONA LAS DIMENSIONES
    pantallaVar.contadorColumnas = 25;
    pantallaVar.contadorFilas = 10;

    // Borrado de toda la pantalla
    borradoPantalla(pantallaVar);

    // Inicializacion a datos de prueba
    colocacionDatosPrueba(pantallaVar);

    // Pruebas

    maxColor = colorMasUtilizado(pantallaVar, 0); // buscamos el color de fondo mas usado en la primera fila (el verde)

    cout << "El color mas utilizado en la primera fila " << " es " << aCadena(maxColor) << endl;

    primerParpadeanteV2(pantallaVar, fila, col);

    if (fila == -1)
        cout << "No hay ningun caracter parpadeante" << endl;
    else
        cout << "Primer parpadeante en la fila " << fila << " y columna " << col << endl;

    return 0;
}

tColor colorMasUtilizado(const tListaVariable pantallaVar, int fila)
{
    typedef int tArrayContadores[NUM_COLORES];
    tArrayContadores contadores = {0};

    for (int j = 0; j < NUM_COLUMNAS; j++)
    {
        tColor colorFondo = pantallaVar.matrizVariable[fila][j].colorFondo;
        contadores[colorFondo]++;
    }

    // BUSQUEDA DEL MAXIMO VALOR DE UN ARRAY
    int indiceMaximo = 0;
    for (int i = 0; i < NUM_COLORES; i++)
    {
        if (contadores[i] > indiceMaximo)
        {
            indiceMaximo = i;
        }
    }

    return (tColor)indiceMaximo;
}

void primerParpadeante(const tListaVariable pantallaVar, int &fila, int &columna)
{
    // Devuelve los indices; -1 en fila y en columna si no lo hay
    // ESQUEMA DE BUSQUEDA
    bool encontrado = false;
    int indiceFila = 0, indiceColumna;

    while (indiceFila < pantallaVar.contadorFilas && !encontrado)
    {
        indiceColumna = 0;
        while (indiceColumna < pantallaVar.contadorColumnas && !encontrado)
        {
            if (pantallaVar.matrizVariable[indiceFila][indiceColumna].parpadea == true)
            {
                fila = indiceFila;
                columna = indiceColumna;
                encontrado = true;
            }
            else
            {
                indiceColumna++;
            }
        }
        if (!encontrado)
        {
            indiceFila++;
        }
    }

    if (!encontrado)
    {
        fila = -1;
        columna = -1;
    }
}

string aCadena(tColor color)
{
    string resultado;

    switch (color)
    {
    case negro:
        resultado = "negro";
        break;
    case azul:
        resultado = "azul";
        break;
    case verde:
        resultado = "verde";
        break;
    case amarillo:
        resultado = "amarillo";
        break;
    case rojo:
        resultado = "rojo";
        break;
    default:
        resultado = "Error!";
        break;
    }

    return resultado;
}

void borradoPantalla(tListaVariable& pantallaVar)
{
    for (int i = 0; i < pantallaVar.contadorFilas; i++)
        for (int j = 0; j < pantallaVar.contadorColumnas; j++)
        {
            tPixel pixel = {' ', negro, negro, false};
            pantallaVar.matrizVariable[i][j] = pixel;
        }   
}

void colocacionDatosPrueba(tListaVariable& pantallaVar)
{
    for (int i = 0; i < (pantallaVar.contadorColumnas / 2 + 1); i++)
    {
        tPixel pixel = {' ', amarillo, verde, false};
        pantallaVar.matrizVariable[0][i] = pixel;
    } // en la fila 0 ponemos 41 fondos verdes (con primer plano amarillo)

    pantallaVar.matrizVariable[0][pantallaVar.contadorColumnas - 1].parpadea = true; // el unico parpadeante es la esquina superior derecha
    pantallaVar.matrizVariable[9][pantallaVar.contadorColumnas - 1].parpadea = true;
}

void primerParpadeanteV2(const tListaVariable pantallaVar, int &fila, int &columna)
{
    // Busqueda desde la esquina inferior derecha, recorriendo todas las filas de una columna. De abajo a arriba.
    // Devuelve los indices; -1 en fila y en columna si no lo hay.
    // ESQUEMA DE BUSQUEDA
    bool encontrado = false;
    int indiceFila, indiceColumna = (pantallaVar.contadorColumnas - 1);

    while (indiceColumna > -1 && !encontrado)
    {
        indiceFila = ( pantallaVar.contadorFilas -1 );
        while (indiceFila > -1 && !encontrado)
        {
            if (pantallaVar.matrizVariable[indiceFila][indiceColumna].parpadea == true)
            {
                fila = indiceFila;
                columna = indiceColumna;
                encontrado = true;
            }
            else
            {
                indiceColumna--;
            }
        }
        if (!encontrado)
        {
            indiceFila--;
        }
    }

    if (!encontrado)
    {
        fila = -1;
        columna = -1;
    }
}