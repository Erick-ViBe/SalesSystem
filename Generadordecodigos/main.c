#include "generadorcodigos.h"

int main(int argc, char const *argv[]) {

  char palabra[20];

  scanf("%[^\n]",palabra);
  printf("El nombre del producto es: %s\n", palabra);

  printf("El codigo del producto ingresado es: %d\n", obtenercodigo(palabra));

  return 0;
}
