#include<stdio.h>
#include<conio.h>


main(){

    FILE *arquivo;

    char nome[30];
    int idade;
    float salario;

    int op;

    arquivo = fopen("registro.txt", "w");

    while(op != 0){
        printf("Digite o nome: ");
        scanf("%s", &nome);
        printf("Digite a idade: ");
        scanf("%d", &idade);
        printf("Digite o salario: ");
        scanf("%f", &salario);

        fprintf(arquivo, "%s %d %.2f\n", nome, idade, salario);

        printf("Deseja continuar? 1 - Sim | 0 - Nao\n");
        scanf("%d", &op);
    }

}
