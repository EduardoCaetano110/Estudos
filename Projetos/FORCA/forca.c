#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>

//Variaveis globais
	char chutes[26];
	int chutesdados = 0;
	char palavrasecreta[TAMANHO_PALAVRA];
	void adicionapalavra();


void abertura() {
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta() {
	char chute;
	scanf(" %c", &chute);

	chutes[chutesdados] = chute;
	chutesdados++;
}



void desenhaforca() {

int erros = chuteserrados();


printf("  _______       \n");
printf(" |/      |      \n");
printf(" |      %c%c%c  \n", (erros>=1?'(':' '), 
    (erros>=1?'_':' '), (erros>=1?')':' '));
printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), 
    (erros>=2?'|':' '), (erros>=3?'/': ' '));
printf(" |       %c     \n", (erros>=2?'|':' '));
printf(" |      %c %c   \n", (erros>=4?'/':' '), 
    (erros>=4?'\\':' '));
printf(" |              \n");
printf("_|___           \n");

		printf("\n\n");

	printf("Você já deu %d chutes\n", chutesdados);

	for(int i = 0; i < strlen(palavrasecreta); i++) {

		if(jachutou(palavrasecreta[i])) {
			printf("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}

	}
	printf("\n");

}
void adicionapalavra() {
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);

    if(quer == 'S') {
        char novapalavra[20];

        printf("Digite a nova palavra, em letras maiúsculas: ");
        scanf("%s", novapalavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");
        if(f == 0) {
            printf("Banco de dados de palavras não disponível\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);

    }

}


void escolhepalavra() {
	FILE* f;
	f = fopen("palavras.txt", "r");
	if(f == 0){
		printf("Desculpe, banco de dados não disponível\n\n");
		exit(1);
	}

	srand(time(0));
	int qtdpalavra;
	fscanf(f, "%d", &qtdpalavra);

	int randomico = rand() % qtdpalavra;

		for(int i = 0; i <= randomico; i++){
			fscanf(f, "%s", palavrasecreta);
		}

	fclose(f);
}

 int acertou() {
	for(int i=0; i < strlen(palavrasecreta);i++) {
		if(!jachutou(palavrasecreta[i])){
			return 0;
		}
	}
	return 1;
 }
int chuteserrados(){
	int erros = 0;

	for(int i=0; i< chutesdados;i++) {
		int existe = 0;

		for (int j = 0; j < strlen(palavrasecreta); j++){
			if(chutes[i] == palavrasecreta[j]){
				existe = 1;
				break;
			}
			
		}
		if (!existe) erros++;
	}
	return erros;
}
int enforcou(){
	return chuteserrados() >= 5;
}

int jachutou(char letra) {
	int achou = 0;
	for(int j = 0; j < chutesdados; j++) {
		if(chutes[j] == letra) {
			achou = 1;
			break;
		}
	}

	return achou;
}

int main() {
	

	// Configuração da página de código UTF-8
    unsigned int CPAGE_UTF8 = 65001;
    unsigned int CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

	abertura();
	escolhepalavra();

	do {

		desenhaforca();
		chuta();

	} while (!acertou() && !enforcou());

	if(acertou()){
		printf("VOCÊ GANHOU!");
	}else {
		printf("VOCÊ  PERDEU!");
	}

}