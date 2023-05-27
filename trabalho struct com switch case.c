

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_SIZE 3

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Pessoa;

int numPessoas = 0;
Pessoa pessoas[MAX_SIZE];

void incluirPessoa();
void listarPessoa();
void ordenarPessoa();
int sair();

int main() {
    int opcao ;
    
    do {
        printf("\n--- MENU ---\n");
        printf("\n1. Incluir pessoas\n");
        printf("\n2. Listar pessoas\n");
        printf("\n3. Sair\n");
        
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls");
        
        switch (opcao) {
            case 1:
                incluirPessoa();
                break;
            case 2:
                listarPessoa();
                break;
            case 3:
                if(sair()){
                    printf("\nEncerrando o programa\nObrigado");
                   
                return 0;
                }
                break;
            
            default:
                printf("Opcao invalida!\n");
        }
    } while (1);
    
    
}

void incluirPessoa() {
    if (numPessoas == MAX_SIZE) {
        printf("Nao e possivel adicionar mais pessoas!\n");
        return;
    }
    
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]", pessoas[numPessoas].nome);
    printf("\nDigite a idade da pessoa: ");
    scanf("%d", &pessoas[numPessoas].idade);
    printf("\nDigite o salario da pessoa: ");
    scanf("%f", &pessoas[numPessoas].salario);
    
    numPessoas++;
    system("cls");
    printf("\n\nPessoa adicionado com sucesso!\n");
    printf("\n\nDigite uma tecla para continuar");
    getch();
    system("cls");
}

void listarPessoa() {
    ordenarPessoa();
    
    printf("Lista de pessoas:\n");
    for (int i = 0; i < numPessoas; i++) {
        printf("\nNome: %s | Idade: %d | Salario: %.2f\n", 
               pessoas[i].nome, pessoas[i].idade, pessoas[i].salario);
    }
    printf("\n\nClique em uma tecla para continuar");
    getch();
    system("cls");
}

void ordenarPessoa() {
    Pessoa temp;
    
    for (int i = 0; i < numPessoas; i++) {
        for (int j = i + 1; j < numPessoas; j++) {
            if (strcmp(pessoas[i].nome, pessoas[j].nome) > 0) {
                temp = pessoas[i];
                pessoas[i] = pessoas[j];
                pessoas[j] = temp;
            }
        }
    }
}

int sair() {
    char opcao;
    
    printf("Deseja realmente sair? (S/N) ");
    scanf(" %c", &opcao);
    
    if (opcao == 'S' || opcao == 's') {
       return 1;
    }

    else {
        return 0;
    }
    
}