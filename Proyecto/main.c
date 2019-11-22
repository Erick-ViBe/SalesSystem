#include "supermercado.h"

int main(void) {

   struct Arbol *raiz = NULL;

   raiz = insertar(raiz, leerProducto());
   raiz = insertar(raiz, leerProducto());
   raiz = insertar(raiz, leerProducto());

   printf("Nombre: %s\n", raiz->productoAlmacenado.nombre);
   printf("Codigo: %d\n", raiz->productoAlmacenado.codigo);
   printf("Precio %f\n", raiz->productoAlmacenado.precio);

   printf("Nombre: %s\n", raiz->hijoDerecho->productoAlmacenado.nombre);
   printf("Codigo: %d\n", raiz->hijoDerecho->productoAlmacenado.codigo);
   printf("Precio %f\n", raiz->hijoDerecho->productoAlmacenado.precio);

   printf("Nombre: %s\n", raiz->hijoIzquierdo->productoAlmacenado.nombre);
   printf("Codigo: %d\n", raiz->hijoIzquierdo->productoAlmacenado.codigo);
   printf("Precio %f\n", raiz->hijoIzquierdo->productoAlmacenado.precio);

   return 0;
}
