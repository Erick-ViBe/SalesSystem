#include "stdio.h"
#include "string.h"
#include "ctype.h"

int main(int argc, char const *argv[]) {

  char palabra[] = "agua embotellada 123";
  char cifrada[strlen(palabra)];

  printf("%s\n", palabra);

  //convertir cadena a minúsculas
  for(int i = 0; i < strlen(palabra); ++i){
      if(isupper(palabra[i])){
        palabra[i] = tolower(palabra[i]);
      }
  }

  // insertar el ascii de cada elemento de la cadena
  for(int i = 0; i < strlen(palabra); ++i){
    cifrada[i] = (char)palabra[i]%9;
  }

  for(int i = 0; i < strlen(palabra); ++i){
    printf("%d", cifrada[i]);
  }


  return 0;
}
