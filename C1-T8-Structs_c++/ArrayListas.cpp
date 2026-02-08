// Este ejercicio se trata de un Array de Listas de tamaño variable.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Variables Globales
const int MAX_CARRITOS = 10;    // Lista de tamaño variable
const int MAX_CAJAS = 5;        // Lista de tamaño fijo(array)

// Estructuras
typedef struct{
    double importe;
    string senior;
    string pago;
}tCarrito;

typedef tCarrito tListaCarritos[MAX_CARRITOS];

typedef struct{
    tListaCarritos caja;                            // Array de Carritos
    int contador;
}tCajas;                                            // Lista de tamaño variable de cajas

typedef tCajas tSupermercado[MAX_CAJAS];            // Array de cajas de tamaño fijo.

// Prototipos
void cargarCajas(ifstream& archivo,tSupermercado& listaDeCajas, bool& exito);
void mostrarCajas(tSupermercado arrayCajas);
void mostrarListaCarritos(tCajas arrayCarritos);
void mostrarUnCarrito(tCarrito carrito);

// Main
int main(){
    tSupermercado arrayCajas;
    tCajas listaCarritos;
    tCarrito carrito;


    bool exito = false;
    ifstream archivo;
    cargarCajas(archivo, arrayCajas ,exito);
    if(exito){
        cout << "Archivo abierto correctamente" << endl;
        mostrarCajas(arrayCajas);
    }else{
        cout << "No se pudo abrir el archivo correctamente" << endl;
    }
    
    archivo.close();
    return 0;
}

void cargarCajas(ifstream& archivo,tSupermercado& listaDeCajas, bool& exito){
    archivo.open("supermercado.txt");
    if(!archivo.is_open()){
        exito = false;
    }else{
        exito = true;
        int i;                             // Indice de Cajas
        for(i = 0; i < MAX_CAJAS; i++){
            int j = 0;
            listaDeCajas[i].contador = 0;      // Contador de Carritos por caja
            archivo >> listaDeCajas[i].caja[j].importe;
            while(listaDeCajas[i].caja[j].importe != -1 && listaDeCajas[i].contador < MAX_CARRITOS){
                archivo >> listaDeCajas[i].caja[j].senior;
                archivo >> listaDeCajas[i].caja[j].pago;
                j++;
                listaDeCajas[i].contador++;
                archivo >> listaDeCajas[i].caja[j].importe;
            }
        }
    }
}

void mostrarCajas(tSupermercado arrayCajas){
    for(int i = 0; i < MAX_CAJAS; i++){    
        cout << "Caja " << i + 1 << endl;
        mostrarListaCarritos(arrayCajas[i]);
    }
}

void mostrarListaCarritos(tCajas arrayCarritos){
    for(int i = 0; i < arrayCarritos.contador; i++){
        mostrarUnCarrito(arrayCarritos.caja[i]);
    }
}


void mostrarUnCarrito(tCarrito carrito){
    cout << "Importe: " << carrito.importe << "  Senior o No senior: " << carrito.senior << "  Pago: " << carrito.pago << endl;
}

