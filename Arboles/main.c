#include<stdio.h>
#include<stdlib.h>

struct Nodo {
    int valor;
    struct Nodo *izq;
    struct Nodo *der;
};

struct Nodo *raiz = NULL;

//Busca si el elemento existe partiendo desde el nodo pasado por parámetro
int existeElemento(int valor, struct Nodo *nodoIndice)
{
    if (nodoIndice == NULL)
        nodoIndice = raiz;

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

//Inserta un valor ordenado
void insertar(int valor)
{
    if (!existeElemento(valor, raiz))
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
    else
        printf("El elemento ya existe!");
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

//Borra todo partiendo de un Nodo determinado hacia sus hijos
void borrar(struct Nodo *nodoIndice)
{
    if (nodoIndice != NULL)
    {
        borrar(nodoIndice->izq);
        borrar(nodoIndice->der);
        free(nodoIndice);
    }
}

//Borra el elemento más chico desde el nodo pasado por parámetro
struct Nodo* borrarMinimo(struct Nodo *nodo)
{
     if (nodo != NULL) {
         struct Nodo *nodoBorrar;
         if (nodo->izq == NULL)
         {
             nodoBorrar = nodo;
             nodo = nodo->der;
             free(nodoBorrar);
         }
         else {
             struct Nodo *nodoAnterior = nodo;
             struct Nodo *nodoIndice = nodo->izq;
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

 //Busca el mímimo elemento partiendo de un Nodo
struct Nodo* buscarMinimo(struct Nodo *nodo)
{
    if(nodo != NULL)
        while(nodo->izq != NULL)
            nodo = nodo->der;

    return nodo;
}

//Borra un elemento partiendo de un Nodo
struct Nodo* BorrarElemento(int elemento, struct Nodo *nodo)
{
    if (nodo == NULL)
        nodo = raiz;

    if (!existeElemento(elemento, NULL))
		printf("No se encontró el valor!");

	if (elemento < nodo->valor)
		nodo->izq = BorrarElemento(elemento, nodo->izq);
	else if(elemento > nodo->valor)
		nodo->der = BorrarElemento(elemento, nodo->der);
	else if(nodo->izq != NULL && nodo->der != NULL) //Nodo con dos hijos
	{
		nodo->valor = buscarMinimo(nodo->der)->valor;
		nodo->der = borrarMinimo(nodo->der);
	}
	else
		if (nodo->izq != NULL)
            nodo = nodo->izq;
		else
            nodo = nodo->der;

	return nodo;
}

int main()
{
    return 0;
}
