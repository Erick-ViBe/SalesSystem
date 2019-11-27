#include "supermercado.h"

int main(void) {

   struct Arbol *raiz = NULL;

   int respuesta;
   char resp;

   do {

     menuprincipal:
     system("clear");
     printf("\t\tMENU DE COMPRAS: \n\n\t");
     printf("SELECCIONE LA OPCION: \n\n\t");
     printf("OPCION 1: ADMINISTRADOR\n\t");
     printf("OPCION 2: CAJERO\n\t");
     printf("OPCION 3: SALIR\n\t");

     scanf("%d", &respuesta);
     system("clear");

     if(respuesta == 1){

       printf("\t\tHA ENTRADO AL MENU ADMINISTRADOR\n\n\t\t");
       printf("SELECCIONE LA OPCION: \n\n\t");
       printf("OPCION 1: INGRESAR PRODUCTOS\n\t");
       printf("OPCION 2: MODIFICAR PRECIO DE UN PRODUCTO\n\t");
       printf("OPCION 3: MOSTRAR PRODUCTOS INGRESADOS\n\t");
       printf("OPCION 4: VOLVER AL MENU ANTERIOR\n\t");
       printf("OPCION 5: SALIR\n\t");

       scanf("%d", &respuesta);
       system("clear");

       if(respuesta == 1){
         printf("\t\tHA SELECCIONADO INGRESAR UN NUEVO PRODUCTO\n\t");

         struct Producto nuevoProducto;

         nuevoProducto = leerProducto();
         raiz = insertar(raiz, nuevoProducto);
         printf("\nEL PRODUCTO HA SIDO REGISTRADO\n");
         printf("NOMBRE: %s\n", nuevoProducto.nombre);
         printf("PRECIO: %.2f\n", nuevoProducto.precio);
         printf("CODIGO: %d\n", nuevoProducto.codigo);

       } else if(respuesta == 2) {

         printf("\t\tHA SELECCIONADO MODIFICAR PRECIO DE UN PRODUCTO\n\t");

         int codigoModificarPrecio;
         printf("\nCODIGO DE PRODUCTO A MODIFICAR: ");
         scanf("%d", &codigoModificarPrecio);
         modificarPrecio(raiz, codigoModificarPrecio);

      } else if(respuesta == 3) {

         printf("\t\tHA SELECCIONADO MOSTRAR PRODUCTOS INGRESADOS\n\t");
         mostrar(raiz);

      } else if(respuesta == 4) {

        goto menuprincipal;

      } else if(respuesta == 5){

        system("clear");
        printf("\t\tGRACIAR POR USAR ESTE PROGRAMA\n\t\t");
        exit(EXIT_SUCCESS);

      } else {

         printf("\t\tLA OPCION INGRESADA NO EXISTE. \n\t");

       }


     } else if(respuesta == 2) {

       printf("\t\tHA ENTRADO AL MENU CAJERO\n\n\t");
       printf("SELECCIONE LA OPCION: \n\n\t");
       printf("OPCION 1: REGISTRAR UNA NUEVA COMPRA\n\t");
       printf("OPCION 2: VOLVER AL MENU ANTERIOR\n\t");
       printf("OPCION 3: SALIR\n\t");

       scanf("%d", &respuesta);
       system("clear");

       if(respuesta == 1){

         printf("\t\tHA SELECCIONADO REGISTRAR UNA NUEVA COMPRA\n\t\t");
         struct Ticket nuevoTicket;
         nuevoTicket = finalizarCompra(leerCliente(), raiz);
         printf("\t\tTOTAL A PAGAR: %.2f\n", nuevoTicket.totalCompra);
         mostrarhora();

       } else if(respuesta == 2) {

         goto menuprincipal;

       } else if(respuesta == 3){

         system("clear");
         printf("\t\tGRACIAR POR USAR ESTE PROGRAMA\n\t\t");
         exit(EXIT_SUCCESS);

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
