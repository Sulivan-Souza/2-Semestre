// criar um programa com struct e um menu de incluir e Listar

#include <stdio.h>// biblioteca de entrada e saida de dados
#include <string.h>//biblioteca manipulacao texto para usar
#include <windows.h>// biblioteca dos codigos cmd
#include <ctype.h>



struct molde_pessoa{
char nome[30];
int idade;
float salario;
};
struct molde_pessoa pessoa[3];//quantidade de entradas,caso mude ,mudar tbm no for da opcao 1 e 2



main(){

    int indice,i;
    int continuar = 1;
    int op,opcao;
    char buffer[1024];

    while(continuar != 0){
        system("cls");

        printf("            |----------------- #####   MENU   #####------------------|\n");
        printf("            |                                                        |\n");
        printf("            |                   1  -  Incluir  -  1                  |\n");
        printf("            |                                                        |\n");
        printf("            |                   2  -  Listar   -  2                  |\n");
        printf("            |                                                        |\n");
        printf("            |                   3  -  Creditos -  3                  |\n");
        printf("            |                                                        |\n");
        printf("            |                   4  -  Sair     -  4                  |\n");
        printf("            |--------------------------------------------------------|\n\n");

        printf("\n                      Escolha uma opcao para continuar:\n\n  ");

        scanf("%d", &op);
     
        if(op == 1){
            system("cls");
            printf("--  OPCAO INCLUIR  --\n\n");
            /*  programa da opcao 1 aqui */
            for(indice = 0;indice < 3; indice++){
                system("cls");

                int nome_valido = 0, idade_valida = 0, salario_valido = 0;
                while(!nome_valido){
                    printf("Digite o nome da pessoa %s: ", indice+1);
                    fgets(buffer, 1024, stdin);
                    sscanf(buffer, "%29[^\n]", pessoa[indice].nome);

                    nome_valido = 1;
                    for (i = 0; pessoa[indice].nome[i]; i++){
                        if (!isalpha(pessoa[indice].nome[i]) && !isspace(pessoa[indice].nome[i])){
                            printf("Erro: O nome deve conter apenas letras e espacos.\n");
                            nome_valido = 0;
                            break;
                        }
                    }
                }
                while (!idade_valida){
                    printf("Digite a idade da pessoa %d: ", indice+1);
                    fgets(buffer, 1024, stdin);
                    if (sscanf(buffer, "%d", &pessoa[indice].idade) != 1 || pessoa[indice].idade <= 0){
                        printf("Erro: A idade deve ser um numero inteiro.\n");
                    } else {
                        idade_valida = 1;
                    }
                }
                while (!salario_valido){
                    printf("Digite o salario da pessoa %d: ", indice+1);
                    fgets(buffer, 1024, stdin);
                    if (sscanf(buffer, "%f", &pessoa[indice].salario) != 1 || pessoa[indice].salario <= 0){
                        printf("Erro: O salario deve ser um numero real.\n");
                    } else {
                        salario_valido = 1;
                    }
                }             
            }
            system("cls");
            printf("Digite uma tecla para continuar");
            getch();
        } else if(op == 2){
            system("cls");
            printf("\n  --  OPCAO LISTAR  --\n\n");
            /*  programa da opcao 2 aqui */
            printf("| %-10s | %-30s | %10s | %10s |\n ","Num","Nome","Idade","Salario" );
                for(indice = 0; indice < 3; indice++){
                    
                printf("\n| %5i | %-30s | %10i | %10.2f |",(indice+1), pessoa[indice].nome, pessoa[indice].idade,
				pessoa[indice].salario);
            }
            printf("\nDigite uma tecla para continuar\n");
            getch();

        } else if (op == 3){
            system("cls");
        

        } else if (op == 4){ /*  programa de saida aqui */           
            system("cls");                    
            printf("\n\nVoce deseja sair do programa? (1 - Sim / 2 - Nao): ");            
            scanf("%i", &opcao);
            if(opcao == 2){
                continuar = 1;
            } else {
                system("cls");
                printf("Obrigado por usar o programa");
                Sleep(2000);
               exit(0);
            }             
           
        }
    }
}