#include "supermercado.h"

struct Producto
leerProducto(){

   struct Producto nuevo;
   float precioProducto;
   char nombreProducto[25];

   printf("\n\tINGRESE EL NOMBRE: ");
   scanf("%s",nombreProducto);
   printf("\n\tINGRESE EL PRECIO: ");
   scanf("%f", &precioProducto);

   nuevo.precio = precioProducto;
   strcpy(nuevo.nombre, nombreProducto);
   nuevo.codigo = obtenerCodigo(nombreProducto);

   return nuevo;
}

struct Cliente
leerCliente(){

   struct Cliente nuevo;
   char nombreCliente[30];
   int idTarjeta;

   printf("\n\tNOMBRE DEL CLIENTE: ");
   scanf("%s", nombreCliente);
   printf("\n\tNUMERO DE TARJETA: ");
   scanf("%d", &idTarjeta);

   strcpy(nuevo.nombre, nombreCliente);
   nuevo.id_tarjeta = idTarjeta;

   return nuevo;
}

struct Arbol*
insertar(struct Arbol *raizArbol, struct Producto productoInsertar){

   struct Arbol *nuevo = NULL;

   if (raizArbol == NULL) {

      nuevo = malloc(sizeof(struct Arbol));
      if (nuevo == NULL) {
         return NULL;
      }
      nuevo->productoAlmacenado = productoInsertar;
      nuevo->fe = 0;
      nuevo->hijoDerecho = NULL;
      nuevo->hijoIzquierdo = NULL;
      return nuevo;
   }

   if (raizArbol->productoAlmacenado.codigo == productoInsertar.codigo) {

      return raizArbol;
   }

   if (productoInsertar.codigo > raizArbol->productoAlmacenado.codigo) {

      raizArbol->hijoDerecho = insertar(raizArbol->hijoDerecho, productoInsertar);
   } else {

      raizArbol->hijoIzquierdo = insertar(raizArbol->hijoIzquierdo, productoInsertar);
   }

   raizArbol->fe = calcularFE(raizArbol);
   if ((raizArbol->fe == -2) && (raizArbol->hijoIzquierdo->fe == -1)) {
			raizArbol = rotacionDerecha(raizArbol);
			raizArbol->fe = calcularFE(raizArbol);
			raizArbol->hijoDerecho->fe = calcularFE(raizArbol->hijoDerecho);
			raizArbol->hijoIzquierdo->fe = calcularFE(raizArbol->hijoIzquierdo);
		}

		if ((raizArbol->fe == 2) && (raizArbol->hijoDerecho->fe == 1)) {
			raizArbol = rotacionIzquierda(raizArbol);
			raizArbol->fe = calcularFE(raizArbol);
			raizArbol->hijoDerecho->fe = calcularFE(raizArbol->hijoDerecho);
			raizArbol->hijoIzquierdo->fe = calcularFE(raizArbol->hijoIzquierdo);
		}

		if ((raizArbol->fe > 1) && (raizArbol->hijoDerecho->fe < 0)) {
			raizArbol->hijoDerecho = rotacionDerecha(raizArbol->hijoDerecho);
			raizArbol = rotacionIzquierda(raizArbol);
			raizArbol->fe = calcularFE(raizArbol);
			raizArbol->hijoDerecho->fe = calcularFE(raizArbol->hijoDerecho);
			raizArbol->hijoIzquierdo->fe = calcularFE(raizArbol->hijoIzquierdo);
		}

		if ((raizArbol->fe < -1) && (raizArbol->hijoIzquierdo->fe > 0)) {
			raizArbol->hijoIzquierdo = rotacionIzquierda(raizArbol->hijoIzquierdo);
			raizArbol = rotacionDerecha(raizArbol);
			raizArbol->fe = calcularFE(raizArbol);
			raizArbol->hijoDerecho->fe = calcularFE(raizArbol->hijoDerecho);
			raizArbol->hijoIzquierdo->fe = calcularFE(raizArbol->hijoIzquierdo);
		}

   return raizArbol;
}

struct Arbol*
rotacionDerecha(struct Arbol *raizDesbalanceada) {

	struct Arbol *aux = raizDesbalanceada;
		struct Arbol *aux2 = NULL;
	raizDesbalanceada = raizDesbalanceada->hijoIzquierdo;

	if (raizDesbalanceada->hijoDerecho != NULL) {

		aux2 = raizDesbalanceada->hijoDerecho;
	}

	raizDesbalanceada->hijoDerecho = aux;

	raizDesbalanceada->hijoDerecho->hijoIzquierdo = aux2;

	return raizDesbalanceada;

}

struct Arbol*
rotacionIzquierda(struct Arbol *raizDesbalanceada) {

	struct Arbol *aux = raizDesbalanceada;
		struct Arbol *aux2 = NULL;
	raizDesbalanceada = raizDesbalanceada->hijoDerecho;

	if (raizDesbalanceada->hijoIzquierdo != NULL) {

		aux2 = raizDesbalanceada->hijoIzquierdo;
	}

	raizDesbalanceada->hijoIzquierdo = aux;

	raizDesbalanceada->hijoIzquierdo->hijoDerecho = aux2;

	return raizDesbalanceada;

}

int
calcularAltura(struct Arbol *raiz){

	int alturaDerecha = 0;
	int alturaIzquierda = 0;

	if (raiz == NULL) {
		return -1;
	}

	alturaIzquierda = calcularAltura(raiz->hijoIzquierdo);
	alturaDerecha = calcularAltura(raiz->hijoDerecho);

	if (alturaIzquierda > alturaDerecha) {
		return alturaIzquierda+1;
	}
	return alturaDerecha+1;
}

