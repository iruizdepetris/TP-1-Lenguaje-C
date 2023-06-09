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

//funciones punto b
int numeroEquivalente (char caracter[]){

    int numerosEqv[longitud(caracter)];
    int numeroFinal = 0;

    for(int i = 0; i<longitud(caracter); i++){
        if(caracter[i] >= 48 && caracter[i]<=57){
            numerosEqv[i] = caracter[i] - '0';
        }else{
            numerosEqv[i] = 0;
        }
    }
    for(int i = 1; i<=longitud(caracter); i++){
        numeroFinal+=(potencia(10, longitud(caracter)-i)*numerosEqv[i-1]);
    }
    return numeroFinal;
}
//funcion potencia sirve para la funcion numeroEquivalente
int potencia(int numero, int veces){
    if(veces == 0){
        return 1;
    }else{
        return numero*potencia(numero, veces-1);
    }
}
//fin funciones punto b

void convertirAMayusculas(char* cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - 'a' + 'A';
        }
        i++;
    }
}

void eliminarOcurrenciasDeChar(char *cadena, char caracter) {
int largo=longitud(cadena);
  for (int i = 0; i < largo - 1; i++) {
    if (cadena[i] == caracter) {
      for (int j = i; j < largo - 1; j++) {
        cadena[j] = cadena[j + 1];
      }
    }
  }
}

void concatenar(char *destino, char *elOtro)
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

void insertarCaracter(char* cadena, char caracter, int posicion) {
    int longitud = calcularLongitud(cadena);
    int i;
    for (i = longitud; i >= posicion; i--) {
        cadena[i + 1] = cadena[i];
    }
    cadena[posicion] = caracter;
}

int main() {
  // a) Calcular y retornar la longitud de una cadena dada.
  int largopalabra;
  char *palabra = "Hola como te va";
  largopalabra = longitud(palabra);
  printf("El resultado es %d\n", largopalabra);

  // b) Convertir una cadena de dígitos en su equivalente numérico.
  char cadenaDigitos[] = "2023";
  printf("El numero de la cadena %s es: %d ", cadenaDigitos, numeroEquivalente(cadenaDigitos));


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

  convertirAMayusculas(micadena);

  printf("Hola, deberia estar en mayuscula: %s", micadena);

  // d) Eliminar de una cadena dada todas las ocurrencias de un caracter dado.

  char caracter = 'a';
  char micadena2[] = "me falta una letra \n";

  eliminarOcurrenciasDeChar(micadena2, caracter);

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

  insertarCaracter(palabraPrueba,letra,9);

  printf("%s", palabraPrueba);

  return 0;
}
