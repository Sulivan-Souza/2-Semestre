#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


main(){

    int indice;
    struct molde_pessoa{
    char nome[30];
    int idade;
    float salario;
};

struct molde_pessoa[10];

int op = 1;
int indice = 0;

    while(op != 0){
        system("cls");

    printf("            |-----------------------------------------------------------|\n");
    printf("            |                                                           |\n");
    printf("            |                     ####   MENU   #####                   |\n");
    printf("            |                                                           |\n");
    printf("            |                      1  -  Incluir  -  1                  |\n");
    printf("            |                                                           |\n");
    printf("            |                      2  -  Listar   -  2                  |\n");
    printf("            |                                                           |\n");
    printf("            |                      0  -  Sair     -  0                  |\n");
    printf("            |                                                           |\n");
    printf("            |-----------------------------------------------------------|\n\n");

        printf("\nDigite 0 para sair\n ou escolha uma opcao para continuar: ");

        scanf("%d", &op);
        if(op == 1){
            system("cls");
            printf("Opcao Incluir\n");
            /*  programa da opcao 1 aqui */
            
for (indice = 0; indice < 10; indice++){
    system("cls");
    printf("pessoa %i \n\n", (indice + 1));
    printf("digite o nome: ");
    scanf("%s", &pessoa[indice].nome);
    printf("digite a idade: ");
    scanf("%i", &pessoa[indice].idade);
    printf("Digite o salario da pessoa");
    scanf("%f", &pessoa[indice].salario);
}


            printf("digite uma tecla para continuar");
            getch();
        } else if(op == 2){
            system("cls");
            printf("Opcao Listar\n");
            /*  programa da opcao 2 aqui */

for(indice = 0; indice < 10; indice++){
        printf("pessoa %i :: nome: %s idade: %i salario: %f\n\n", (indice+1), pessoa[indice].nome, pessoa[indice].idade,
        pessoa[indice].salario);
    }

            printf("digite uma tecla para continuar");
            getch();
        } else if (op == 0){
            system("cls");
            printf("saindo do programa\n");
            /*  programa de saida aqui */
            printf("digite uma tecla para continuar");
            getch();
        } else {
            system("cls");
            printf("opcao invalida\n");
            /*  programa de opcao invalida aqui */
            printf("digite uma tecla para continuar");
            getch();
        }       
    }
}