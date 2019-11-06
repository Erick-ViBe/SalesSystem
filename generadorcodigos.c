#include "stdio.h"
#include "string.h"
#include "ctype.h"

int main(int argc, char const *argv[]) {

  char palabra[] = "PALABRAs";
  char contenedor;
  char cifrada[] = {};
  printf("%s\n", palabra);

  //convertir a minúsculas
  for(int i = 0; i < strlen(palabra); ++i){
      if(isupper(palabra[i])){
        palabra[i] = tolower(palabra[i]);
      }
  }


  for(int i = 0; i < strlen(palabra); ++i){

    contenedor = (char)palabra[i]%9;
    //strcat(cifrada, contenedor);
  }

  printf("%s\n",palabra);

  /*for(int i = 97; i <= 122; ++i){
    printf("%d mod9 =  %d\n",i, i % 9);
  }*/

  return 0;
}
