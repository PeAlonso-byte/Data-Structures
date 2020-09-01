#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p)
{
        *p = NULL;
        return 0;
}

int pilaVacia(Pila *p)
{
   if (*p == NULL) {
       return 1;
   } else {
       return 0;
   }
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
        tipoCelda *aux, *aux2;

        if (NULL == (aux = malloc(sizeof(tipoCelda)))){
            return -1;
        }
        aux->elemento   = elemento;
        aux->sig        = NULL;

        if (pilaVacia(p)) {
            *p = aux;
        } else {
            aux2 = *p;
            *p = aux;
            aux->sig = aux2;
        }

}

tipoElemento pilaSuprime(Pila *p)
{
   tipoCelda *aux, *aux2;
   tipoElemento dato;

   

   if (pilaVacia(p)) {
       return 0;
   } else {
       aux = *p;
       dato = aux->elemento;
       *p = aux->sig;

       free(aux);
       return dato;
   }
}

void imprime(Pila *p) {
    tipoCelda *aImprimir;
    int posicion;

    if (p == NULL) {
        return;
    } else {
        posicion = 1;
        aImprimir = *p;

        while (aImprimir != NULL) {
            printf("Valor: %d en posicion %d\n", aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;
        }
        printf("%d valores en la cola\n",posicion-1);
    }
}
