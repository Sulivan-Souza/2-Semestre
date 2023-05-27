#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct modelo_pessoa
{
    char nome[30];
    int idade;
    float salario;
};

struct modelo_pessoa pessoa[3];
int indice = 0;

int salvarRegistros()
{
    FILE *arquivo = fopen("registro.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    for (int i = 0; i < indice; i++)
    {
        fprintf(arquivo, "%s %d %.2f\n", pessoa[i].nome, pessoa[i].idade, pessoa[i].salario);
    }

    fclose(arquivo);
    printf("Registros salvos com sucesso!\n");
    return 1;
}

int carregarRegistros()
{
    FILE *arquivo = fopen("registro.txt", "r");
    if (arquivo == NULL)
    {
        printf("Nenhum registro encontrado!\n");
        return 0;
    }

    while (fscanf(arquivo, "%s %d %f\n", pessoa[indice].nome, &pessoa[indice].idade, &pessoa[indice].salario) == 3)
    {
        indice++;
        if (indice >= 3)
            break;
    }

    fclose(arquivo);
    printf("Arquivos carregados com sucesso!\n");
    return 1;
}

int validarSalario(float salario)
{
    if (salario <= 0)
    {
        printf("Salario invalido. Digite um valor positivo maior que zero.\n");
        return 0;
    }
    return 1;
}

int main()
{
    int opcao, continuar = 1, alterar = 0, i;

    carregarRegistros();

    while (continuar != 0)
    {
        system("cls");
        printf(" -- MENU PRINCIPAL --\n\n");
        printf("     1 - INCLUIR \n");
        printf("     2 - LISTAR \n");
        printf("     3 - ALTERAR \n");
        printf("     4 - EXCLUIR \n");
        printf("     5 - SALVAR \n");
        printf("     6 - SAIR\n\n");
        printf("  ESCOLHA UMA OPCAO: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            system("cls");
            printf("-- INCLUIR REGISTRO --\n\n");
            if (indice < 3)
            {
                printf("PESSOA %i \n\n", (indice + 1));
                printf("Digite o nome da pessoa: ");
                scanf("%s", pessoa[indice].nome);
                printf("\nDigite a idade da pessoa: ");
                scanf("%i", &pessoa[indice].idade);
                printf("\nDigite o salario da pessoa: ");
                scanf("%f", &pessoa[indice].salario);

                if (!validarSalario(pessoa[indice].salario))
                {
                    printf("\nDigite uma tecla para continuar");
                    getch();
                    continue;
                }

                indice++;
                printf("\nPessoa adicionada com sucesso!\n");
                printf("\nDigite uma tecla para continuar");
                getch();
            }
            else
            {
                printf("Nao e possivel adicionar mais pessoas\n\n");
                printf("Digite uma tecla para continuar\n");
                getch();
            }
        }
        else if (opcao == 2)
        {
            system("cls");
            printf("-- LISTAR REGISTRO --\n\n");
            if (indice == 0)
            {
                printf("Nao existe arquivo de pessoas\n\n");
                printf("Digite uma tecla para retornar");
                getch();
            }
            else
            {
                printf("| %-10s |%-30s | %10s | %10s |\n", "Num", "Nome", "Idade", "Salario");
                for (i = 0; i < indice; i++)
                {
                    printf("| %-10i |%-30s | %10i | %10.2f |\n", (i + 1), pessoa[i].nome, pessoa[i].idade, pessoa[i].salario);
                }
                printf("\nDigite uma tecla para continuar");
                getch();
            }
        }
        else if (opcao == 3)
        {
            system("cls");
            printf("-- ALTERAR REGISTRO--\n\n");
            if (indice == 0)
            {
                printf("Nao ha arquivos para alteracao\n\n");
                printf("Pressione uma tecla para continuar");
                getch();
            }
            else
            {
                printf("Qual entrada voce quer alterar: ");
                scanf("%i", &alterar);
                if (alterar > 0 && alterar <= indice)
                {
                    alterar--;

                    printf("|%-30s | %10i | %10.2f |\n", pessoa[alterar].nome, pessoa[alterar].idade, pessoa[alterar].salario);
                    printf("\nDigite o nome da pessoa: ");
                    scanf("%s", pessoa[alterar].nome);
                    printf("\nDigite a idade da pessoa: ");
                    scanf("%i", &pessoa[alterar].idade);
                    printf("\nDigite o salario da pessoa: ");
                    scanf("%f", &pessoa[alterar].salario);

                    if (!validarSalario(pessoa[alterar].salario))
                    {
                        printf("\nDigite uma tecla para continuar");
                        getch();
                        continue;
                    }

                    printf("\n\nPessoa alterada com sucesso!\n");
                    printf("\nDigite uma tecla para continuar");
                    getch();
                }
                else
                {
                    printf("Entrada nao encontrada...");
                    printf("Digite uma tecla para voltar ao menu");
                    getch();
                }
            }
        }
        else if (opcao == 4)
        {
            system("cls");
            printf("-- EXCLUIR PESSOAS --\n\n");
            if (indice == 0)
            {
                printf("Nao ha arquivos para exclusao\n\n");
                printf("Digite uma tecla para continuar");
                getch();
            }
            else
            {
                printf("Qual entrada voce quer excluir: ");
                scanf("%i", &alterar);
                if (alterar > 0 && alterar <= indice)
                {
                    alterar--;
                    printf("|%-30s | %10i | %10.2f |\n", pessoa[alterar].nome, pessoa[alterar].idade, pessoa[alterar].salario);
                    printf("\n\nDeseja excluir esta entrada? (1 - Sim / 2 - Nao): ");
                    scanf("%i", &opcao);
                    if (opcao == 1)
                    {
                        for (i = alterar; i < indice - 1; i++)
                        {
                            strcpy(pessoa[i].nome, pessoa[i + 1].nome);
                            pessoa[i].idade = pessoa[i + 1].idade;
                            pessoa[i].salario = pessoa[i + 1].salario;
                        }
                        indice--;
                        printf("\n\nPessoa excluida com sucesso!\n");
                        printf("\nDigite uma tecla para continuar");
                        getch();
                    }
                    else
                    {
                        printf("\n\nNenhum pessoa foi excluida!\n");
                        printf("\nDigite uma tecla para continuar");
                        getch();
                    }
                }
                else
                {
                    printf("Entrada nao encontrada...");
                    printf("\nDigite uma tecla para voltar ao menu");
                    getch();
                }
            }
        }
        else if (opcao == 5)
        {
            system("cls");
            salvarRegistros();
            printf("\nDigite uma tecla para continuar");
            getch();
        }
        else if (opcao == 6)
        {
            continuar = 0;
        }
    }

    return 0;
}

