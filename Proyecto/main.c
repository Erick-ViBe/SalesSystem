#include "supermercado.h"

int main(void) {

   struct Arbol *raiz = NULL;
   //
   // raiz = insertar(raiz, leerProducto());
   // raiz = insertar(raiz, leerProducto());
   // raiz = insertar(raiz, leerProducto());
   //
   // printf("Nombre: %s\n", raiz->productoAlmacenado.nombre);
   // printf("Codigo: %d\n", raiz->productoAlmacenado.codigo);
   // printf("Precio: %.2f\n", raiz->productoAlmacenado.precio);
   //
   // printf("Nombre: %s\n", raiz->hijoDerecho->productoAlmacenado.nombre);
   // printf("Codigo: %d\n", raiz->hijoDerecho->productoAlmacenado.codigo);
   // printf("Precio: %.2f\n", raiz->hijoDerecho->productoAlmacenado.precio);
   //
   // printf("Nombre: %s\n", raiz->hijoIzquierdo->productoAlmacenado.nombre);
   // printf("Codigo: %d\n", raiz->hijoIzquierdo->productoAlmacenado.codigo);
   // printf("Precio: %.2f\n", raiz->hijoIzquierdo->productoAlmacenado.precio);
   //
   // while (getchar()!=32);

   int selector;
   char resp;

   do {
     system("clear");
     printf("MENU DE COMPRAS: \n\t\t");
     printf("SELECCIONE LA OPCION: \n\n\t\t");
     printf("OPCION 1: ADMINISTRADOR\n\t\t");
     printf("OPCION 2: CAJERO\n\t\t");
     printf("OPCION 3: SALIR\n\t\t");

     scanf("%d", &selector);
     system("clear");

     if(selector == 1){
       printf("HA ENTRADO AL MENU ADMINISTRADOR\n\n\t\t");
       printf("SELECCIONE LA OPCION: \n\n\t\t");
       printf("OPCION 1: INGRESAR PRODUCTOS\n\t\t");
       printf("OPCION 2: MODIFICAR UN PRODUCTO\n\t\t");
       printf("OPCION 3: SALIR\n");

       scanf("%d", &selector);
       system("clear");

       if(selector == 1){
         printf("HA SELECCIONADO INGRESAR UN NUEVO PRODUCTO\n\t\t");

       } else if(selector == 2) {
         printf("HA SELECCIONADO MODIFICAR UN PRODUCTO\n\t\t");

       } else if(selector == 3) {
         printf("GRACIAR POR USAR ESTE PROGRAMA\n\t\t");
         exit(EXIT_SUCCESS);

       } else {
         printf("LA OPCION INGRESADA NO EXISTE. \n\t\t");

       }


     } else if(selector == 2) {
       printf("HA ENTRADO AL MENU CAJERO\n\n\t\t");
       printf("SELECCIONE LA OPCION: \n\n\t\t");
       printf("OPCION 1: REGISTRAR UNA NUEVA COMPRA\n\t\t");
       printf("OPCION 2: SALIR\n\t\t");

       scanf("%d", &selector);
       system("clear");

       if(selector == 1){
         printf("HA SELECCIONADO REGISTRAR UNA NUEVA COMPRA\n\t\t");

       } else if(selector == 2) {
         printf("GRACIAR POR USAR ESTE PROGRAMA\n\t\t");
         exit(EXIT_SUCCESS);

       } else {
         printf("LA OPCION INGRESADA NO EXISTE. \n\t\t");

       }

     } else if(selector == 3) {
       system("clear");
       printf("GRACIAR POR USAR ESTE PROGRAMA\n\t\t");
       exit(EXIT_SUCCESS);

     } else {
       printf("LA OPCION INGRESADA NO EXISTE. \n\t\t");

     }
     printf("\nPresione 's' si desea realizar otra operacion\n\t\t");
     scanf("%s", &resp);

   } while(resp == 's' || resp == 'S');



   return 0;
}
