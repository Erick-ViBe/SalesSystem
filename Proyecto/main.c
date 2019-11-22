#include "supermercado.h"

int main(void) {

   struct Arbol *raiz = NULL;

   raiz = insertar(raiz, leerProducto());

   printf("Nombre: %s\n", raiz->productoAlmacenado.nombre);
   printf("Codigo: %d\n", raiz->productoAlmacenado.codigo);
   printf("Precio %f\n", raiz->productoAlmacenado.precio);

   return 0;
}
