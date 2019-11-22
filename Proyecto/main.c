#include "supermercado.h"

int main(void) {

   struct Arbol *raiz = NULL;

   raiz = insertar(raiz, leerProducto());

   printf("Nombre %s\n", raiz->productoAlmacenado.nombre);

   return 0;
}
