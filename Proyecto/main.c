#include "supermercado.h"

int main(void) {

   struct Arbol *raiz = NULL;

   raiz = insertar(raiz, leerProducto());

   return 0;
}
