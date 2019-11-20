#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"

char enteroacaracter(int numero);

int main(int argc, char const *argv[]) {

  int acumulado = 0;
  char palabra[30], parte2[8];
  char codigo_producto[strlen(palabra)];

  scanf("%[^\n]",palabra);
  printf("La palabra ingresada es: %s\n", palabra);

  //convertir cadena a minúsculas
  for(int i = 0; i < strlen(palabra); ++i){
      if(isupper(palabra[i])){
        palabra[i] = tolower(palabra[i]);
      }
  }

  // Obtener el mod9 de la suma de los ascii
  for(int i = 0; i < strlen(palabra); ++i){
    acumulado += palabra[i];
  }

  // Convertir la primera parte de entero a caracter
  	char *parte1 = malloc(4 * sizeof(char));
  	sprintf(parte1, "%d", acumulado);
          free(parte1);


  // Convertir la segunda parte de entero a caracter
  int valor = 0;
  char comocaracter;

  for(int i = 0; i < 8; i++){

    valor = palabra[i] % 9;
    comocaracter = enteroacaracter(valor);
    parte2[i] = comocaracter;

    printf("%d %c\n", valor, parte2[i]);

  }


  printf("El entero acumulado es: %d\n", acumulado);
  printf("La cadena del entero acumulado es: %s\n", parte1);
  printf("El entero de la segunda parte es: %s\n", parte2);

  //strcat(cadenacestino,cadenaorigen)
  strcat(parte1,parte2);

  printf("La cadena resultante es %s\n", parte1);

  return 0;
}

char enteroacaracter(int numero){
  return numero + '0';
}
