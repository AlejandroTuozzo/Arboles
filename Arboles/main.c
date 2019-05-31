#include<stdio.h>
#include<stdlib.h>

struct Nodo {
    int valor;
    struct Nodo *izq;
    struct Nodo *der;
};

struct Nodo *raiz = NULL;

int existeElemento(int valor)
{
    struct Nodo *nodoIndice = raiz;
    while (nodoIndice != NULL)
    {
        if (valor == nodoIndice->valor)
                return 1;
        else
            if (valor > nodoIndice->valor)
                nodoIndice = nodoIndice->der;
            else
                nodoIndice = nodoIndice->izq;
    }
    return 0;
}

void insertar(int valor)
{
    if (!existeElemento(valor))
    {
        struct Nodo *nuevoNodo;

        nuevoNodo = malloc(sizeof(struct Nodo));
        nuevoNodo->valor = valor;
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
                if (valor < nodoIndice->valor)
                    nodoIndice = nodoIndice->izq;
                else
                    nodoIndice = nodoIndice->der;
            }
            if (valor < nodoAnterior->valor)
                nodoAnterior->izq = nuevoNodo;
            else
                nodoAnterior->der = nuevoNodo;
        }
    }
}

void recorrerPreOrden(struct Nodo *nodoIndice)
{
    if (nodoIndice != NULL)
    {
        printf("%i-", nodoIndice->valor);
        recorrerPreOrden(nodoIndice->izq);
        recorrerPreOrden(nodoIndice->der);
    }
}

void recorrerInOrden(struct Nodo *nodoIndice)
{
    if (nodoIndice != NULL)
    {
        recorrerInOrden(nodoIndice->izq);
        printf("%i-", nodoIndice->valor);
        recorrerInOrden(nodoIndice->der);
    }
}

void recorrerPostOrden(struct Nodo *nodoIndice)
{
    if (nodoIndice != NULL)
    {
        recorrerPostOrden(nodoIndice->izq);
        recorrerPostOrden(nodoIndice->der);
        printf("%i-", nodoIndice->valor);
    }
}

void borrar(struct Nodo *nodoIndice)
{
    if (nodoIndice != NULL)
    {
        borrar(nodoIndice->izq);
        borrar(nodoIndice->der);
        free(nodoIndice);
    }
}

void borrarMinimo(struct Nodo *raiz)
{
     if (raiz != NULL) {
         struct Nodo *nodoBorrar;
         if (raiz->izq == NULL)
         {
             nodoBorrar = raiz;
             raiz = raiz->der;
             free(nodoBorrar);
         }
         else {
             struct Nodo *nodoAnterior = raiz;
             struct Nodo *nodoIndice = raiz->izq;
             while (nodoIndice->izq != NULL)
             {
                 nodoAnterior = nodoIndice;
                 nodoIndice = nodoIndice->izq;
             }
             nodoAnterior->izq = nodoIndice->der;
             free(nodoIndice);
         }
     }
 }

/*struct Nodo BorrarElemento(int elemento, struct Nodo *raiz)
{
	//if(raiz == NULL)
	//	throw new ItemNotFoundException(x.toString());

	if (elemento < raiz->valor)
		raiz->izq = BorrarElemento(elemento, raiz->izq);
	else if(elemento > raiz->valor)
		raiz->der = BorrarElemento(elemento, raiz->der);
	else if(raiz->izq != NULL && raiz->der != NULL) //Nodo con dos hijos
	{
		raiz->valor = buscarMinimo(raiz->der)->valor;
		raiz->der = borrarMinimo(raiz->der);
	}
	else
		if (raiz->izq != NULL)
            raiz = raiz->izq;
		else
            raiz = raiz->der;

	return raiz;
}*/

int main()
{
    return 0;
}
