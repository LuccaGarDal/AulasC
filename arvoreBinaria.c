#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* esquerda;
    struct Nodo* direita;
} Nodo;

//Cria nós
Nodo* criarNodo(int valor) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

//Inclui nós dentro da árvore
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

//Encontra o menor valor da subárvore
Nodo* encontrarMinimo(Nodo* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

//Remove nós da árvore
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

//Exibe nós em pré-ordem (raiz -> esquerda -> direita)
void preOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

//Exibe nós em ordem (esquerda -> raiz -> direita)
void emOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

//Exibe nós em pós-ordem (esquerda -> direita -> raiz)
void posOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

int main () {
    int opcao = 1;
    Nodo* raiz = NULL;
    int valor;
    int option;
    while (opcao != 0)
    {
        printf("\n***MENU DE OPÇÕES***\n");
        printf("1 - Incluir nó.\n");
        printf("2 - Remover nó.\n");
        printf("3 - Buscar pré-ordem.\n");
        printf("4 - Buscar em ordem. \n");
        printf("5 - Buscar pós-ordem.\n");
        printf("0 - Sair do menu.\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite o valor do nó que deseja incluir: ");
                scanf("%d", &valor);
                raiz = incluir(raiz, valor);
                printf("Nó incluído na árvore!\n");

                printf("Continuar?\n");
                printf("1 - Sim\n");
                printf("2 - Não\n");
                scanf("%d", &option);

                if (option == 2)
                {
                    printf("Encerrando o programa...\n");
                    opcao = 0;
                }
                break;
                
            case 2:
                printf("Digite o valor do nó que deseja remover: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                printf("Nó removido da árvore!\n");

                printf("Continuar?\n");
                printf("1 - Sim\n");
                printf("2 - Não\n");
                scanf("%d", &option);
                
                if (option == 2)
                {
                    printf("Encerrando o programa...\n");
                    opcao = 0;
                }
                break;
            case 3:
                printf("***Pré-ordem***\n");
                preOrdem(raiz);
                printf("\n");

                printf("Continuar?\n");
                printf("1 - Sim\n");
                printf("2 - Não\n");
                scanf("%d", &option);
                
                if (option == 2)
                {
                    printf("Encerrando o programa...\n");
                    opcao = 0;
                }
                break;
            case 4:
                printf("***Em ordem***\n");
                emOrdem(raiz);
                printf("\n");

                printf("Continuar?\n");
                printf("1 - Sim\n");
                printf("2 - Não\n");
                scanf("%d", &option);
                
               if (option == 2)
                {
                    printf("Encerrando o programa...\n");
                    opcao = 0;
                }
                break;
            case 5:
                printf("***Pós-ordem***\n");
                posOrdem(raiz);
                printf("\n");

                printf("Continuar?\n");
                printf("1 - Sim\n");
                printf("2 - Não\n");
                scanf("%d", &option);
                
                if (option == 2)
                {
                    printf("Encerrando o programa...\n");
                    opcao = 0;
                }
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    }
    return 0;
    
}