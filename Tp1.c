/*
Realizar en Lenguaje C una función para realizar cada una de las operaciones
solicitadas, sin la utilización de funciones de biblioteca: 
a) Calcular y retornar la longitud de una cadena dada. 
b) Convertir una cadena de dígitos en su equivalente numérico. 
c) Convertir una cadena de caracteres a la misma cadena con todos sus caracteres en mayúscula.
d) Eliminar de una cadena dada todas las ocurrencias de un carácter dado. 
e) Concatenar al final de la primera cadena dada una segunda cadena también dada.
f) Modificar la cadena dada con la inserción de un carácter dado en una posición determinada.

Construir un programa para el testeo de las funciones del punto 1.
*/

#include <stdio.h>

int longitud(char palabra[]) {
  int contador = 0;
  char actual = palabra[0];
  while (actual != '\0') {
    contador++;
    actual = palabra[contador];
  }
  return contador;
}

char *amayuscula(char *mipalabra, int largo) {
  for (int i = 0; i < largo; i++) {
    if (mipalabra[i] >= 'a' && mipalabra[i] <= 'z') {
      mipalabra[i] = mipalabra[i] - 32;
    }
  }
  return mipalabra;
}

void eliminarOcurrenciasDeChar(char *cadena, char caracter, int largo) {
  for (int i = 0; i < largo - 1; i++) {
    if (cadena[i] == caracter) {
      for (int j = i; j < largo - 1; j++) {
        cadena[j] = cadena[j + 1];
      }
    }
  }
}

char *concatenar(char *destino, char *elOtro)
{
    int i=longitud(destino);
    int j=0;
    int contador=i+longitud(elOtro);
    while(i<=contador) {
        destino[i]=elOtro[j];
        i++;
        j++;
    }
}

char *clavar(char *palabra, char caracter, int posicion)
{
  int contador=longitud(palabra);
  if (contador<posicion)
    printf("La posicion indicada no esta disponible");
  else
  {
    palabra[posicion]=caracter;
  }
}
int main() {
  // a) Calcular y retornar la longitud de una cadena dada.
  int largopalabra;
  char *palabra = "Hola como te va";
  largopalabra = longitud(palabra);
  printf("El resultado es %d\n", largopalabra);

  // b) Convertir una cadena de dígitos en su equivalente numérico.

  /* Quizás conviene hacerlo con la palabra definida como char palabra[]? así:

  char micadenita[] = "Hola como te va\0";
  int longi = longitud(micadenita);

  for (int i = 0; i < longi; i++){
  char *punteropalabra = &micadenita[i];

  printf("'%s' tiene el valor %d\n", punteropalabra, *punteropalabra);
  }

*/

  for (int i = 0; i < largopalabra; i++) {
    char *punteropalabra = &palabra[i];

    printf("'%s' tiene el valor %d\n\n", punteropalabra, *punteropalabra);
  }

  // c) Convertir una cadena de caracteres a la misma cadena con todos sus
  // caracteres en mayúscula.

  char micadena[] = "estoy en mayus\n\n";
  // Le pase una cadena nueva porque con palabra se rompe. Creo que es por el
  // char* pero no termino de entender bien.

  char *estoyenmayus;

  estoyenmayus = amayuscula(micadena, longitud(micadena));

  printf("Hola, deberia estar en mayuscula: %s", estoyenmayus);

  // d) Eliminar de una cadena dada todas las ocurrencias de un caracter dado.

  char caracter = 'a';
  char micadena2[] = "me falta una letra \n";

  eliminarOcurrenciasDeChar(micadena2, caracter, longitud(micadena2));

  printf("Frase sin 'a': %s", micadena2);

  //e) Concatenar al final de la primera cadena dada una segunda cadena también dada.

  char segundaPalabra[50], primerPalabra[50];

  concatenar(segundaPalabra,  " y esta sera la segunda parte.");
  concatenar(primerPalabra, "Esta es la primera parte");

  concatenar(primerPalabra, segundaPalabra);

  printf("Palabra concatenada : %s\n", primerPalabra);

  //f) Modificar la cadena dada con la inserción de un carácter dado en una posición determinada.
  
  char palabraPrueba[]="La letra A deberia ser reemplazada por una o\n";
  char letra='o';

  clavar(palabraPrueba,letra,9);

  printf("%s", palabraPrueba);

  return 0;
}
