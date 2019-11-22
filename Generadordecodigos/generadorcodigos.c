#include "generadorcodigos.h"

char enteroacaracter(int numero){
  return numero + '0';
}

int obtenercodigo(char *palabra){

  int acumulado = 0, num = 0;
  char parte2[8];

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
          //free(parte1); //eliminsndo esta línea el error desaparece


  // Convertir la segunda parte de entero a caracter
  int valor;
  char convertido;

  int i = 0;
  for(i = 0; i < strlen(palabra) && i < 5; i++){

    valor = palabra[i] % 9;
    if(valor == 0){
      valor = 9;
    }
    convertido = enteroacaracter(valor);
    parte2[i] = convertido;
  }

  parte2[i] = '\0';

  //printf("La primera parte de la cadena es: %s\n", parte1);
  //printf("La segunda parte de la cadena es: %s\n", parte2);

  //strcat(cadenacestino,cadenaorigen)
  strcat(parte1, parte2);
  num = atoi(parte1);
  int multiplicador;
  // printf("El codigo antes de agregar ceros es: %d\n", num);
  // printf("El largo de cadena es: %lu\n", strlen(parte1) );
  // printf("El restante es: %lu\n", (9 - strlen(parte1)) );

  if(strlen(parte1) < 10){
    multiplicador = pow(10, (9 - strlen(parte1)));
    num *= multiplicador;
  }
    //printf("multiplicador = %d\n", multiplicador);


  return num;
}
