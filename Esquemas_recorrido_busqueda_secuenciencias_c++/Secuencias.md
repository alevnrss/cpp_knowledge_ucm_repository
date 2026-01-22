Secuencia es una sucesion de elementos de un mismo tipo que se acceden linealmente
Esto suena mucho a array, pues el array se trata de una sucesion o secuencia de elementos
del mismo tipo y que se acceden linealmente a traves de un indice comun.

En las secuencias siempre hay un ultimo elemento.

Las secuencias pueden ser:
secuencias explicitas -> teclado, archivo.
secuencias calculadas -> formulas de recurrencia 
secuencias tipo listas -> arrays, structs.

En las secuencias explicitas manejaremos los datos leidos por teclado o leidos de un archivo.
Y siempre con un elemento especial al final de la secuencia que seria el centinela.

-- Deteccion del final de la secuencia explicita de archivo.
Para detectar el final de la secuencia de un archivo habra dos opciones. 
    - Detectar la marca del final del archivo (EOF)
    - Detectar un valor centinela final

-- Deteccion del final de la secuencia explicita de teclado
Para detectar el final de la secuencia de datos leidos por teclado habra dos opciones
    - Preguntar al usuario si quiere introducir un dato nuevo
    - Preguntar al principio cuantos datos va a introducir
    - Detectar un valor centinela final


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



