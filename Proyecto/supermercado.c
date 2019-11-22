#include "supermercado.h"

struct Producto
leerProducto(void){

   struct Producto nuevo;
   float precioProducto;
   char nombreProducto[25];

   printf("Precio del Producto: \n");
   scanf("%f", &precioProducto);
   printf("Nombre del Producto: \n");
   scanf("%s",nombreProducto);

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

   scanf("Nombre del Cliente: %[^\n]",nombreCliente);
   scanf("Id de la tajeta: %d", &idTarjeta);

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
modificar(struct Arbol *raiz, int codigoBuscar){

	if (raiz == NULL) {

      return 0;
	} else if (raiz->productoAlmacenado.codigo == codigoBuscar) {

		printf("%f\n", raiz->productoAlmacenado.precio);
      float nuevoPrecio;
      scanf("Nuevo Precio:%f", &nuevoPrecio);
      raiz->productoAlmacenado.precio = nuevoPrecio;
      return 1;
	}	else if (codigoBuscar < raiz->productoAlmacenado.codigo) {

		return modificar(raiz->hijoIzquierdo, codigoBuscar);
	} else{

		return modificar(raiz->hijoDerecho, codigoBuscar);
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

     multiplicador = pow(10, (9 - strlen(parte1)));
     num *= multiplicador;
 }


  return num;
}
