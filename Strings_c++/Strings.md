# STRINGS (LISTAS/COLECCIONES HOMOGÉNEAS DE CARACTERES). LIBRERIA `#include <string>`.

Los `strings` tambien conocidos como `cadena de caracteres`, se tratan de una **coleccion homogenea de elementos de tipo char**.
Esto quiere decir que se parece a los *arrays*, como una coleccion de elementos del mismo tipo donde se acceden de **manera lineal**.

Al ser una coleccion homogenea, esto permite que su acceso a dichos caracteres sea extremadamente rapido mediante un `indice`.

## ACCESO A ELEMENTOS DE UNA CADENA DE CARACTERES.

Para acceder a los elementos, lo haremos de la misma manera que un array.
Para ello existen dos formas posibles, mediante corchetes `[]` ó mediante la función `.at(posicion)`.  

```cpp
string cadena = "Hola Alejandro";

cadena[1];      // Estamos accediendo al elemento en la posicion 1.
cadena.at(2);   // Estamos accediendo al elemento en la posicion 2. 

```

Pero, ***¿qué pasaría si accedo por error a una posicion inexistente?.***

Para ello esta la gran diferencia entre utilizar corchetes o la funcion at. Para evitar que nuesto programa dé como salida valores basura, **siempre utilizaremos la funcion `.at()`.** 
Esta función lo que hace es *comprobar siempre que exista el elemento y la posicion que le pasamos como parametro.* 
**Si no existe entonces la terminal nos dara un aviso y detendrá el programa.**   

## LONGITUD O TAMAÑO DE UN STRING. ESQUEMAS DE RECORRIDO Y BÚSQUEDA EN UN TIPO DE DATO STRING.

Los ***esquemas de recorrido y busqueda*** se basan en *algoritmos* ideales para utilizarlos en secuencias explicitas, calculadas o listas(mencionado en anteriores temas).
Como bien mencionamos al inicio, el string se trata de una secuencia o coleccion homogenea de caracteres de tipo char. 
Es decir que se trata de una **lista de elementos tipo char**, lo que significa que podremos utilizar en ella los esquemas de recorrido y busqueda.

Para recorrer un string, lo ideal siempre es saber cual es su `tamaño total (longitud)`.
Es por eso que utilizaremos dos funciones que serviran para obtener su tamaño:

1. `Función .length()`.
2. `Función .size()`. 
 
Ambas se utilizan para saber cual es el tamaño o longitud de nuestra cadena de caracteres.

***(ESQUEMA DE RECORRIDO)***
Para recorrer nuestra coleccion de caracteres, utilizaremos el `bucle for()` de la siguiente manera:

```cpp

string cadena = "alejandro";
for(int i = 0; i < cadena.length(); i++ ){
    cout << cadena.at(i) << " ";
}

```

***(ESQUEMA DE BÚSQUEDA)***
Para buscar un caracter dentro de nuestra coleccion, utilizaremos el `bucle while()` de la siguiente manera:

```cpp

string cadena = "hola alejandro";
int indice = 0;
bool encontrado = false;
while(indice < cadena.length() && !encontrado){
    if(cadena.at(indice) == 'j'){
        encontrado = true;
    }else{
        indice++;    
    }
}

if(!encontrado){
    indice = -1;
}

return indice;

```

## FUNCIONES BÁSICAS DE MANEJO DE STRINGS.

Ya hemos visto que existen diferentes funciones para saber informacion sobre nuestro tipo de dato String. Sin embargo, no solo tenemos ese tipo de funciones, sino que tenemos muchas otras que nos serviran para poder trabajar con ellos de manera que nos facilitara su acceso y su implementacion al código.

### FUNCIONES CON PARAMETROS -> INDICE INICIAL, LONGITUD O CADENA.

***1.1 FUNCION PARA EXTRAER UNA CADENA NUEVA. [`substr(indiceInicial, Longitud)`]***

Esta funcion lo que hace es pedirnos un ***indice inicial y una longitud de accion***.
1. El indice inicial sirve para decirle en que posicion del string queremos empezar a extraer.
2. La longitud indica cuantas posiciones, *contando desde la inicial* queremos extraer.

```cpp

string cadena = "abcdefg";
string extraccion;
extraccion = cadena.substr(0,3);     // Extraemos desde la a hasta la c. -> abc 

cout << extraccion;

```

***1.2 FUNCION PARA BORRAR PARTE DE UNA CADENA. [`erase(indiceInicial, Longitud)`]***

Esta funcion lo que hace es pedirnos un ***indice inicial y una longitud de accion***.
1. El indice inicial sirve para decirle en que posicion del string queremos empezar a borrar.
2. La longitud indica cuantas posiciones, *contando desde la inicial* queremos borrar.

```cpp

string cadena = "abcdefg";
string eraseString;
eraseString = cadena.erase(0,3);     // Borramos desde la posicion 0 a 3 caracteres (abc) -> defg
eraseString = cadena.erase(0,1);     // Borramos desde la posicion 0 a 1 caracter (a) -> bcdefg

cout << eraseString;

```

***1.3 FUNCION PARA INSERTAR UNA CADENA DENTRO OTRA CADENA. [`insert(indiceInicial, cadena)`]***

Esta funcion lo que hace es pedirnos un ***indice inicial y una longitud de accion***.
1. El indice inicial sirve para decirle en que posicion del string queremos insertar.
2. La subcadena es la cadena que queremos insertar en dicha posicion.

```cpp

string cadena = "abcdefg";
string subcadena = "123";
eraseString = cadena.insert(1, subcadena);     // Insertamos desde la posicion 1 desde b hacia adelante -> ab123cdefg

```

***1.4 FUNCION PARA ENCONTRAR UN CARACTER O CADENA DENTRO DE OTRA CADENA (DESDE 0 A INFINITO). [`find(cadenaABuscar)`]***

Esta funcion lo que hace es pedirnos una cadenaABuscar. Esta buscara la cadena o caracter desde la `posicion (0) hasta al final (infinito).`

1. Segun si la encuentra o no, nos dara dos opciones:
    - Si la encuentra nos dara la posicion de la primera letra de nuestra cadena a buscar. 
    - Si no la encuentra nos dara por salida un `-1` en *numero de 64 bits.*

> La salida cuando no lo encuentra `(-1)` es importante, ya que puede ser util si lo que buscamos es un tipo de nombre o
> caracter en especifico. 

```cpp

string cadena = "abcdefg";
cadena.find("ef");              // Salida = 4; el primer "ef" se encuentra en la posicion 4.
cadena.find("i");               // Salida -1; no se encontrara nunca la i   

```

***1.5 FUNCION PARA ENCONTRAR UN CARACTER O CADENA DENTRO DE OTRA CADENA (DESDE INFINITO A 0). [`rfind(cadenaABuscar)`]***

Esta funcion lo que hace es pedirnos una cadenaABuscar. Esta buscara la cadena o caracter al revés, desde `la posicion mas lejana (infinito) hasta al inicio (0).`

1. Segun si la encuentra o no, nos dara dos opciones:
    - Si la encuentra nos dara la posicion de la primera letra de nuestra cadena a buscar. 
    - Si no la encuentra nos dara por salida un `-1` en numero de 64 bits.

> La salida cuando no lo encuentra `(-1)` es importante, ya que puede ser util si lo que buscamos es un tipo de nombre o
> caracter en especifico. 

```cpp

string cadena = "abcdefgef";
cadena.rfind("ef");              // Salida = ; el primer "ef" se encuentra en la posicion 7 .
cadena.rfind("i");               // Salida -1; no se encontrara nunca la i   

```



