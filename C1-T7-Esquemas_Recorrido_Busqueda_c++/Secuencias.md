# SECUENCIAS, TIPOS DE SECUENCIAS Y FINAL DE UNA SECUENCIA.

### ¿Qué es una secuencia?.

Conocemos como **_Secuencia_** a una sucesion de elementos de un mismo tipo a los que dichos elementos se acceden linealmente.

### Tipos de secuencias. 

Las secuencias pueden ser de **3 tipos diferentes**:
1. ***SECUENCIAS EXPLICITAS*** -> teclado, archivo.
2. ***SECUENCIAS CALCULADAS*** -> formulas de recurrencia. Recursividad 
3. ***SECUENCIAS TIPO DATO ESTRUCTURADO(LISTAS)*** -> Arrays unidimensionales o multidimensionales, structs, etc...

### Final de una secuencia.

Es importante identificar cual es el final de una secuencia, pues nos servirá para poder utilizar los famosos algoritmos de `Recorrido y Busqueda`.

1. ***Deteccion del final de la secuencia explicita de tipo ARCHIVO.TXT***
Para detectar el final de la secuencia de un archivo habra dos opciones. 
    - Detectar la marca del final del archivo `(EOF)`.
    - Detectar un valor `centinela` final.

2. ***Deteccion del final de la secuencia explicita de tipo TECLADO***
Para detectar el final de la secuencia de datos leidos por teclado habra dos opciones
    - Preguntar al usuario si quiere introducir un dato nuevo.
    - Preguntar al principio cuantos datos va a introducir.
    - Detectar un valor `centinela` final.


Para los diferentes tipos de secuencias, existe dos tipos de esquema de tratarmiento de secuencias:
Los esquemas de recorrido y busqueda de secuencias.

Los esquemas de recorrido realiza un mismo tratamiento a todos los elementos de la secuencia.
Ejemplos: Mostrar los elementos de una secuencia, sumar todos los numeros de una secuencia, par o impar cada numero de una secuencia.
Este esquema siempre termina al llegar al final de la secuencia (segun el tipo y que deteccion)

Los esquemas de busqueda tratan de recorrer la secuencia hasta encontrar el elemento buscado. 
Ejemplos: Localizar el primer numero mayor a algo.
Este esquema siempre termina al localizar el primer elemento que cumpla la condicion(si se ha encontrado) o al llegar al final de la secuencia

---------
Esquema de recorrido:
    Inicializacion (Obtener el primer elemento de la secuencia) 
    Mientras no llegue al final de la secuencia
        Obtener el siguiente elementos 
        Procesar elementos
    Finalizacion.

Si no sabemos cuantos elementos hay no podemos utilizar el for, entonces daremos uso al bucle while.



