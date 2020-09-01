#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"



int colaCreaVacia(Cola *c)
{
    
    if (c == NULL)
        return -2;
    else if (NULL == (c->frente = c->fondo = (tipoCelda *)malloc(sizeof(tipoCelda))))
        return -1;
    else {
        c->frente->sig = NULL;
        
    }
    return 0;
    
}

int colaVacia(Cola *c)
{
    
    if (c == NULL || c->frente == NULL || c->fondo == NULL) {
        return -1;
    }
    else if (c->frente->sig == NULL || c->fondo->sig == NULL)
        return 1;
    else
        return 0;
    
}

void imprime(Cola *c) {
    tipoCelda *aImprimir;
    int posicion;

    if (c == NULL || c->frente == NULL) {
        return;
    } else {
        posicion = 1;
        aImprimir = c->frente;

        while (aImprimir != NULL) {
            printf("Valor: %d en posicion %d\n", aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;
        }
        printf("%d valores en la cola\n",posicion-1);
    }
}

int colaInserta(Cola *c,tipoElemento elemento)
{
    tipoCelda *new;
    if (colaVacia(c) == -1) {
        return -1;
    }

    new = malloc(sizeof(tipoCelda));
    if (new == NULL) {
        return -2;
    }
    new->sig = NULL;
    new->elemento = elemento;
    if (c->frente == NULL) {
        
        c->frente   = new;
        c->fondo    = new;

    } else
    {
        c->fondo->sig   = new;
        c->fondo        = new;
    }
    
    return 0;
    
}

tipoElemento colaSuprime(Cola *c)
{
    tipoCelda *delete;
    tipoElemento aux;
    if (c->frente != NULL) {
        delete = c->frente;
        aux = delete->elemento;
        c->frente = c->frente->sig;
        free(delete);
    }

    if (c->frente == NULL) {
        c->fondo = NULL;
        aux = 0;
    }
    return aux;
}
