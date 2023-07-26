#include <stdio.h>

void main(){
//Primeiro [3] = Linha.
//Segundo [3] = Coluna.
int matriz3x3 [3] [3]= {{1, 6, 9},
                        {5 , 2, 4},
                        {7 ,0 ,1}};


for(int i = 0; i < 3;i++){
    printf("|");
    for(int j = 0; j < 3; j++){
        //Multiplicação dela por 5.
        matriz3x3[i][j] *= 5;
        printf(" %i", matriz3x3[i] [j]);
        }
    printf("|\n");

}
}