#include <stdio.h>

void main() {

    int opcao;
    float primeiroValor;
    float segundoValor;
    float resultado;

    printf("#-> Digite uma opcao:\n");
    printf("1 - ADICAO\n");
    printf("2 - SUBTRACAO\n");
    printf("3 - DIVISAO\n");
    printf("4 - MULTIPLICACAO\n");
    //Primeiro registra a opcao
    scanf(" %d", &opcao);

    //Depois voce captura os dados
    printf("Informe o primeiro numero: ");
    scanf(" %f", &primeiroValor);
    printf("Informe o segundo numero: ");
    scanf(" %f", &segundoValor);

    //Aqui voce faz a selecao para o tratamento dos dados de acordo a opcao do usuario
    if (opcao == 1) {
        resultado = primeiroValor + segundoValor;
    } else if (opcao == 2) {
        resultado = primeiroValor - segundoValor;
    } else if (opcao == 3) {
        resultado = primeiroValor / segundoValor;
    } else if (opcao == 4) {
        resultado = primeiroValor * segundoValor;
    }

    //Aqui voce exibe a informacao
    //Esse ".2" significa que eu vou querer somente 2 casas apos o ponto.
    //ex : 1."00"
    printf("O resultado e: %.2f", resultado);
}