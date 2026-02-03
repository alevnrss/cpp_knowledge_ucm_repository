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

// Prototipos

tColor colorMasUtilizado(const tPantalla pantalla, int fila);
void primerParpadeante(const tPantalla pantalla, int &fila, int &columna);

string aCadena(tColor color);
void borradoPantalla(tPantalla pantalla);
void colocacionDatosPrueba(tPantalla pantalla);

int main()
{
    tPantalla pantalla;
    int fila, col;
    tColor maxColor;

    // Borrado de toda la pantalla
    borradoPantalla(pantalla);

    // Inicializacion a datos de prueba
    colocacionDatosPrueba(pantalla);

    // Pruebas

    maxColor = colorMasUtilizado(pantalla, 0); // buscamos el color de fondo mas usado en la primera fila (el verde)

    cout << "El color mas utilizado en la primera fila " << " es " << aCadena(maxColor) << endl;

    primerParpadeante(pantalla, fila, col);

    if (fila == -1)
        cout << "No hay ningun caracter parpadeante" << endl;
    else
        cout << "Primer parpadeante en la fila " << fila << " y columna " << col << endl;

    return 0;
}

tColor colorMasUtilizado(const tPantalla pantalla, int fila)
{
    int arrayContadores[NUM_COLORES] = {0};     // { 0  ,   0   ,   0   ,   0   ,   0 } 

    for(int j = 0; j < NUM_COLUMNAS; j++){      
        tColor colorFondo = pantalla[fila][j].colorFondo;
        arrayContadores[colorFondo]++;         
    }
    
    // BUSQUEDA DEL MAXIMO VALOR DE UN ARRAY
    int indiceMaximo = 0;
    for(int i = 0; i < NUM_COLORES; i++){
        if(arrayContadores[i] > indiceMaximo){
            indiceMaximo = i;
        }
    }

    return (tColor)indiceMaximo;
}

void primerParpadeante(const tPantalla pantalla, int &fila, int &columna)
{
    // Devuelve los indices; -1 en fila y en columna si no lo hay
    // ESQUEMA DE BUSQUEDA
    bool encontrado = false;
    int indiceFila = 0, indiceColumna;
    
    while(indiceFila < NUM_FILAS && !encontrado){
        indiceColumna = 0;
        while(indiceColumna < NUM_COLUMNAS && !encontrado){
            if(pantalla[indiceFila][indiceColumna].parpadea == true){
                fila = indiceFila;
                columna = indiceColumna;
                encontrado = true;
            }else{
                indiceColumna++;
            }
        }
        indiceFila++;
    }

    if(!encontrado){
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

void borradoPantalla(tPantalla pantalla)
{
    for (int i = 0; i < NUM_FILAS; i++)
        for (int j = 0; j < NUM_COLUMNAS; j++)
        {
            tPixel pixel = {' ', negro, negro, false};
            pantalla[i][j] = pixel;
        }
}

void colocacionDatosPrueba(tPantalla pantalla)
{
    for (int i = 0; i < (NUM_COLUMNAS / 2 + 1); i++)
    {
        tPixel pixel = {' ', amarillo, verde, false};
        pantalla[0][i] = pixel;
    } // en la fila 0 ponemos 41 fondos verdes (con primer plano amarillo)

    pantalla[0][NUM_COLUMNAS - 1].parpadea = true; // el unico parpadeante es la esquina superior derecha
}