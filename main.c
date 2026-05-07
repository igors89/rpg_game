#include "stdio.h"
#include "stdlib.h"

#define COLOR_MAGENTA   "\033[0;35m"
#define COLOR_RED       "\033[0;31m"
#define COLOR_GREEN     "\033[0;32m"
#define COLOR_YELLOW    "\033[0;33m"
#define COLOR_BLUE      "\033[0;34m"
#define COLOR_PURPLE    "\033[0;35m"
#define COLOR_CYAN      "\033[0;36m"
#define RESET           "\033[0m"

void limpar() {
    system("clear");
}

void tela_inicial(){

    int op;
    limpar();

    printf(COLOR_GREEN "\n\nEscolha a opção: 1 - Iniciar   0 - Sair\n\n" RESET "Escolha a opção: ");
    scanf("%d",&op);
    limpar();
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