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



int main()
{
    int x;
    char *palabra = "Hola como te va";
    x = longitud(palabra);
    printf("El resultado es %d",x);
    return 0;
}