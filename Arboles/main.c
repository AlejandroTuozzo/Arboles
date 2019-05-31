#include<stdio.h>
#include<stdlib.h>

struct Nodo {
    int valor;
    struct Nodo *izq;
    struct Nodo *der;
};

struct Nodo *raiz = NULL;

void insertar(int nuevoValor)
{
    struct Nodo *nuevoNodo;

    nuevoNodo = malloc(sizeof(struct Nodo));
    nuevoNodo->valor = nuevoValor;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    if (raiz == NULL)
        raiz = nuevoNodo;
    else
    {
        struct Nodo *nodoAnterior, *nodoIndice;
        nodoAnterior = NULL;
        nodoIndice = raiz;

        while (nodoIndice != NULL)
        {
            nodoAnterior = nodoIndice;
            if (nuevoValor < nodoIndice->valor)
                nodoIndice = nodoIndice->izq;
            else
                nodoIndice = nodoIndice->der;
        }
        if (nuevoValor < nodoAnterior->valor)
            nodoAnterior->izq = nuevoNodo;
        else
            nodoAnterior->der = nuevoNodo;
    }
}

void recorrerPreOrden(struct Nodo *nodoIndice)
{
    if (nodoIndice != NULL)
    {
        printf("%i-",nodoIndice->valor);
        recorrerPreOrden(nodoIndice->izq);
        recorrerPreOrden(nodoIndice->der);
    }
}

void recorrerInOrden(struct Nodo *nodoIndice)
{
    if (nodoIndice != NULL)
    {
        recorrerInOrden(nodoIndice->izq);
        printf("%i-",nodoIndice->valor);
        recorrerInOrden(nodoIndice->der);
    }
}

void recorrerPostOrden(struct Nodo *nodoIndice)
{
    if (nodoIndice != NULL)
    {
        recorrerPostOrden(nodoIndice->izq);
        recorrerPostOrden(nodoIndice->der);
        printf("%i-",nodoIndice->valor);
    }
}

int main()
{
    return 0;
}
