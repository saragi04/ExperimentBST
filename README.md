# EXPERIMENTO DE INSERCIÓN ALEATORIA

### PLANTEAMIENTO DEL PROBLEMA

En un vector, insertar ordenadamente un total de 100 animales diferentes, para posteriormente insertar en un árbol de búsqueda binaria cada uno de esos animales. Se debe generar un número aleatorio entre 0 y el número de elementos que contenga el vector menos uno (en este caso 100-1=99) para determinar la posición del animal que se insertará en el árbol. En el momento que se inserta el elemento (animal) en el árbol, se elimina al mismo del vector, este proceso se repite hasta que el vector quede completamente vacío y por otro lado, el árbol quede con un tamaño de 100 nodos. 

### OBJETIVOS

- Analizar el comportamiento del árbol de búsqueda binario frente a la inserción aleatoria de elementos.
- Obtener conclusiones referentes a las carácterísticas del árbol como lo son el número de hojas, altura, balanceo.

### MÉTODO DE SOLUCIÓN

Primeramente se implementaron las estructuras de datos que se debían utilizar para realizar el experimento que serían el árbol de búsqueda binaria y el vector para almacenar los datos inicialmente. Después de esto procedemos a la búsqueda por medio de la IA de los 100 animales que se debían incluir en el vector, se ubicaron en un archivo csv para poder ingresarlos al vector por medio de operaciones con archivos en C++.

Después de que estos se ingresaran, se utilizó el método de ordenamiento implementado en la estructura de datos "Vector", el cual funciona específicamente con el método quickSort, esto para tener los elementos ordenados en el vector como se pedía inicialmente en experimento. 

Con estos elementos ya ubicados en el vector, procedemos a insertarlos en el árbol de búsqueda binaria por medio de una selección aleatoria implementada con ayuda de la librería "random" originaria de C++ y al mismo tiempo, se iban eliminando del vector en el que se encontraban.

Después de que todos los elementos se hayan insertado en el árbol y el vector haya quedado vacío, continuamos con el análisis de datos obtenidos. Para esto nos ayudamos de un bucle for para así realizar 1000 veces el mismo proceso, para cada una de las iteraciones, el programa nos muestra para cada uno de los árboles creados el número de hojas que tienen, el número de niveles o su altura y  el número de nodos a la derecha e izquierda de la raíz del árbol. Con esto, pudimos obtener: 

- Promedio de hojas: 34
- Promedio de niveles: 13 
- Promedio de nodos al lado derecho: 52
- Promedio de nodos al lado izquierdo: 47

### CÓDIGO

- Código de la estrucura vector: ["Vector.hh"](https://github.com/saragi04/ExperimentBST/blob/5c85673974b24f36839f3ca6f9a1d1f752a065b6/src/vector.hh)

- Código de la estrucutar "bst.hh": ["bst.hh"](https://github.com/saragi04/ExperimentBST/blob/5c85673974b24f36839f3ca6f9a1d1f752a065b6/src/bst.hh)

- Código principal del experimento: ["experiment.cpp"](https://github.com/saragi04/ExperimentBST/blob/5c85673974b24f36839f3ca6f9a1d1f752a065b6/src/experiment.cpp)

### CONCLUSIONES 

- *ALTURA DEL ÁRBOL:* Sabemos que la áltura teóricamente esperada de un árbol se puede definir a base del logaritmo base 2 del número de nodos que presenta el mismo árbol, si lo hacemos con la cantidad que manejabamos esta vez, obteníamos que la altura "perfecta" la podíamos encontrar entre 7 y 8 niveles, mientras que en el promedio de niveles que se obtuvo en el experimento, fue de 13, lo que claramente implica que el árbol se encuentre desbalanceado y con menos hojas de las esperadas según la teoría de un árbol balanceado.

- *CANTIDAD DE HOJAS:* Como bien se hizo mención en el punto anterior, en el promedio de las hojas de los árboles obtenidos en el experimento fue un 30% menos que las esperadas, teniendo en cuenta que en un árbol balanceado, la cantidad de hojas corresponde a la mitad de la cantidad de elementos que se encuentren en el árbol. 

- *DESBALANCE:* A pesar de que en el promedio de la cantidad de nodos tanto a la izquierda como a la derecha parece estar bien distribuida, si lograbamos diferenciar en cada árbol especificamente, obteníamos de que existía una gran diferencia entre esta cantidad de nodos, en los peores casos se obtuvo: derecha 13, 80; izquierda 86, 19, respectivamente. Con esto, lo que podemos esperar es una ineficiencia en las operaciones del árbol. 

Dichas estas 3 conclusiones, podemos determinar de que la inserción aleatoria de elementos en un árbol de búsqueda binaria simplemente nos lleva a la ineficiencia del mismo, es básicamente desaprovechar la potencia en cuanto velocidad de búsqueda que estos árboles presentan, sin dejar a un lado la característica que poseen de inserción eficiente también.
