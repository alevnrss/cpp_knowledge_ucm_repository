#include <iostream>
#include <string>    // Libreria string -> importante para el uso de las siguientes funciones
using namespace std;

void accesoACaracteres();
void operacionesBasicas();

int main(){
    
    // ACCESO A CARACTERES
    accesoACaracteres();

    // OPERACIONES BASICAS CON CADENAS
    operacionesBasicas();

    

}

void accesoACaracteres(){
    
    // Acceso a caracteres mediante indice. 
    
    string cadena = "Hola Alex";        // En total se usa 9 caracteres contando el espacio.
    cout << cadena[0] << endl;          // Acceso a la primera letra.
    cout << cadena[8] << endl;          // Acceso a la ultima letra.
    cout << cadena[9] << endl;          // Error de ejecucion. NO RECOMENDADO.
    // cout << cadena.at(9) << endl;       // Error de ejecucion. RECOMENDADO.

    // Acceso a caracteres mediante esquema de recorrido tipo array.

    for(int i = 0; i < cadena.size(); i++){     // Tambien se puede utilizar el .length()
        cout << cadena[i] << endl;
    }
    cout << endl;
}

void operacionesBasicas(){
    
    // FUNCION substr(posicion_inicial, longitud);
    string cadena1 = "abcdefg";
    cout << cadena1.substr(2,3);    // cde

    cout << endl;

    // FUNCION erase(posicion_inicial, longitud);
    string cadenaErase = "abcdef";
    cout << cadenaErase.erase(0,1) << endl; // Borrara desde la posicion 0 una longitud de 1 caracter -> bcdef 

    cout << endl;

    // FUNCION insert(posicion_inicial, cadenaInsertar);
    string cadenaInicial = "abcdef";
    string cadenaInsertar = "123";
    cout << cadenaInicial.insert(2, cadenaInsertar) << endl; // Inserta desde la posicion 2 -> ab123cdef  

    cout << endl;

    // FUNCION find(subcadena_A_Buscar);
    string cadena2 = "Ola";
    cout << cadena2.find("i") << endl;          // Numero -1 en sistema de 64 bits
    
    if(cadena2.find("a") != -1){
        cout << "Se ha encontrado" << endl;     // Si lo encuentra, devolvera la posicion inicial
        cout << "Indice: " << cadena2.find("a") << endl;
    }else{
        cout << "No se ha encontrado" << endl;
    }

    // FUNCION rfind(subcadena_A_Buscar);
    string cadena3 = "Olalalailailili";         // Ultima ocurrencia de i en la posicion 14
    cout << cadena3.rfind("i") << endl;         // Devuelve la ultima ocurrencia(ultima vez que aparece).
}






