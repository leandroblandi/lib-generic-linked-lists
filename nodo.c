#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"

struct Nodo {
    DatoPtr dato;
    NodoPtr siguiente;
};

NodoPtr crearNodo(DatoPtr dato) {
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    if (nodo == NULL) {
        return NULL;
    }

    nodo->dato = dato;
    nodo->siguiente = NULL;
    return nodo;
}

void destruirNodo(NodoPtr nodo) {
    if (nodo == NULL) {
        return;
    }
    free(nodo);
}

void mostrarNodoInt(NodoPtr nodo) {
    chequearNullNodo(nodo);

    printf("\nNodo(valor=%d, proximo=%p)\n", *((int *) nodo->dato), nodo->siguiente);
}

void mostrarNodoChar(NodoPtr nodo) {
    chequearNullNodo(nodo);
    printf("\nNodo(valor=%s, proximo=%p)\n", (char *) nodo->dato, nodo->siguiente);
}

void mostrarNodoFloat(NodoPtr nodo) {
    chequearNullNodo(nodo);
    printf("\nNodo(valor=%.2f, proximo=%p)\n", *((float *) nodo->dato), nodo->siguiente);
}

void setSiguiente(NodoPtr nodo, NodoPtr siguiente) {
    nodo->siguiente = siguiente;
}

NodoPtr getSiguiente(NodoPtr nodo) {
    return nodo->siguiente;
}

void setDato(NodoPtr nodo, DatoPtr dato) {
    nodo->dato = dato;
}

DatoPtr getDato(NodoPtr nodo) {
    return nodo->dato;
}

void chequearNullNodo(NodoPtr nodo) {
    if (nodo == NULL) {
        printf("\n[ERROR] El nodo tiene valor NULL\n");
        return;
    }
}

