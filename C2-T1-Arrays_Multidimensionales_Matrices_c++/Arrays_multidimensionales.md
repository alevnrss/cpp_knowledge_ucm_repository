Array multidimensional - Matrices:

Declarar un array de tipo multidimensional
typedef tipo_dato tNombreArray[dimension1][dimension2]...[dimensionN]

Para arrays bidimensionales (matrices)
    dimension1 : Filas.
    dimension2 : Columnas.

Declarar variable de tipo array multidimensiona
tNombreArray variable;

Acceso a elementos del array multidimensional
nombreVariable[indice1][indice2]...[indiceN]

Ejemplo de inicializacion de matriz:
typedef int tMatriz[5][2];
tMatriz a = { 1,1, 2,4, 4,5, ....}

Cada valor rellena tanto las columas como las filas segun la dimesion del array multidimensional 

------
Recorrido de array bidimensional(matriz)
    - Primero nos pondremos en cada una de las filas. (i)
        - Para cada fila recorremos las columnas. (j)



const int FILAS = 10;
const int COLUMNAS = 5;
typedef double tMatriz[FILAS][COLUMNAS];
tMatriz matriz;

for(int fila = 0; fila < FILAS; fila++){
    for(int columna = 0; columna < COLUMNAS; columna++){
        // procesar celda. Para cada fila se hace el bucle segun la cantidad de columnas. Fila 0, se itera unas 5 veces. Fila 1, se itera unas 5 veces.
    }
}

for(int fila = 0; fila < FILAS; fila++){
    for(int columna = 0; columna < COLUMNAS; columna++){
        cout << matriz[fila][columna] << ' ' ;
    }
    cout << endl;
}

Si tuviera un cubo, al tener tres vectores x, y , z entonces utilizara la cantidad de 3 bucles.

---------
Esquema de busqueda de array bidimensional(matriz)






