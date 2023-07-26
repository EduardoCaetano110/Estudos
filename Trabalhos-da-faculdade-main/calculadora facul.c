#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
   

    double x;
    double y;
    int opcao;

    printf("Qual tipo de cálculo você gostaria de fazer?\n");
    printf("-> Escolha uma opção:\n");
        printf("1 - Soma\n");
        printf("2 - Subtração\n");
        printf("3 - Divisão\n");
        printf("4 - Multiplicação\n");
        scanf("%d", &opcao);

    printf("Digite o primeiro número: \n");
    scanf("%lf", &x);

    printf("Digite o segundo número: \n");
    scanf("%lf", &y);

    switch (opcao) {
        case 1:
            printf("O resultado de %.2lf + %.2lf é igual a %.2lf\n", x, y, x + y);
            break;
        case 2:
            printf("O resultado de %.2lf - %.2lf é igual a %.2lf\n", x, y, x - y);
            break;
        case 3:
            if (y != 0) {
                printf("O resultado de %.2lf / %.2lf é igual a %.2lf\n", x, y, x / y);
            } else {
                printf("Não é possível dividir por zero.\n");
            }
            break;
        case 4:
            printf("O resultado de %.2lf * %.2lf é igual a %.2lf\n", x, y, x * y);
            break;
        default:
            printf("Opção inválida.\n");
    }

    return 0;
}