#include <stdio.h>

#define texto "Meu nome é Lucca."

int main() {
    printf("%s\n", texto);

    int idade = 0;
    float altura = 0.0;
    char nome [50] = "";

    printf("Digite a sua idade: ");
    scanf("%d", &idade);
    printf("Digite a sua altura: ");
    scanf("%f", &altura);
    printf("Digite o seu nome: ");
    scanf("%s", &nome);

    printf("O seu nome é %s.\n ", nome);
    printf("A sua idade é %d.\n ", idade);
    printf("A sua altura é %.2f.\n", altura);

}