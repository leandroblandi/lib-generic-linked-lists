#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct Lista {
    NodoPtr nodo;
};

ListaPtr crearLista() {
    ListaPtr lista = (ListaPtr) malloc(sizeof(struct Lista));

    if (lista == NULL) {
        return NULL;
    }

    lista->nodo = NULL;
    return lista;
}

void destruirLista(ListaPtr lista) {
    if (lista == NULL) {
        return;
    }

    int largo = obtenerLargo(lista);

    if (largo == 0) {
        free(lista);
        return;
    }

    NodoPtr nodoActual = lista->nodo;
    NodoPtr nodoSiguiente = NULL;

    for (int i = 0; i < largo; i++) {
        nodoSiguiente = getSiguiente(nodoActual);
        destruirNodo(nodoActual);
        nodoActual = nodoSiguiente;
    }
}

void mostrarLista(ListaPtr lista, void(*mostrarNodoFunc)(NodoPtr)) {
    if (lista == NULL) {
        printf("\n[ERROR] Lista con valor NULL\n");
    }

    int largo = obtenerLargo(lista);

    if (largo == 0) {
        printf("[INFO] Lista vacia");
        return;
    }

    printf("\n === Inicio lista ===\n");

    NodoPtr nodo = lista->nodo;

    for (int i = 0; i < largo; i++) {
        mostrarNodoFunc(nodo);
        nodo = getSiguiente(nodo);
    }

    printf("\n === Fin lista ===\n");
}

int obtenerLargo(ListaPtr lista) {
    if (lista == NULL) {
        return -1;
    }

    int largo = 0;
    NodoPtr nodoActual = lista->nodo;

    while (nodoActual != NULL) {
        largo++;
        nodoActual = getSiguiente(nodoActual);
    }

    return largo;
}

void insertarPrincipio(ListaPtr lista, NodoPtr nodo) {
    if (lista == NULL || nodo == NULL) {
        return;
    }

    setSiguiente(nodo, lista->nodo);
    setNodo(lista, nodo);
}

void insertarFinal(ListaPtr lista, NodoPtr nodo) {

    if (lista == NULL || nodo == NULL) {
        return;
    }

    int largo = obtenerLargo(lista);

    if (largo == 0) {
        insertarPrincipio(lista, nodo);
        return;
    }

    NodoPtr nodoActual = lista->nodo;

    // Recorremos hasta el largo - 1 debido a que el intentara
    // obtener el siguiente y será nulo
    for (int i = 0; i < largo - 1; i++) {
        nodoActual = getSiguiente(nodoActual);
    }

    setSiguiente(nodoActual, nodo);
}

void insertarEnPosicion(ListaPtr lista, NodoPtr nodo, int posicion) {

    if (lista == NULL || nodo == NULL || posicion < 0) {
        return;
    }

    int largo = obtenerLargo(lista);

    if (largo == 0 || posicion == 0) {
        insertarPrincipio(lista, nodo);
        return;
    }

    if (posicion > largo) {
        return;
    }

    if (posicion == largo) {
        insertarFinal(lista, nodo);
        return;
    }

    NodoPtr nodoActual = lista->nodo;

    for (int i = 0; i < posicion - 1; i++) {
        nodoActual = getSiguiente(nodoActual);
    }

    NodoPtr nodoAux = getSiguiente(nodoActual);
    setSiguiente(nodoActual, nodo);
    setSiguiente(nodo, nodoAux);
}

void insertarEnOrden(ListaPtr lista, NodoPtr nuevoNodo, int (*cmp)(void *, void *)) {
    if (lista == NULL || nuevoNodo == NULL) {
        return;
    }

    NodoPtr actual = getNodo(lista);
    NodoPtr anterior = NULL;

    if (actual == NULL || cmp(getDato(nuevoNodo), getDato(actual)) <= 0) {
        setSiguiente(nuevoNodo, actual);
        setNodo(lista, nuevoNodo);
        return;
    }

    while (actual != NULL && cmp(getDato(nuevoNodo), getDato(actual)) > 0) {
        anterior = actual;
        actual = getSiguiente(actual);
    }

    setSiguiente(nuevoNodo, actual);
    setSiguiente(anterior, nuevoNodo);
}

