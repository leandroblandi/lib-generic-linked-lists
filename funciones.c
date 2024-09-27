#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

int compararInt(void * d1, void * d2) {
    chequearParametros(d1, d2);

    int dato1 = *(int *) d1;
    int dato2 = *(int *) d2;

    if (dato1 > dato2) {
        return 1;
    } else if (dato1 == dato2) {
        return 0;
    } else {
        return -1;
    }
}

int compararChar(void * d1, void * d2) {
    chequearParametros(d1, d2);

    char * dato1 = (char *) d1;
    char * dato2 = (char *) d2;

    return strcmp(dato1, dato2);
}

int compararFloat(void * d1, void * d2) {
    chequearParametros(d1, d2);

    float dato1 = *(float *) d1;
    float dato2 = *(float *) d2;

    if (dato1 > dato2) {
        return 1;
    } else if (dato1 == dato2) {
        return 0;
    } else {
        return -1;
    }
}

void chequearParametros(void * d1, void * d2) {
    if (d1 == NULL || d2 == NULL) {
        return;
    }
}
