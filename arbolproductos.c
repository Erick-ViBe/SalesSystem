#include <stdio.h>
#include <stdlib.h>

struct Producto {

   int codigo;
   char nombre[];
   float precio;
};

struct Nodo {
   struct Producto producto_almacenado;
   struct Nodo *hijo_derecho;
   struct Nodo *hijo_izquierdo;
   int fe;
};

struct Producto buscar(int codigo_a_buscar, struct Nodo *raiz_arbol_productos) {

   if (raiz_arbol_productos == null) {
      return null;

   } else if (raiz_arbol_productos->producto_almacenado.codigo == codigo_a_buscar) {
      return raiz_arbol_productos->producto_almacenado;

   } else if (codigo_a_buscar < raiz_arbol_productos->producto_almacenado.codigo) {
      return buscar(codigo_a_buscar, raiz_arbol_productos->hijo_izquierdo);

   } else {
      return codigo_a_buscar(codigo_a_buscar, raiz_arbol_productos->hijo_derecho);

   }
}

struct Nodo* crearNodo(struct Producto datosNodo){

}

//No terminado
void insertar(struct Producto producto_a_insertar, struct Nodo **raiz_arbol_productos) {

  if(*raiz_arbol_productos == NULL){
      raiz_arbol_productos = malloc(sizeof(struct nodo));
  }

  struct nodo *nodotemporal = malloc(sizeof(struct nodo));

   struct Nodo* nodoCreado;
   *nodoCreado = crearNodo(producto_a_insertar);

   struct Nodo* auxiliar;
//cdcdc
   if (raiz_arbol_productos == null) {

      return null;
   } else if (nodoCreado->producto_almacenado.codigo < raiz_arbol_productos->producto_almacenado.codigo) {

      return buscar(codigo_a_buscar, raiz_arbol_productos->hijo_izquierdo);
   } else {

      return codigo_a_buscar(codigo_a_buscar, raiz_arbol_productos->hijo_derecho);
   }


}