void ordenarListaBurbujeo(ListaPtr lista, int (*cmp)(void *, void *)) {
    if (lista == NULL || obtenerLargo(lista) == 0 || cmp == NULL) {
        return;
    }

    int largo = obtenerLargo(lista);

    for (int i = 0; i < largo; i++) {
        NodoPtr nodoActual = lista->nodo;
        NodoPtr nodoSiguiente = NULL;

        while (getSiguiente(nodoActual) != NULL) {
            nodoSiguiente = getSiguiente(nodoActual);

            if (cmp(getDato(nodoActual), getDato(nodoSiguiente)) > 0) {
                DatoPtr valorAuxiliar = getDato(nodoActual);
                setDato(nodoActual, getDato(nodoSiguiente));
                setDato(nodoSiguiente, valorAuxiliar);
            }

            nodoActual = getSiguiente(nodoActual);
        }
    }
}

void ordenarListaSeleccion(ListaPtr lista, int (*cmp)(void *, void *)) {
    if (lista == NULL || obtenerLargo(lista) == 0 || cmp == NULL) {
        return;
    }

    int largo = obtenerLargo(lista);
    NodoPtr nodoActual = NULL;
    NodoPtr nodoMinimo = NULL;

    for (int i = 0; i < largo - 1; i++) {
        nodoActual = lista->nodo;

        nodoMinimo = nodoActual;
        for (int j = i + 1; j < largo; j++) {
            nodoActual = getSiguiente(nodoActual);
            if (cmp(getDato(nodoActual), getDato(nodoMinimo)) < 0) {
                nodoMinimo = nodoActual;
            }
        }

        if (nodoMinimo != lista->nodo) {
            DatoPtr valorAuxiliar = getDato(lista->nodo);
            setDato(lista->nodo, getDato(nodoMinimo));
            setDato(nodoMinimo, valorAuxiliar);
        }

        lista->nodo = getSiguiente(lista->nodo);
    }
}

void ordenarListaInsercion(ListaPtr lista, int (*cmp)(void *, void *)) {
    if (lista == NULL || obtenerLargo(lista) == 0 || cmp == NULL) {
        return;
    }

    NodoPtr nodoActual = lista->nodo;
    NodoPtr nodoSiguiente;

    while (nodoActual != NULL) {
        nodoSiguiente = getSiguiente(nodoActual);
        NodoPtr nodoPrevio = lista->nodo;

        while (nodoPrevio != nodoActual && cmp(getDato(nodoActual), getDato(nodoPrevio)) < 0) {
            nodoPrevio = getSiguiente(nodoPrevio);
        }

        if (nodoPrevio != nodoActual) {
            DatoPtr valorAuxiliar = getDato(nodoActual);
            setDato(nodoActual, getDato(nodoPrevio));

            setDato(nodoPrevio, valorAuxiliar);
        }

        nodoActual = nodoSiguiente;
    }
}


int busquedaLineal(ListaPtr lista, DatoPtr dato, int (*cmp)(void *, void *)) {
    int pos = -1;

    if (lista == NULL || dato == NULL || obtenerLargo(lista) == 0 || cmp == NULL) {
        return pos;
    }

    int largo = obtenerLargo(lista);
    NodoPtr nodoActual = lista->nodo;

    for (int i = 0; i < largo; i++) {

        if (cmp(getDato(nodoActual), dato) == 0) {
            pos = i;
            break;
        }

        nodoActual = getSiguiente(nodoActual);
    }
    return pos;
}

int busquedaBinaria(ListaPtr lista, DatoPtr dato, int (*cmp)(void *, void *)) {
    if (lista == NULL || dato == NULL || obtenerLargo(lista) == 0 || cmp == NULL) {
        return -1;
    }

    int inicio = 0;
    int fin = obtenerLargo(lista) - 1;
    NodoPtr nodoActual;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        nodoActual = lista->nodo;
        for (int i = 0; i < medio; i++) {
            nodoActual = getSiguiente(nodoActual);
        }

        int comparacion = cmp(getDato(nodoActual), dato);

        if (comparacion == 0) {
            return medio;
        } else if (comparacion < 0) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return -1;
}

ListaPtr duplicarLista(ListaPtr listaOriginal) {
    ListaPtr nuevaLista = crearLista();

    if (listaOriginal == NULL || getNodo(listaOriginal) == NULL) {
        return nuevaLista;
    }

    NodoPtr actualOriginal = getNodo(listaOriginal);

    while (actualOriginal != NULL) {
        DatoPtr datoOriginal = getDato(actualOriginal);
        insertarFinal(nuevaLista, nuevoNodo);
        actualOriginal = getSiguiente(actualOriginal);
    }

    return nuevaLista;
}

void setNodo(ListaPtr lista, NodoPtr nodo) {
    lista->nodo = nodo;
}

NodoPtr getNodo(ListaPtr lista) {
    return lista->nodo;
}
