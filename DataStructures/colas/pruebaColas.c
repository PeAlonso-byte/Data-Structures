#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cola.h"

int main () {
    Cola cola;
    int i;
    tipoElemento v[]={45,25,45,50,60,50};
    int n =sizeof(v)/sizeof(tipoElemento);
    printf("Creando la cola vacia: %d\n", colaCreaVacia(&cola));

    for (i = 0; i < n; i++) {
        colaInserta(&cola, v[i]);
    }

    imprime(&cola);

    printf("Vamos a eliminar un elemento de la cola : %d\n", colaSuprime(&cola));
    imprime(&cola);

    printf("Vamos a eliminar un elemento de la cola : %d\n", colaSuprime(&cola));
    imprime(&cola);

    return 0;
}