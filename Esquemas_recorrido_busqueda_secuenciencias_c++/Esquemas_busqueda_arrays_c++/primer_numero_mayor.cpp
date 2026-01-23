#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int MAX = 10;

typedef int tArray[MAX];

void generarAleatorios(tArray a);
void mostrarAleatorios(const tArray a);
int identificarPrimerNumeroMayor(const tArray a);

int main(){
    tArray array;
    int indice;

    generarAleatorios(array);
    mostrarAleatorios(array);
    indice = identificarPrimerNumeroMayor(array);
    if(indice = -1){
        cout << "No se ha logrado encontrar un numero mayor a 5";
    }else{
        cout << "Se ha logrado encontrar un numero mayor a 5 en la posicion: " << indice << endl;
    }

    return 0;    
}

void generarAleatorios(tArray a){
    srand(time(NULL));
    for(int i = 0; i < MAX; i++){
        a[i] = (1 + (rand()%((10 + 1) - 1)));
    }
}
void mostrarAleatorios(tArray a){
    for(int i = 0; i < MAX; i++){
        cout << " " << a[i] ;
    }
}
int identificarPrimerNumeroMayor(const tArray a){
    int indice = 0, numeroMayor = 0;

    bool encontrado = false;
    while(indice < MAX && !encontrado){
        if(a[indice] > 5){
            encontrado = true;
            numeroMayor = indice;
        }else{
            indice++;
        }
    }

    if(!encontrado){
        numeroMayor = -1;
    }

    return numeroMayor;
}



