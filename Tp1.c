/*
Realizar en Lenguaje C una función para realizar cada una de las operaciones solicitadas, sin la utilización de funciones de biblioteca: 
a) Calcular y retornar la longitud de una cadena dada. 
b) Convertir una cadena de dígitos en su equivalente numérico. 
c) Convertir una cadena de caracteres a la misma cadena con todos sus caracteres en mayúscula. 
d) Eliminar de una cadena dada todas las ocurrencias de un carácter dado. 
e) Concatenar al final de la primera cadena dada una segunda cadena también dada. 
f) Modificar la cadena dada con la inserción de un carácter dado en una posición determinada.

Construir un programa para el testeo de las funciones del punto 1.
*/


#include <stdio.h>

int longitud(char palabra[])
{
    int contador=0;
    char actual = palabra[0];
    while (actual != '\0')
    {
        contador++;
        actual= palabra[contador];
    }
    return contador;
}

char *amayuscula(char *mipalabra, int largo)
{
    char *punteromayus;
        
    for (int i = 0; i < largo; i++){
    char *punteroamayus = &mipalabra[i];

    if (*punteroamayus < 41 && *punteroamayus > 90)
    {
        *punteroamayus = *punteroamayus-32;
    }
    return punteroamayus;
    }
}


int main()
{
    // a) Calcular y retornar la longitud de una cadena dada. 
    int largopalabra;
    char *palabra = "Hola como te va";
    largopalabra = longitud(palabra);
    printf("El resultado es %d\n",largopalabra);
  
    // b) Convertir una cadena de dígitos en su equivalente numérico. 

    /* Quizás conviene hacerlo con la palabra definida como char palabra[]? así:

    char micadenita[] = "Hola como te va\0";
    int longi = longitud(micadenita);

    for (int i = 0; i < longi; i++){
    char *punteropalabra = &micadenita[i];

    printf("'%s' tiene el valor %d\n", punteropalabra, *punteropalabra);
    }
*/

    for (int i = 0; i < largopalabra; i++)
    {
    char *punteropalabra = &palabra[i];

    printf("'%s' tiene el valor %d\n", punteropalabra, *punteropalabra);
    }

    // c) Convertir una cadena de caracteres a la misma cadena con todos sus caracteres en mayúscula. 

    char *estoyenmayus;
    estoyenmayus = amayuscula(palabra, largopalabra);
    printf("\n Hola, deberia estar en mayuscula: %s", estoyenmayus);

  return 0;
}
