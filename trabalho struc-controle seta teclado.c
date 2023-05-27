// criar um menu 

#include <stdio.h>  // biblioteca de entrada e saida de dados
#include <stdlib.h> // biblioteca de conversao das strings
#include <conio.h>  // biblioteca de manipulacao de caracteres
#include <windows.h>// biblioteca dos codigos cmd
#include <string.h> //biblioteca manipulacao texto

/*  MENU */

int indice;
struct molde_pessoa{
char nome[30];
int idade;
float salario;
};
struct molde_pessoa pessoa[3];

char resposta;
int a,b,L,L2; // declaracao das variaveis
void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int main(){
    /*//menu*/
    int opcao;
    do{
        inicio:
        opcao=0;
        L=2;L2=2;b=2;
        system("cls"); // limpar a tela dos comandos anteriores
        system("color 0f"); // Cor de fundo e letra cmd
        printf(" |--------########    MENU    ########-----------|");
        printf("\n\n      1 - INCLUIR \n      2 - LISTAR \n      3 - CREDITOS \n      4 - SAIR\n");
        printf(" |-----------------------------------------------|\n");
        do{
            gotoxy(1,L);
            printf("-->");
            gotoxy(10,6);
            if(kbhit){a=getch();}
            if(a == 80 && b < 5){L2=L;L++;b++;}/*seta p/baixo*/
            if(a == 72 && b > 2){L2=L;L--;b--;}/*seta p/cima */
            if(L!=L2){gotoxy(1,L2);printf("   ");L2=L;}
            if(a == 13){opcao=b-1;}
        }while(opcao == 0);
        
        switch (opcao){
            case 1:
                system("cls");
                printf("\n    INCLUIR\n\n");
                for (indice = 0;indice < 10; indice ++){
                    printf("Digite o nome: ");
                    scanf("%s", &pessoa[indice].nome);
                    printf("Digite a idade: ");
                    scanf("%i", &pessoa[indice].idade);
                    printf("Digite o salario: ");
                    scanf("%f", &pessoa[indice].salario);
                    
                }
                printf("Digite uma tecla para continuar");
                getch();
                break;
            case 2:
                system("cls");
                printf("\n    LISTAR\n\n");
                printf("| %-30s | %10s | %10s |\n ","Nome","Idade","Salario" );
                for(indice = 0; indice < 10; indice++){
                    
                printf("\n| %-30s | %10i | %10.2f |\n", pessoa[indice].nome, pessoa[indice].idade,
				pessoa[indice].salario);
            }
            printf("digite uma tecla para continuar");
            getch();
                break;
            case 3:
                system("cls");
                printf("\n    Creditos\n");
        printf("            |-----------------------------------------------------------|\n");
        printf("            |                                                           |\n");
        printf("            |             ####   Desenvolvido por   #####               |\n");
        printf("            |                                                           |\n");
        printf("            |                      SULIVAN SOUZA                        |\n");
        printf("            |                                                           |\n");
        printf("            |           TRABALHO LABORATORIO AMBIENTES DE REDES         |\n");
        printf("            |                                                           |\n");
        printf("            |                          2023                             |\n");
        printf("            |-----------------------------------------------------------|\n\n");
                Sleep(3000);
                break;
            case 4:
                system("cls");
                printf("voce Deseja sair do programa ?  ( s / n )\n");
                char resposta;
                scanf("%c", &resposta);
                if (resposta == 's' || resposta == 'S'){
                    printf("Obrigado por usar o programa\n");
                    Sleep(2000);
                    exit(0);
                }
                else{
                    goto inicio;
                }
                break;
            default:
                printf("voce deve escolher uma opcao valida\n");
                printf("Precione qualquer tecla para voltar ao menu\n");
                getch();
                
        }
    }while(opcao!=4);
   
}