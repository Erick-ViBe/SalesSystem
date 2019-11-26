#include "supermercado.h"

int main(void) {

   struct Arbol *raiz = NULL;

   int selector;
   char resp;

   do {
     system("clear");
     printf("MENU DE COMPRAS: \n\n\t");
     printf("SELECCIONE LA OPCION: \n\n\t");
     printf("OPCION 1: ADMINISTRADOR\n\t");
     printf("OPCION 2: CAJERO\n\t");
     printf("OPCION 3: SALIR\n\t");

     scanf("%d", &selector);
     system("clear");

     if(selector == 1){
       printf("HA ENTRADO AL MENU ADMINISTRADOR\n\n\t");
       printf("SELECCIONE LA OPCION: \n\n\t");
       printf("OPCION 1: INGRESAR PRODUCTOS\n\t");
       printf("OPCION 2: MODIFICAR PRECIO DE UN PRODUCTO\n\t");
       printf("OPCION 3: MOSTRAR PRODUCTOS INGRESADOS\n\t");
       printf("OPCION 4: VOLVER AL MENU ANTERIOR\n");

       scanf("%d", &selector);
       system("clear");

       if(selector == 1){
         printf("HA SELECCIONADO INGRESAR UN NUEVO PRODUCTO\n\t\t");
         struct Producto nuevoProducto;
         nuevoProducto = leerProducto();
         raiz = insertar(raiz, nuevoProducto);
         printf("Su producto ha sido ingresado\n");
         printf("Nombre: %s\n", nuevoProducto.nombre);
         printf("Precio: %f\n", nuevoProducto.precio);
         printf("Codigo: %d\n", nuevoProducto.codigo);

       } else if(selector == 2) {
         printf("HA SELECCIONADO MODIFICAR PRECIO DE UN PRODUCTO\n\t");

         int codigoModificarPrecio;
         printf("Codigo de producto a modificar: ");
         scanf("%d", &codigoModificarPrecio);
         modificarPrecio(raiz, codigoModificarPrecio);

      } else if(selector == 3) {
         printf("HA SELECCIONADO MOSTRAR PRODUCTOS INGRESADOS\n\t");

         mostrar(raiz);

      } else if(selector == 4) {
         printf("GRACIAR POR USAR ESTE PROGRAMA\n\t");
         exit(EXIT_SUCCESS);

       } else {
         printf("LA OPCION INGRESADA NO EXISTE. \n\t");

       }


     } else if(selector == 2) {
       printf("HA ENTRADO AL MENU CAJERO\n\n\t");
       printf("SELECCIONE LA OPCION: \n\n\t");
       printf("OPCION 1: REGISTRAR UNA NUEVA COMPRA\n\t");
       printf("OPCION 2: VOLVER AL MENU ANTERIOR\n\t");

       scanf("%d", &selector);
       system("clear");

       if(selector == 1){
         printf("HA SELECCIONADO REGISTRAR UNA NUEVA COMPRA\n\t");
         struct Ticket nuevoTicket;
         nuevoTicket = finalizarCompra(leerCliente(), raiz);
         printf("Total a Pagar: %.2f\n", nuevoTicket.totalCompra);
       } else if(selector == 2) {
         printf("GRACIAR POR USAR ESTE PROGRAMA\n\t");
         exit(EXIT_SUCCESS);

       } else {
         printf("LA OPCION INGRESADA NO EXISTE. \n\t");

       }

     } else if(selector == 3) {
       system("clear");
       printf("GRACIAR POR USAR ESTE PROGRAMA\n\t");
       exit(EXIT_SUCCESS);

     } else {
       printf("LA OPCION INGRESADA NO EXISTE. \n\t");

     }
     printf("\nPresione 's' si desea realizar otra operacion\n\t");
     scanf("%s", &resp);

   } while(resp == 's' || resp == 'S');



   return 0;
}
