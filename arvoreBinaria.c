#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* esquerda;
    struct Nodo* direita;
} Nodo;

Nodo* criarNodo(int valor) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

Nodo* incluir(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return criarNodo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = incluir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = incluir(raiz->direita, valor);
    }

    return raiz;
}

Nodo* encontrarMinimo(Nodo* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

Nodo* remover(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    }
    else {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }
        else if (raiz->esquerda == NULL) {
            Nodo* temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL) {
            Nodo* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        Nodo* temp = encontrarMinimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }

    return raiz;
}

void preOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

void posOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

int main () {
    
}