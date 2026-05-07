#include "stdio.h"
#include "stdlib.h"

#define COLOR_MAGENTA "\033[0;35m"
#define COLOR_RED   "\033[0;31m"
#define COLOR_GREEN   "\033[0;32m"
#define RESET "\033[0m"

void tela_inicial(){

    int op;

    system("clear");
    printf(COLOR_GREEN "\n\nEscolha a opção: 1 - Iniciar   0 - Sair\n\n" RESET "Escolha a opção: ");
    scanf("%d",&op);
    system("clear");
    if(op){
        printf(COLOR_MAGENTA "\n\nBem-vindo ao jogo\n\n" RESET);
    }else{
        printf(COLOR_RED "\n\nSaindo\n\n" RESET);
    }
}

int main () {
    tela_inicial();
    getchar();
    return 0;
}