#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "nodo.h"
#include "funciones.h"

void procedimientoListaInt();
void procedimientoListaChar();
void procedimientoListaFloat();

int main()
{
    procedimientoListaInt();
    procedimientoListaChar();
    procedimientoListaFloat();
}

void procedimientoListaInt() {
    printf("\n==== Procedimiento con Listas [int] ====\n");
    ListaPtr lista = crearLista();

    int dato1 = 10;
    int dato2 = 15;
    int dato3 = 20;

    NodoPtr nodo1 = crearNodo(&dato1);
    NodoPtr nodo2 = crearNodo(&dato2);
    NodoPtr nodo3 = crearNodo(&dato3);

    insertarPrincipio(lista, nodo1);
    insertarFinal(lista, nodo2);
    insertarEnPosicion(lista, nodo3, 1);

    ordenarListaBurbujeo(lista, compararInt);
    mostrarLista(lista, mostrarNodoInt);

    destruirLista(lista);

    printf("\n==== Fin procedimiento con Listas [int] ====\n");
}

void procedimientoListaChar() {
    printf("\n==== Procedimiento con Listas [char *] ====\n");
    ListaPtr lista = crearLista();

    char dato1[20] = "Francisco";
    char dato2[20] = "Javier";
    char dato3[20] = "Alfredo";

    NodoPtr nodo1 = crearNodo(&dato1);
    NodoPtr nodo2 = crearNodo(&dato2);
    NodoPtr nodo3 = crearNodo(&dato3);

    insertarPrincipio(lista, nodo1);
    insertarFinal(lista, nodo2);
    insertarEnPosicion(lista, nodo3, 1);

    ordenarListaBurbujeo(lista, compararChar);
    mostrarLista(lista, mostrarNodoChar);

    destruirLista(lista);
    printf("\n==== Fin procedimiento con Listas [char *] ====\n");
}

void procedimientoListaFloat() {
    printf("\n==== Procedimiento con Listas [float] ====\n");
    ListaPtr lista = crearLista();

    float dato1 = 100.24;
    float dato2 = 42.23;
    float dato3 = 10.56;

    NodoPtr nodo1 = crearNodo(&dato1);
    NodoPtr nodo2 = crearNodo(&dato2);
    NodoPtr nodo3 = crearNodo(&dato3);

    insertarPrincipio(lista, nodo1);
    insertarFinal(lista, nodo2);
    insertarEnPosicion(lista, nodo3, 1);

    ordenarListaBurbujeo(lista, compararFloat);
    mostrarLista(lista, mostrarNodoFloat);

    destruirLista(lista);
    printf("\n==== Fin procedimiento con Listas [float] ====\n");
}
