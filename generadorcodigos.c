#include "stdio.h"
#include "string.h"
#include "ctype.h"

int main(int argc, char const *argv[]) {

  char palabra[4];

  palabra[0] = 'A';
  palabra[1] = 'G';
  palabra[2] = 'U';
  palabra[3] = 'A';

  int cifrada[strlen(palabra)];

  printf("%s\n", palabra);

  //convertir cadena a minúsculas
  for(int i = 0; i < strlen(palabra); ++i){
      if(isupper(palabra[i])){
        palabra[i] = tolower(palabra[i]);
      }
  }
  printf("%s\n", palabra);

  for(int i = 0; i < strlen(palabra); ++i){
    cifrada[i] = palabra[i]%9;
  }

  for(int i = 0; i < strlen(palabra); ++i){
    printf("%d ", cifrada[i]);
  }

  for(int i = 0; i < strlen(palabra) ; ++i){

  }






  return 0;
}
