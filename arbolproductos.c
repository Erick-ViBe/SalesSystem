#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"
#include "stdlib.h"

struct Producto {

   int codigo;
   char nombre[25];
   float precio;
};

struct Arbol {

   struct Producto productoAlmacenado;
   struct Arbol *hijoDerecho;
   struct Arbol *hijoIzquierdo;
   int fe;
};

struct Producto leerProducto();
struct Arbol* insertar();
struct Arbol* rotacionDerecha();
struct Arbol* rotacionIzquierda();
int calcularAltura();
int calcularFE();
struct Producto buscar();
int modificar();
char enteroacaracter();
int obtenerCodigo();

int main(void) {

   // struct Arbol *raiz = NULL;
   //
   // struct Producto nuevo;
   // nuevo.codigo = 13;
   // nuevo.precio = 5.69;
   // strcpy(nuevo.nombre, "agua");
	// raiz = insertar(raiz, nuevo);
   //
   // nuevo.codigo = 2;
   // nuevo.precio = 8.17;
   // strcpy(nuevo.nombre, "mole");
	// raiz = insertar(raiz, nuevo);
   //
   // nuevo.codigo = 4;
   // nuevo.precio = 25.29;
   // strcpy(nuevo.nombre, "sal");
	// raiz = insertar(raiz, nuevo);
   //
   // nuevo.codigo = 5;
   // nuevo.precio = 5.69;
   // strcpy(nuevo.nombre, "azucar");
	// raiz = insertar(raiz, nuevo);
   //
   // nuevo.codigo = 36;
   // nuevo.precio = 8.17;
   // strcpy(nuevo.nombre, "cloro");
	// raiz = insertar(raiz, nuevo);
   //
   // nuevo.codigo = 11;
   // nuevo.precio = 25.29;
   // strcpy(nuevo.nombre, "jabon");
	// raiz = insertar(raiz, nuevo);
   //
   // nuevo.codigo = 42;
   // nuevo.precio = 5.69;
   // strcpy(nuevo.nombre, "atun");
	// raiz = insertar(raiz, nuevo);
   //
   // nuevo.codigo = 0;
   // nuevo.precio = 8.17;
   // strcpy(nuevo.nombre, "queso");
	// raiz = insertar(raiz, nuevo);
   //
   // nuevo.codigo = 12;
   // nuevo.precio = 25.29;
   // strcpy(nuevo.nombre, "cafe");
	// raiz = insertar(raiz, nuevo);
   //
   // printf("%d - (%f) - (%s)\n", raiz->productoAlmacenado.codigo , raiz->productoAlmacenado.precio, raiz->productoAlmacenado.nombre);
	// printf("%d - (%f) - (%s)\n", raiz->hijoDerecho->productoAlmacenado.codigo, raiz->hijoDerecho->productoAlmacenado.precio, raiz->hijoDerecho->productoAlmacenado.nombre);
	// printf("%d - (%f) - (%s)\n", raiz->hijoDerecho->hijoDerecho->productoAlmacenado.codigo , raiz->hijoDerecho->hijoDerecho->productoAlmacenado.precio, raiz->hijoDerecho->hijoDerecho->productoAlmacenado.nombre);
	// printf("%d - (%f) - (%s)\n", raiz->hijoDerecho->hijoDerecho->hijoDerecho->productoAlmacenado.codigo, raiz->hijoDerecho->hijoDerecho->hijoDerecho->productoAlmacenado.precio, raiz->hijoDerecho->hijoDerecho->hijoDerecho->productoAlmacenado.nombre);
	// printf("%d - (%f) - (%s)\n", raiz->hijoDerecho->hijoIzquierdo->productoAlmacenado.codigo, raiz->hijoDerecho->hijoIzquierdo->productoAlmacenado.precio, raiz->hijoDerecho->hijoIzquierdo->productoAlmacenado.nombre);
	// printf("%d - (%f) - (%s)\n", raiz->hijoDerecho->hijoIzquierdo->hijoDerecho->productoAlmacenado.codigo, raiz->hijoDerecho->hijoIzquierdo->hijoDerecho->productoAlmacenado.precio, raiz->hijoDerecho->hijoIzquierdo->hijoDerecho->productoAlmacenado.nombre);
	// printf("%d - (%f) - (%s)\n", raiz->hijoIzquierdo->productoAlmacenado.codigo, raiz->hijoIzquierdo->productoAlmacenado.precio, raiz->hijoIzquierdo->productoAlmacenado.nombre);
	// printf("%d - (%f) - (%s)\n", raiz->hijoIzquierdo->hijoDerecho->productoAlmacenado.codigo, raiz->hijoIzquierdo->hijoDerecho->productoAlmacenado.precio, raiz->hijoIzquierdo->hijoDerecho->productoAlmacenado.nombre);
	// printf("%d - (%f) - (%s)\n", raiz->hijoIzquierdo->hijoIzquierdo->productoAlmacenado.codigo, raiz->hijoIzquierdo->hijoIzquierdo->productoAlmacenado.precio, raiz->hijoIzquierdo->hijoIzquierdo->productoAlmacenado.nombre);
   //
   // nuevo = buscar(raiz, 11);
   //
   // printf("%d - (%f) - (%s)\n", nuevo.codigo , nuevo.precio, nuevo.nombre);

   // modificar(raiz, 12);

   int desicionesMenu;

   printf("1-Cliente\n");
   printf("2-Administrador\n");
   scanf("%d", &desicionesMenu);

   switch (desicionesMenu) {
      case 1:
         printf("1-Comprar\n");
         scanf("%d", &desicionesMenu);
         switch (desicionesMenu) {
            case 1:

            break;
            default:
               printf("nel\n");
         }
      break;
      case 2:
         printf("1-Registrar Producto\n");
         printf("2-Modificar Producto\n");
         scanf("%d", &desicionesMenu);
         switch (desicionesMenu) {
            case 1:

               break;
            case 2:

               break;
            default:
               printf("nel\n");
         }
      break;
      default:
         printf("nel\n");
   }

   return 0;
}

char enteroacaracter(int numero){
  return numero + '0';
}

int obtenerCodigo(char *palabra){

  int acumulado = 0;
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
  for(i = 0; i < strlen(palabra) && i < 6; i++){

    valor = palabra[i] % 9;
    if(valor == 0){
      valor = 9;
    }
    convertido = enteroacaracter(valor);
    parte2[i] = convertido;
  }

  parte2[i] = '\0';

  strcat(parte1, parte2);

  int num = atoi(parte1);

  return num;
}

struct Producto
leerProducto(){

   struct Producto nuevo;
   float precioProducto;
   char nombreProducto[25];

   scanf("Precio del Producto: %f\n", &precioProducto);
   scanf("Nombre del Producto: %[^\n]",nombreProducto);

   nuevo.precio = precioProducto;
   strcpy(nuevo.nombre, nombreProducto);
   nuevo.codigo = obtenerCodigo(nombreProducto);

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
      scanf("%f\n", &nuevoPrecio);
      raiz->productoAlmacenado.precio = nuevoPrecio;
      return 1;
	}	else if (codigoBuscar < raiz->productoAlmacenado.codigo) {

		return modificar(raiz->hijoIzquierdo, codigoBuscar);
	} else{

		return modificar(raiz->hijoDerecho, codigoBuscar);
	}
}
