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

   int respuesta;
   char resp;

   do {
     system("clear");
     printf("\t\tMENU DE COMPRAS: \n\t\t");
     printf("SELECCIONE LA OPCION: \n\n\t\t");
     printf("OPCION 1: ADMINISTRADOR\n\t\t");
     printf("OPCION 2: CAJERO\n\t\t");
     printf("OPCION 3: SALIR\n\t\t");

     scanf("%d", &respuesta);
     system("clear");

     if(respuesta == 1){
       printf("\t\tHA ENTRADO AL MENU ADMINISTRADOR\n\n\t\t");
       printf("SELECCIONE LA OPCION: \n\n\t\t");
       printf("OPCION 1: INGRESAR PRODUCTOS\n\t\t");
       printf("OPCION 2: MODIFICAR PRECIO DE UN PRODUCTO\n\t\t");
       printf("OPCION 3: MOSTRAR PRODUCTOS INGRESADOS\n\t\t");
       printf("OPCION 4: VOLVER AL MENU ANTERIOR\n");

       scanf("%d", &respuesta);
       system("clear");

       if(respuesta == 1){
         printf("\t\tHA SELECCIONADO INGRESAR UN NUEVO PRODUCTO\n\t\t");
         struct Producto nuevoProducto;
         nuevoProducto = leerProducto();
         raiz = insertar(raiz, nuevoProducto);
         printf("EL PRODUCTO HA SIDO REGISTRADO\n");
         printf("NOMBRE: %s\n", nuevoProducto.nombre);
         printf("PRECIO: %.2f\n", nuevoProducto.precio);
         printf("CODIGO: %d\n", nuevoProducto.codigo);

       } else if(respuesta == 2) {
         printf("\t\tHA SELECCIONADO MODIFICAR PRECIO DE UN PRODUCTO\n\t\t");

         int codigoModificarPrecio;
         printf("CODIGO DE PRODUCTO A MODIFICAR: ");
         scanf("%d", &codigoModificarPrecio);
         modificarPrecio(raiz, codigoModificarPrecio);

      } else if(respuesta == 3) {
         printf("\t\tHA SELECCIONADO MOSTRAR PRODUCTOS INGRESADOS\n\t\t");

         mostrar(raiz);

      } else if(respuesta == 4) {

        printf("\n\t\tSALIENDO DE LA OPCION...\n");

       } else {

         printf("\t\tLA OPCION INGRESADA NO EXISTE. \n\t\t");

       }


     } else if(respuesta == 2) {
       printf("\t\tHA ENTRADO AL MENU CAJERO\n\n\t\t");
       printf("SELECCIONE LA OPCION: \n\n\t\t");
       printf("OPCION 1: REGISTRAR UNA NUEVA COMPRA\n\t\t");
       printf("OPCION 2: VOLVER AL MENU ANTERIOR\n\t\t");

       scanf("%d", &respuesta);
       system("clear");

       if(respuesta == 1){
         printf("\t\tHA SELECCIONADO REGISTRAR UNA NUEVA COMPRA\n\t\t");
         struct Ticket nuevoTicket;
         nuevoTicket = finalizarCompra(leerCliente(), raiz);
         printf("TOTAL A PAGAR: %.2f\n", nuevoTicket.totalCompra);
         mostrarhora();
       } else if(respuesta == 2) {

         printf("\n\t\tSALIENDO DE LA OPCION...\n");

       } else {
         printf("\t\tLA OPCION INGRESADA NO EXISTE. \n\t\t");

       }

     } else if(respuesta == 3) {
       system("clear");
       printf("\t\tGRACIAR POR USAR ESTE PROGRAMA\n\t\t");
       exit(EXIT_SUCCESS);

     } else {
       printf("\t\tLA OPCION INGRESADA NO EXISTE. \n\t\t");

     }

     printf("\n\t\tPRESIONE 'S' PARA REALIZAR OTRA OPERACION\n\t\t");
     scanf("%s", &resp);

   } while(resp == 's' || resp == 'S');



   return 0;
}
