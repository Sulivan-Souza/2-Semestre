#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>// biblioteca para usar o getch
#include <stdlib.h> // Adicionada a biblioteca para usar a função exit()

struct modelo_pessoa
{   
    int num;
    char nome[30];
    int idade;
    float salario;
};

struct modelo_pessoa pessoa[3];
int indice = 0;
//funcao para validar nome
int validarNome(const char *nome)
{
    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (!isalpha(nome[i]))//A função isalpha  Ela é usada para verificar se um caractere é uma letra do alfabeto
            return 0;       //o operador lógico ! (negação) para inverter o resultado da função
    }                       //essa expressão verifica se o caractere não é uma letra do alfabeto
    return 1;
}
//funcao para validar idade
int validarIdade(int idade)
{
    return idade > 0;
}
//funcao para validar salario
int validarSalario(float salario)
{
    if (salario <= 0)
    {
        printf("Salario invalido. Digite um valor positivo maior que zero.\n");
        return 0;
    }
    return 1;
}
//função para salavar registros no arquivo .txt
int salvarRegistros()// A função fopen em C é usada para abrir um arquivo em um determinado modo e associá-lo a um ponteiro do tipo FILE.
{
    FILE  *arquivo = fopen("registro.txt", "w");  //pra abrir  arquivo em modo escrita w .e por ponteiro de arquivo retornado pela funcao fopen na variavel arquivo
    if (arquivo == NULL)                         
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0; // retorna 0 indica erro
    }

    for (int i = 0; i < indice; i++)// escreve dados de cada pessoa no arquivo
    {
        fprintf(arquivo, "%d\t|%s\t|%d\t|%.2f\n", pessoa[i].num,pessoa[i].nome, pessoa[i].idade, pessoa[i].salario);
    }

    //fputs("teste", arquivo);// escreve a string teste no arquivo
    fclose(arquivo);//fecha o arquivo
    printf("Registros salvos com sucesso!\n");
    return 1; // retorna 1 indica sucesso
}

