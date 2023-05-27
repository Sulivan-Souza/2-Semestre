#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10 //tamanho maximo

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Pessoa;

int numPessoas = 0; // usada para controlar quantas pessoas 
Pessoa pessoas[MAX_SIZE];

void incluirPessoa();// funcao incluir pessoas
void listarPessoas();
void ordenarPessoas();
void sair();

int main() {
    int opcao;
    
    do {
        printf("\n               ---------------   OPCAO  INCLUIR-   ----------------  \n\n");

        printf("            |-----------------          MENU       ------------------|\n");
        printf("            |                                                        |\n");
        printf("            |                   1  -  Incluir  -  1                  |\n");
        printf("            |                                                        |\n");
        printf("            |                   2  -  Listar   -  2                  |\n");
        printf("            |                                                        |\n");
        printf("            |                   4  -  Sair     -  4                  |\n");
        printf("            |--------------------------------------------------------|\n\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls");
        
        if (opcao == 1) {
            incluirPessoa();
        } else if (opcao == 2) {
            listarPessoas();
        }  else if (opcao == 4) {
             sair();
        } else {
            printf("Opcao invalida!\n");
        }
    } while (opcao != 4);
    
    return 0;
}

void incluirPessoa() {
    if (numPessoas == MAX_SIZE) {
        printf("Nao e possivel adicionar mais funcionarios!\n");
        return;
    }
    
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]", pessoas[numPessoas].nome); //  %[^\n] para ler sequencia de caracteres,inclui espaçoes em branco
    printf("Digite a idade da pessoa: ");       //  % indica que argumento esta sendo lido, e o [^\n] especifica quais
    scanf("%d", &pessoas[numPessoas].idade);    //  caracteres devem ser lidos,no caso leia todos exeto o de \n proxima linha
    printf("Digite o salario da pessoa: ");
    scanf("%f", &pessoas[numPessoas].salario);
    
    numPessoas++;
    printf("Pessoa adicionado com sucesso!\n");
}

void listarPessoas() {
    ordenarPessoas();
    
    printf("Lista de pessoas:\n");
    for (int i = 0; i < numPessoas; i++) {
        printf("Nome: %s | Idade: %d | Salario: %.2f\n", 
               pessoas[i].nome, pessoas[i].idade, pessoas[i].salario);
    }
}

void ordenarPessoas() {
    Pessoa temp;
    
    for (int i = 0; i < numPessoas; i++) {
        for (int j = i + 1; j < numPessoas; j++) {
            if (strcmp(pessoas[i].nome, pessoas[j].nome) > 0) {//strcmp funcao auxiliar para ordem alfabetica
                temp = pessoas[i];
                pessoas[i] = pessoas[j];
                pessoas[j] = temp;
            }
        }
    }
}

void sair() {
    char opcao;
    
    printf("Deseja realmente sair? (S/N) ");
    scanf(" %c", &opcao);
    
    if (opcao == 'S' || opcao == 's') {
        exit(0);
    }
}