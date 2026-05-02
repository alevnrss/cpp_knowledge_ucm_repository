Declarar un puntero
tipo *variable;     ->      int *txPtr; 
Significado de la sintaxis: "Reserva un espacio en memoria para un puntero que apuntara a la direccion de una variable de tipo de dato entero".

2. Inicializar puntero
    2.1 Sin valor al que apuntar:       puntero = nullptr;  ->  tXPtr = nullptr;

    2.2 Asignar una direccion de memoria al que apuntar:    puntero = &variable;    ->     tXPtr = &a;

3. Funcionalidades de los operadores: Ampersand (&) y Asterisco (*)
Para manejar punteros utilizaremos estos operadores:

El ampersand [&] es un operador que sirve para obtener la dirección de memoria de cualquier variable, sea puntero o variable normal.    

El asterisco [*] es un operador que sirve para obtener el valor que se encuentra en la dirección de memoria al que se apunta. Este operador se utiliza para dos acciones:
    -  `Inicializar o crear puntero`:               int *tVarPtr;
    -  `Acceder al valor de la direccion (Acceso indirecto)`:         cout << *tVarPtr;

4. Ejemplos del uso de asterisco [*]

    ```cpp
        int *tAPtr, *tBPtr, x, y;
        x = 10, y = 20;

        tAPtr = &x;
        tBPtr = &y;

        cout << tAPtr << endl;  // Direccion de memoria de x.
        cout << tBPtr << endl;  // Direccion de memoria de y.
        cout << *tAPtr << endl; // Valor de x.
        cout << *tBPtr << endl; // Valor de y.
               




    ```