int carregarRegistros()// funcao para carregar registros do arquivo
{
    FILE *arquivo = fopen("registro.txt", "r");//abre o arquivo no modo leitura
    if (arquivo == NULL)
    {
        printf("Nenhum registro encontrado!\n");
        return 0; // retorna 0 para indicar erro
    }

    while (fscanf(arquivo, "%d\t|%s\t|%d\t|%f", &pessoa[indice].num, pessoa[indice].nome, &pessoa[indice].idade, &pessoa[indice].salario) == 4)
    {
        indice++;
        if (indice >= 3)
            break;
    }

    fclose(arquivo);// fecha o arquivo
    printf("arquivos carregados com sucesso!\n");
    return 1; // retorna 1 indica sucesso
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

        /////////////////////INCLUIR////////////////////////////////
        if (opcao == 1)
        {          
            system("cls");
            printf("-- INCLUIR  REGISTRO --\n\n");
            if (indice < 3)
            {   
                pessoa[indice].num = indice + 1;           
                printf("PESSOA %i \n\n", (indice + 1));
                printf("Digite o nome da pessoa : ");
                scanf("%s", pessoa[indice].nome);
                if (!validarNome(pessoa[indice].nome))
                {
                    printf("Nome invalido. Digite apenas caracteres alfabeticos.\n");
                    printf("\nDigite uma tecla para continuar\n");
                    getch();
                    continue;
                }
                printf("\nDigite a idade da pessoa : ");
                scanf("%i", &pessoa[indice].idade);
                if (!validarIdade(pessoa[indice].idade))
                {
                    printf("Idade invalida. Digite apenas numeros positivos.\n");
                    printf("\nDigite uma tecla para continuar\n");
                    getch();
                    continue;
                }
                printf("\nDigite o salario da pessoa: ");
                scanf("%f", &pessoa[indice].salario);
                if (!validarSalario(pessoa[indice].salario))
                {
                    printf("\nDigite uma tecla para continuar\n");
                    getch();
                    continue;
                }
                system("cls"); 
                indice++;
                printf("\n\nPessoa adicionada com sucesso!\n");
                printf("\n\nDigite uma tecla para continuar");
                getch();
            }
            else
            {
                printf(" Nao e possivel adicionar mais pessoas\n\n Pressione uma tecla para continuar : ");
                printf("\nDigite uma tecla para continuar\n");
                getch();
            }
        }
        /////////////////////////LISTAR////////////////
        else if (opcao == 2)
        {
            system("cls");
            printf("-- LISTAR REGISTRO --\n\n");
            if (indice == 0)
            {
                printf(" Nao existe arquivo de pessoas\n\n Pressione uma tecla para retornar : ");
                getch();
            }
            else
            {
                printf("| %-10s |%-30s | %10s | %10s |\n", "Num", "Nome", "Idade", "Salario");
                for (i = 0; i < indice; i++)
                {
                    printf("| %-10i |%-30s | %10i | %10.2f |\n", pessoa[i].num, pessoa[i].nome, pessoa[i].idade, pessoa[i].salario);
                }
                printf("\nDigite uma tecla para continuar\n");
                getch();
            }
        }
        /////////////////////ALTERAR////////////////////////////
        else if (opcao == 3)
        {
            system("cls");
            printf("-- ALTERAR REGISTRO--\n\n");
            if (indice == 0)
            {
                printf(" Nao ha arquivos para alteracao\n\n Pressione uma tecla para continuar:");
                getch();
            }
            else
            {
                printf("Qual entrada voce quer alterar : ");
                scanf("%i", &alterar);
                if (alterar > 0 && alterar <= indice)
                {
                    alterar--;

                    printf("|%-30s | %10i | %10.2f |\n", pessoa[alterar].nome, pessoa[alterar].idade, pessoa[alterar].salario);
                    printf("\nDigite o nome da pessoa :");
                    scanf("%s", pessoa[alterar].nome);
                    if (!validarNome(pessoa[alterar].nome))
                    {
                        printf("Nome invalido. Digite apenas caracteres alfabeticos.\n");
                        printf("\nDigite uma tecla para continuar\n");
                        getch();
                        continue;
                    }
                    printf("\nDigite a idade da pessoa :");
                    scanf("%i", &pessoa[alterar].idade);
                    if (!validarIdade(pessoa[alterar].idade))
                    {
                        printf("Idade invalida. Digite um numero positivo maior que zero.\n");
                        printf("\nDigite uma tecla para continuar\n");
                        getch();
                        continue;
                    }
                    printf("\nDigite o salario da pessoa:");
                    scanf("%f", &pessoa[alterar].salario);
                    if (!validarSalario(pessoa[alterar].salario))
                    {
                        printf("\nDigite uma tecla para continuar\n");
                        getch();
                        continue;
                    }                    
                    printf("\n\nPessoa alterada com sucesso!\n");
                    printf("\n\nDigite uma tecla para continuar");
                    getch();
                }
                else
                {
                    printf(" Entrada nao encontrada...");
                    printf(" Digite uma tecla para voltar ao menu");
                    getch();
                }
            }
        }
        ///////////////////EXCLUIR/////////////////////////
        else if (opcao == 4)
        {
            system("cls");
            printf("-- EXCLUIR PESSOAS --\n\n");
            if (indice == 0)
            {
                printf(" Nao ha arquivos para exclusao\n\n Pressione uma tecla para continuar:");
                getch();
            }
            else
            {
                printf("Qual entrada voce quer excluir : ");
                scanf("%i", &alterar);
                if (alterar > 0 && alterar <= indice)
                {
                    alterar--;
                    printf("|%-30s | %10i | %10.2f |\n", pessoa[alterar].nome, pessoa[alterar].idade, pessoa[alterar].salario);
                    printf("\n\nDeseja excluir esta entrada? (1 - Sim / 2 - Nao): ");
                    scanf("%i", &opcao);
                    if (opcao == 1)
                    {
                        for (i = alterar; i < indice; i++)
                        {
                            strcpy(pessoa[i].nome, pessoa[i + 1].nome);
                            pessoa[i].idade = pessoa[i + 1].idade;
                            pessoa[i].salario = pessoa[i + 1].salario;
                        }
                        indice--;
                        printf("\n\nPessoa excluída com sucesso!\n");
                        printf("\n\nDigite uma tecla para continuar");
                        getch();
                    }
                    else
                    {
                        printf("\n\nPessoa nao excluida!\n");
                        printf("\n\nDigite uma tecla para continuar");
                        getch();
                    }
                }
                else
                {
                    printf("Entrada nao encontrada...");
                    printf("Digite uma tecla para voltar ao menu");
                    getch();
                }
            }
        }
        //////////////////////////SALVAR/////////////////////////////
        else if (opcao == 5)
        {
            system("cls");
            printf("-- SALVAR arquivoS --\n\n");
            if (salvarRegistros() == 1)
            {
                printf("arquivos salvos com sucesso!\n");
            }
            else
            {
                printf("Erro ao salvar os arquivos!\n");
            }
            printf("\n\nDigite uma tecla para continuar");
            getch();
        }
        /////////////////////////SAIR///////////////////////
        else if (opcao == 6)
        {
            int op;
            system("cls");
            printf("-- SAIR --\n\n");
            printf("\n\nVoce deseja sair do programa? (1 - Sim / 2 - Nao): ");
            scanf("%i", &op);
            if (op == 2)
            {
                continuar = 1;
            }
            else
            {
                system("cls");
                printf("Obrigado por usar o programa\n\n");

                if (salvarRegistros() == 1)
                {
                    printf("arquivos salvos com sucesso!\n");
                }
                else
                {
                    printf("Erro ao salvar os arquivos!\n");
                }

                exit(0);
            }
        }
    }
    return 0;
}