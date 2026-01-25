

Los strings tambien conocidos como cadena de caracteres, se tratan de una coleccion homogenea de elementos.
Esto quiere decir que se parece a los arrays, como una coleccion de elementos del mismo tipo, en este caso, 
el string se trata de una COLECCION DE ELEMENTOS DE TIPO CHAR.

Al ser una coleccion homogenea todos sus elementos son de tipo char. Esto permite que su acceso a dichos caracteres
sea extremadamente rapido mediante un indice.


Acceso a elementos de una cadena de caracteres.

Para acceder a los elementos, lo haremos de la misma manera que un array.

```cpp
string cadena = "Hola Alejandro";

cadena[1];      // Estamos accediendo al elemento en la posicion 1.
cadena.at(2);   // Estamos accediendo al elemento en la posicion 2. 

```