# C strings library

## Introducción
La librería ayuda al uso y parseo de strings de una forma más rápida de lo habitual. 
La principal diferencia es que aunque se sigue el estandar de finalizar todas las strings con un caracter nulo, se hace uso de los tamaños de estas por medio de contadores. De este modo el acceso a las diferentes partes de la string es inmediato.

Sin embargo para esta mejora en velocidad se requieren más llamadas a la funcion `malloc()` de lo habitual, ya que se hacen 2 reservas iniciales una para la estructura inicial y una segunda para la string de la que se obtendrán los datos. Sin embargo esto no implica que el incremento de llamadas a `malloc()` sea duplicado. Para evitar este problema las strings pueden generar una relación de dependencia entre ellas, de modo que el parametro `data` se verá compartido entre varias substrings pertenecientes al mismo padre.

Las strings se generan haciendo uso de un constructor `ctor()`. Este constructor recibe como parametro la dirección de memoria de la propia instancia de la estructura string, y un segundo parametro que incluye un `char *` que contiene los bytes de la string. Si el primer parámetro es nulo, o lo que es lo mismo, la referencia a la variable que alojará la string es nula; no se efectuara una reserva para la clase y la función saldrá automaticamente. En caso contrario se efectuara una reserva de memoria y se procedera a inicializar la estructura.

Si por el contrario el segundo parametro es nulo, el miembro `data` no poseera valor alguno y se inicializara con el valor `NULL`. En caso contrario, se realizara una reserva de memoria para la cadena de caracteres proporcionada y se guardara dicha dirección de memoria en el miembro `data`.

Todas las funciones que generan instancias de la estructura `t_string` poseen una réplica exacta de ellas precedidas por una "n". Por defecto las funciones que devuelven una instancia `t_string`, generan una dependencia entre la string padre y la nueva string generada. Esto se debe a que dichas funciones NO efectuan una reserva para el miembro `data`, si no que referencian dicho miembro con el del padre haciendo que ambos miembros guarden la misma dirección de memoria. Como las strings poseen más información sobre ellas como dónde empiezan y dónde terminan, las reservas iniciales de las variables de tipo `char *` alojadas en los miembros `data` pueden ser reutilizadas. Si el programador decide eliminar una string padre de la cual dependen otras strings, puede generar un comportameinto indefinido. Esto implica que el programador debe poner atención en eliminar un padre solo y solo si el resto de strings dependientes a el han sido ya eliminadas. 
Para evitar este tipo de preocupaciones, las funciones precedidas por una "n" (acrónimo de new) haran también una reserva y una copía del miembro "data" en la nueva instancia `t_string` una vez realizada la ejecución de cada función. Esto incrementa el numero de llamadas a `malloc()`

Además, todas las funciones que comienzen con el prefijo 'p_', dan soporte a recibir como segundo parámetro strings del tipo `char *`. Esto habilita la opción de utilizar strings definidas dentro del mismo código usando las comillas dobles.
Ejemplo:
```c
t_string palabras;

p_split(palabras, " ");
```