int
calcularFE(struct Arbol *raiz){

	int alturaDerecha = 0;
	int alturaIzquierda = 0;

	if (raiz == NULL) {
		return 0;
	}

	alturaIzquierda = calcularAltura(raiz->hijoIzquierdo);
	alturaDerecha = calcularAltura(raiz->hijoDerecho);

	return alturaDerecha - alturaIzquierda;
}

struct Producto
buscar(struct Arbol *raiz, int codigoBuscar){

	if (raiz == NULL) {
      struct Producto noExiste;
      noExiste.codigo = 0;
      noExiste.precio = 0;
      strcpy(noExiste.nombre, "");
		return noExiste;
	} else if (raiz->productoAlmacenado.codigo == codigoBuscar) {

		return raiz->productoAlmacenado;
	}	else if (codigoBuscar < raiz->productoAlmacenado.codigo) {

		return buscar(raiz->hijoIzquierdo, codigoBuscar);
	} else{

		return buscar(raiz->hijoDerecho, codigoBuscar);
	}
}

int
modificarPrecio(struct Arbol *raiz, int codigoBuscar){

	if (raiz == NULL) {

      return 0;
	} else if (raiz->productoAlmacenado.codigo == codigoBuscar) {

		printf("\n\tPRECIO ANTIGÜO: %f\n", raiz->productoAlmacenado.precio);
      float nuevoPrecio;
      printf("\n\tNUEVO PRECIO: ");
      scanf("%f", &nuevoPrecio);
      raiz->productoAlmacenado.precio = nuevoPrecio;
      return 1;
	}	else if (codigoBuscar < raiz->productoAlmacenado.codigo) {

		return modificarPrecio(raiz->hijoIzquierdo, codigoBuscar);
	} else{

		return modificarPrecio(raiz->hijoDerecho, codigoBuscar);
	}
}

char enteroacaracter(int numero){
   return numero + '0';
}

int obtenerCodigo(char *palabra){

   int acumulado = 0, num = 0;
   char parte2[8];

   for(int i = 0; i < strlen(palabra); ++i){
      if(isupper(palabra[i])){
         palabra[i] = tolower(palabra[i]);
      }
   }

   for(int i = 0; i < strlen(palabra); ++i){
      acumulado += palabra[i];
   }

   char *parte1 = malloc(4 * sizeof(char));
   sprintf(parte1, "%d", acumulado);

  int valor;
  char convertido;

  int i = 0;
   for(i = 0; i < strlen(palabra) && i < 5; i++){

      valor = palabra[i] % 9;
      if(valor == 0){
         valor = 9;
      }
      convertido = enteroacaracter(valor);
      parte2[i] = convertido;
   }

   parte2[i] = '\0';

   strcat(parte1, parte2);
   num = atoi(parte1);
   int multiplicador;

   if(strlen(parte1) < 10){
      multiplicador = pow(10,(9-strlen(parte1)));
      num *= multiplicador;
   }
   return num;
}

void listaInsertar(struct Lista **milista, struct Producto productoAgregado){

  struct Lista *temporal = malloc(sizeof(struct Lista));
  temporal -> productoComprado = productoAgregado;
  temporal -> siguiente = *milista;

  if (*milista == NULL) {
    *milista = temporal;
	return;
  } else {

    *milista = temporal;
  }
}

struct Ticket finalizarCompra(struct Cliente clienteTicket, struct Arbol *raizArbol){

   struct Ticket nuevo;

   struct Lista *compraTicket = NULL;
   struct Producto busqueda;
   float totalCompraTicket = 0;
   int codigoCompraTicket;
   char comprarProducto;

   do {

      printf("\n\tINGRESE EL CODIGO DEL PRODUCTO: ");
      scanf("%d", &codigoCompraTicket);
      busqueda = buscar(raizArbol, codigoCompraTicket);
      listaInsertar(&compraTicket, busqueda);
      totalCompraTicket += busqueda.precio;
      printf("\n\t\tPRESIONE 'S' PARA AGREGAR OTRO PRODUCTO\n");
      scanf("%s", &comprarProducto);
   } while(comprarProducto=='S' || comprarProducto=='s');

   nuevo.ClienteCompra = clienteTicket;
   nuevo.listaCompra = *compraTicket;
   nuevo.totalCompra = totalCompraTicket;

   return nuevo;
}

void
mostrar (struct Arbol *raiz)
{
  if (raiz == NULL)
    {
      return;
    }

  mostrar (raiz->hijoIzquierdo);
  printf ("\n\tNOMBRE: %s", raiz->productoAlmacenado.nombre);
  printf ("\n\tPRECIO: $ %.2f", raiz->productoAlmacenado.precio);
  printf ("\n\tCODIGO: %d\n", raiz->productoAlmacenado.codigo);
  mostrar (raiz->hijoDerecho);
}

void mostrarhora(void){

  time_t t;
  struct tm *tm;

  t = time(NULL);
  tm = localtime(&t);

    printf("\t\tCOMPRA REALIZADA A LAS: %02d:%02d:%02d\n\t\t", tm -> tm_hour, tm -> tm_min, tm -> tm_sec );
    printf ("DE FECHA: %02d/%02d/%d\n\t\t", tm -> tm_mday, tm -> tm_mon,1900 + tm -> tm_year);
    printf("GRACIAS POR SU COMPRA \n\t\t");


}
