#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo estrutura do nó
typedef struct Nodo {
    int valor;
    struct Nodo* prox;
} Nodo;


// Método para criar nós
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

// Método para inserir nós na cabeça da fila
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

// Método para consultar nós de acordo com o valor
Nodo* consultar(Nodo* inicio, int valor) {
    Nodo* atual = inicio;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}

// Método para imprimir a lista
void imprimir (Nodo* inicio) {
    Nodo * atual = inicio;

    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;   
    }
    printf("NULL\n");
}

// Método para remover um nó da lista
Nodo* deletar (Nodo* inicio, int valor) {
    if (inicio == NULL){
        return NULL;
    }
    Nodo* atual = inicio;
    Nodo* anterior = NULL;

    if (atual->valor == valor){
     Nodo* temp = atual->prox;
     free(atual);   
     return temp;

    }

    while (atual-> valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return inicio; 
    }

    anterior->prox = atual->prox;
    free(atual);
    
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

    Nodo* resultado = consultar(lista, 20);
    printf("Resultado: %d\n", resultado->valor);

    lista = deletar(lista, 20);

    imprimir(lista);

    return 0;
}