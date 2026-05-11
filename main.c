#include "stdio.h"
#include "stdlib.h"

#ifdef _WIN32
    #include "windows.h"
#else
    #include "unistd.h"
#endif

#define COLOR_MAGENTA   "\033[0;35m"
#define COLOR_RED       "\033[0;31m"
#define COLOR_GREEN     "\033[0;32m"
#define COLOR_YELLOW    "\033[0;33m"
#define COLOR_BLUE      "\033[0;34m"
#define COLOR_PURPLE    "\033[0;35m"
#define COLOR_CYAN      "\033[0;36m"
#define DEFAULT           "\033[0m"

#define LINHAS 7
#define COLUNAS 50

char tela[LINHAS][COLUNAS];
int i,j;

void limpar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void press_enter(){
    printf("Aperte ENTER para prosseguir...\n");
    getchar();
}

void montar_caixa() {
    
    for(i=0; i<LINHAS; i++){
        for(j=0; j<COLUNAS; j++){
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

    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    int op;
    limpar();

    montar_caixa();
    printf(COLOR_GREEN "\n\n 1 - Iniciar   0 - Sair\n\n" DEFAULT "Escolha a opção: ");
    scanf("%d",&op);
    limpar();
    if(op==1){
        printf(COLOR_MAGENTA "\n\nBem-vindo ao jogo\n\n" DEFAULT);
    }else if(op==0){
        printf(COLOR_RED "\n\nSaindo\n\n" DEFAULT);
    }else{
        printf(COLOR_RED "\n\nOpção inválida\n\n" DEFAULT);
    }
    getchar();
    press_enter();
}

int main () {
    limpar();
    printf(COLOR_CYAN);
    char titulo[] = "RPG - THE GAME";
    int centro = sizeof(titulo)/2;
    for(i=0; i<5; i++){
        for(j=0; j<30; j++){
            if( i==0 || i == 4) tela[i][j]='-';
            else if (j == 0 || j == 29) tela[i][j] = '|';
            else tela[i][j]=' ';
        }
    }
    tela[0][0] = '+';
    tela[0][30-1] = '+';
    tela[5 - 1][0] = '+';
    tela[5 - 1][30 - 1] = '+';
    int linha_texto = 2;
    int coluna_inicial = 16-centro;
    for(int k=0; k < sizeof(titulo); k++){
        tela[linha_texto][coluna_inicial+k] = titulo[k];
    }
    for(i=0; i<LINHAS;i++){
        for(j=0;j<COLUNAS;j++){
            printf("%c",tela[i][j]);
        }
        printf("\n");
    }
    printf(DEFAULT);
    press_enter();
    tela_inicial();
    return 0;
}