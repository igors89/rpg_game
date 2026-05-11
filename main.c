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

// #define LINHAS 7
// #define COLUNAS 50

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

void renderizar_caixa(int linhas, int colunas) {
    
    char tela[linhas][colunas];
    int i,j;

    printf("linhas = %d colunas = %d\n\n",linhas, colunas);
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            if( i==0 || i < linhas-1) tela[i][j]='-';
            else if (j == 0 || j == colunas - 1) tela[i][j] = '|';
            else tela[i][j]=' ';
        }
    }
    tela[0][0] = '+';
    tela[0][colunas-1] = '+';
    tela[linhas - 1][0] = '+';
    tela[linhas - 1][colunas - 1] = '+';

    // int centro = sizeof(texto)/2;
    // int linha_texto = 2;
    // int coluna_inicial = (colunas/2)-centro;
    // for(int k=0; k < centro*2; k++){
    //     tela[linha_texto][coluna_inicial+k] = texto[k];
    // }
    for(i=0; i<linhas;i++){
        for(j=0;j<colunas;j++){
            printf("%c",tela[i][j]);
        }
        printf("\n");
    }

}

void tela_inicial(){

    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    int op;
    limpar();

    // montar_caixa();
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
    renderizar_caixa(5,30);
    printf(DEFAULT);
    press_enter();
    tela_inicial();
    return 0;
}