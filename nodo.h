#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;

typedef struct Nodo * NodoPtr;
typedef void * DatoPtr;

/// @brief Reserva memoria para un Nodo con un dato generico
/// @return Un Nodo con el dato deseado
NodoPtr crearNodo(DatoPtr dato);

/// @brief Libera el espacio en memoria ocupado por un Nodo
/// @param nodo
void destruirNodo(NodoPtr nodo);

/// @brief Muestra por pantalla a un Nodo con un dato entero
/// @param nodo
void mostrarNodoInt(NodoPtr nodo);

/// @brief Muestra por pantalla a un Nodo con un dato char*
/// @param nodo
void mostrarNodoChar(NodoPtr nodo);

/// @brief Muestra por pantalla a un Nodo con un dato flotante
/// @param nodo
void mostrarNodoFloat(NodoPtr nodo);

/// @brief Asigna un nuevo valor al Nodo siguiente
/// @param nodo
/// @param siguiente
void setSiguiente(NodoPtr nodo, NodoPtr siguiente);

/// @brief Obtiene el siguiente Nodo del nodo pasado por parametro
/// @param nodo
NodoPtr getSiguiente(NodoPtr nodo);

/// @brief Asigna un nuevo valor al Dato perteneciente al Nodo
/// @param nodo
/// @param dato
void setDato(NodoPtr nodo, DatoPtr dato);

/// @brief Obtiene el dato del Nodo pasado por parametro
/// @param nodo
DatoPtr getDato(NodoPtr nodo);

/// @brief Verifica si un Nodo tiene como valor `NULL`
/// @param nodo
void chequearNullNodo(NodoPtr nodo);

#endif // NODO_H_INCLUDED
