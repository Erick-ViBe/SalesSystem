#include <stdio.h>
#include <stdlib.h>

struct Producto {

   int codigo;
   char nombre[];
   float precio;
};

struct Nodo {

   struct Producto producto_almacenado;
   struct Nodo *nododerecho;
   struct Nodo *nodoizquierdo;
};
