#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista;
typedef struct Lista * ListaPtr;

/// @brief Reserva memoria para una Lista
/// @return Una Lista vacia
ListaPtr crearLista();

/// @brief Libera el espacio en memoria ocupado por una Lista
/// @param lista
void destruirLista(ListaPtr lista);

/// @brief Imprime por consola una lista generica
/// @param lista
/// @param mostrarNodoFunc(NodoPtr) La funcion callback a mostrar nodo segun tipo de dato
void mostrarLista(ListaPtr lista, void(*mostrarNodoFunc)(NodoPtr));

/// @brief Retorna el largo de la lista
/// @param lista
int obtenerLargo(ListaPtr lista);

/// @brief Inserta un Nodo al principio de la Lista
/// @param lista
/// @param nodo
void insertarPrincipio(ListaPtr lista, NodoPtr nodo);

/// @brief Inserta un nuevo Nodo de manera ordenada
/// @param lista
/// @param nuevoNodo
/// @param cmp La funcion que compara los datos de los Nodos
void insertarEnOrden(ListaPtr lista, NodoPtr nuevoNodo, int (*cmp)(void *, void *));

/// @brief Inserta un Nodo al final de la Lista
/// @param lista
/// @param nodo
void insertarFinal(ListaPtr lista, NodoPtr nuevoNodo);

/// @brief Inserta un Nodo en una posicion `n` de la Lista
/// @param lista
/// @param nodo
/// @param posicion La posicion entre 0 y `x`, siendo `x` el largo de la Lista
void insertarEnPosicion(ListaPtr lista, NodoPtr nodo, int posicion);

/// @brief Ordena la lista de menor a mayor usando el algoritmo de Bubble Sort
/// @param lista
/// @param cmp(void*, void*) La funcion comparadora
void ordenarListaBurbujeo(ListaPtr lista, int (*cmp)(void *, void *));

/// @brief Ordena la lista de menor a mayor usando el algoritmo de Selection Sort
/// @param lista
/// @param cmp(void*, void*) La funcion comparadora
void ordenarListaSeleccion(ListaPtr lista, int (*cmp)(void *, void *));

/// @brief Ordena la lista de menor a mayor usando el algoritmo de Inserction Sort
/// @param lista
/// @param cmp(void*, void*) La funcion comparadora
void ordenarListaInsercion(ListaPtr lista, int (*cmp)(void *, void *));

/// @brief Busca un dato en la Lista y retorna su posicion en la misma
/// @param lista
/// @param dato
/// @param cmp(void*, void*) La funcion comparadora
int busquedaLineal(ListaPtr lista, DatoPtr dato, int (*cmp)(void *, void *));

/// @brief Busca un dato en la Lista y retorna su posicion en la misma
///        Utiliza el algoritmo de busqueda binaria
/// @param lista
/// @param dato
/// @param cmp(void*, void*) La funcion comparadora
int busquedaBinaria(ListaPtr lista, DatoPtr dato, int (*cmp)(void *, void *));

/// @brief Crea una nueva lista con los mismos valores que la lista
///        ya existente, con nuevas direcciones de memoria
ListaPtr duplicarLista(ListaPtr listaOriginal)

/// @brief Asigna un nuevo valor al Nodo principal de la Lista
/// @param lista
/// @param nodo
void setNodo(ListaPtr lista, NodoPtr nodo);

/// @brief Obtiene el primer Nodo de la Lista
/// @param lista
NodoPtr getNodo(ListaPtr lista);

#endif // LISTA_H_INCLUDED
