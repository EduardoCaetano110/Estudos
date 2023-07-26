#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void main(){
// Configuração da página de código UTF-8
    unsigned int CPAGE_UTF8 = 65001;
    unsigned int CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int numIni = 0;
    int numFinal = 0;
    int quantidadeTotalDePar = 0;

          //Local de por os números. 

    printf("Digite um número inicial: ");
    scanf("%d", &numIni);

    printf("Digite um número Final: ");
    scanf("%d", &numFinal);

// Para evitar bugs.
    if (numFinal < numIni ){
        numIni= 0;
        numFinal= 0;
        printf("Não foi possivel realizar essa tarefa.");
    }
        
        for (int i = numIni; i <= numFinal; i++ ){
        
            if( i % 2 == 0){
                printf("o valor do número -> %d é par! \n", i);
                quantidadeTotalDePar++;

            }else {
                printf("o valor do número -> %d é impar! \n", i);
            }
        }
        printf("O total de pares é: %d\n", quantidadeTotalDePar); 

        
}