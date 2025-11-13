#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    int valor;
    struct Nodo* prox;
} Nodo;

Nodo* criarNodo (int x) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo == NULL)
    {
        printf("Erro de alocação");
        exit(1);
    }
    novo->valor = x;
    novo->prox = NULL;
    return novo;
    
}

Nodo* inserir (Nodo* inicio, int valor) {
    Nodo* novo = criarNodo(valor);
    if(inicio == NULL) {
        return novo;
    }

    Nodo* atual = inicio;
    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }
    atual->prox = novo;
    return inicio;
    
}

int main () {
    Nodo* lista = NULL;

    lista = inserir(lista, 10);
    printf("Inseriu 10\n");

    lista = inserir(lista, 20);
    printf("Inseriu 20\n");

    lista = inserir(lista, 30);
    printf("Inseriu 30\n");

    return 0;
}