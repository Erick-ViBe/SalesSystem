#include "supermercado.h"

int main(void) {

   struct Arbol *raiz = NULL;

   /*raiz = insertar(raiz, leerProducto());
   raiz = insertar(raiz, leerProducto());
   raiz = insertar(raiz, leerProducto());*/

   /*printf("Nombre: %s\n", raiz->productoAlmacenado.nombre);
   printf("Codigo: %d\n", raiz->productoAlmacenado.codigo);
   printf("Precio %f\n", raiz->productoAlmacenado.precio);

   printf("Nombre: %s\n", raiz->hijoDerecho->productoAlmacenado.nombre);
   printf("Codigo: %d\n", raiz->hijoDerecho->productoAlmacenado.codigo);
   printf("Precio %f\n", raiz->hijoDerecho->productoAlmacenado.precio);

   printf("Nombre: %s\n", raiz->hijoIzquierdo->productoAlmacenado.nombre);
   printf("Codigo: %d\n", raiz->hijoIzquierdo->productoAlmacenado.codigo);
   printf("Precio %f\n", raiz->hijoIzquierdo->productoAlmacenado.precio);*/


   int respuesta;

   printf("MENU DE COMPRAS: \n");
   printf("SELECCIONE LA OPCION: \n\n");
   printf("OPCION 1: ADMINISTRADOR\n");
   printf("OPCION 2: CAJERO\n");
   printf("OPCION 3: SALIR\n");

   scanf("%d", &respuesta);
   system("clear");

   if(respuesta == 1){

     printf("HA ENTRADO AL MENU ADMINISTRADOR\n");
     printf("SELECCIONE LA OPCION: \n\n");
     printf("OPCION 1: INGRESAR PRODUCTOS\n");
     printf("OPCION 2: MODIFICAR UN PRODUCTO\n");
     printf("OPCION 3: SALIR\n");

     scanf("%d", &respuesta);
     system("clear");

     if(respuesta == 1){

       printf("HA SELECCIONADO INGRESAR UN NUEVO PRODUCTO\n");

     } else if(respuesta == 2) {

       printf("HA SELECCIONADO MODIFICAR UN PRODUCTO\n");

     } else {

       printf("LA OPCION INGRESADA NO EXISTE. \n");
       
     }


   } else if(respuesta == 2) {

     printf("HA ENTRADO AL MENU CAJERO\n");
     printf("SELECCIONE LA OPCION: \n\n");
     printf("OPCION 1: REGISTRAR UNA NUEVA COMPRA\n");
     printf("OPCION 2: SALIR\n");


   } else if(respuesta == 3) {
     printf("GRACIAR POR USAR ESTE PROGRAMA\n");
     exit(EXIT_SUCCESS);

   } else {

     printf("LA OPCION INGRESADA NO EXISTE. \n");
     printf("LAS OPCIONES SON: \n\n");
     printf("OPCION 1: ADMINISTRADOR\n");
     printf("OPCION 2: CAJERO\n");
     printf("OPCION 3: SALIR\n");
   }

   return 0;
}
