#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int
main(void)
{
    Pila p;
    int i;
    tipoElemento v[]={45,25,45,50,60,50};
    int n =sizeof(v)/sizeof(tipoElemento);
    printf("Creando la cola vacia: %d\n", pilaCreaVacia(&p));

    for (i = 0; i < n; i++) {
        pilaInserta(&p, v[i]);
    }

    imprime(&p);

    printf("Vamos a eliminar un elemento de la cola : %d\n", pilaSuprime(&p));
    imprime(&p);

    printf("Vamos a eliminar un elemento de la cola : %d\n", pilaSuprime(&p));
    imprime(&p);
}


