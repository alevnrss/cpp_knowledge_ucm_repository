#include <iostream>
using namespace std;

// Variables globales
const int NUMERO_FILAS = 1;
const int NUMEROS_COLUMNAS = 1;

// Estructuras
typedef enum {negro, azul, verde, amarillo, rojo} tColor;
typedef struct{
    char caracter;
    tColor color, colorFondo;
    bool parpadea;
} tPixel;

typedef tPixel tPantalla[NUMERO_FILAS][NUMEROS_COLUMNAS];


// Prototipos
void rellenarMatriz(tPantalla pantalla);
bool parpadeando();
void mostrarMatriz(const tPantalla m1);
void informacionCeldas(const tPixel pixel);
string toString(tColor color);
string toStringParpadea(bool parpadea);

int main(){
    tPantalla pantalla;
    rellenarMatriz(pantalla);
    mostrarMatriz(pantalla);

    return 0;
}
void rellenarMatriz(tPantalla pantalla){
    int colorCaracter, colorFondo;

    for(int i = 0; i < NUMERO_FILAS; i++){
        cout << "FILA: " << i << endl;
        for(int j = 0; j < NUMEROS_COLUMNAS; j++){
            cout << "COLUMNA : " << j << endl; 
            cout << "Caracter: ";
            cin >> pantalla[i][j].caracter;
            cout << "ColorCaracter (0: Negro, 1: Azul, 2: Verde, 3: Amarillo, 4: Rojo): ";
            cin >> colorCaracter;
            pantalla[i][j].color = tColor(colorCaracter);
            cout << "ColorFondo (0: Negro, 1: Azul, 2: Verde, 3: Amarillo, 4: Rojo): ";
            cin >> colorFondo;
            pantalla[i][j].colorFondo = tColor(colorFondo);
            pantalla[i][j].parpadea = parpadeando();
        }
    }
};

bool parpadeando(){
    int opcion;
    bool parpadeando;
    cout << "Parpadeando? | (1: Si , 0: No) ";
    cin >> opcion;
    if(opcion == 0){
        parpadeando = true;
    }else{
        parpadeando = false;
    }
    return parpadeando;
}
void mostrarMatriz(const tPantalla m1){
    for(int i = 0; i < NUMERO_FILAS; i++){
        for(int j = 0; j < NUMEROS_COLUMNAS; j++){
            informacionCeldas(m1[i][j]);
        }
        cout << endl;
    }
}

string toString(tColor color) {
    string cadena = "Error/Desconocido"; 

    switch(color) {
        case negro:    cadena = "Negro";    break;
        case azul:     cadena = "Azul";     break;
        case verde:    cadena = "Verde";    break;
        case amarillo: cadena = "Amarillo"; break;
        case rojo:     cadena = "Rojo";     break;
    }
    return cadena;
}
void informacionCeldas(const tPixel pixel){
    cout << pixel.caracter << endl;
    cout << "Color Caracter: " <<  toString(pixel.color) << endl; 
    cout << "Color Fondo: " << toString(pixel.colorFondo) << endl;
    cout << toStringParpadea(pixel.parpadea) << endl;
}



string toStringParpadea(bool parpadea){
    string cadena;
    if(parpadea == 0){
        cadena = "No parpadea";
    }else if(parpadea == 1){  
        cadena = "Parpadea";
    }else{
        cadena = "Caracter introducido invalido"; 
    }
}
