#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"

int main(int argc, char const *argv[]) {

  char palabra[30];
  char codigo_producto[strlen(palabra)];

  scanf("%[^\n]",palabra);
  printf("%s\n", palabra);

  //convertir cadena a minúsculas
  for(int i = 0; i < strlen(palabra); ++i){
      if(isupper(palabra[i])){
        palabra[i] = tolower(palabra[i]);
      }
  }

  // insertar el ascii de cada elemento de la cadena
  for(int i = 0; i < strlen(palabra); ++i){
    codigo_producto[i] = (char)palabra[i]%9;
    if((char)palabra[i]%9 == 0){
      codigo_producto[i] = 9;
    }
  }

  for(int i = 0; i < strlen(palabra); ++i){
    printf("%d", codigo_producto[i]);
  }

  double num = atoi(codigo_producto);

  printf("\nEl valor numerico es: %f\n", num);


  return 0;
}
