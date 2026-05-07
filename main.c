#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#define COLOR_MAGENTA   "\033[0;35m"
#define COLOR_RED       "\033[0;31m"
#define COLOR_GREEN     "\033[0;32m"
#define COLOR_YELLOW    "\033[0;33m"
#define COLOR_BLUE      "\033[0;34m"
#define COLOR_PURPLE    "\033[0;35m"
#define COLOR_CYAN      "\033[0;36m"
#define RESET           "\033[0m"

#define LINHAS 7
#define COLUNAS 50

char tela[LINHAS][COLUNAS];

void limpar() {
    system("clear");
}

void press_enter(){
    printf("Aperte ENTER para prosseguir...\n");
    getchar();
}

void renderizar_caixa() {
    
    int i,j;
    for(i=0; i<LINHAS; i++){
        for(j=0, j<COLUNAS, j++){
            if( i==0 || i < LINHAS-1) tela[i][j]='-';
            else if (j == 0 || j == COLUNAS - 1) tela[i][j] = '|';
            else tela[i][j]=' ';
        }
    }
    tela[0][0] = '+';
    tela[0][COLUNAS-1] = '+';
    tela[LINHAS - 1][0] = '+';
    tela[LINHAS - 1][COLUNAS - 1] = '+';

}

void tela_inicial(){

    int op;
    limpar();

    renderizar_caixa();
    printf(COLOR_GREEN "\n\n 1 - Iniciar   0 - Sair\n\n" RESET "Escolha a opção: ");
    scanf("%d",&op);
    limpar();
    if(op){
        printf(COLOR_MAGENTA "\n\nBem-vindo ao jogo\n\n" RESET);
    }else{
        printf(COLOR_RED "\n\nSaindo\n\n" RESET);
    }
    getchar();
    press_enter();
}

int main () {
    limpar();
    printf(COLOR_CYAN);
    printf("+---------------------------------------+\n");
    printf("|                                       |\n");
    printf("|            RPG - THE GAME             |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n\n");
    printf(RESET);
    press_enter();
    tela_inicial();
    return 0;
}