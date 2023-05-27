

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

int numFuncionarios = 0;
Funcionario funcionarios[MAX_SIZE];

void incluirFuncionario();
void listarFuncionarios();
void ordenarFuncionarios();
void sair();

int main() {
    int opcao;
    
    do {
        printf("\n--- MENU ---\n");
        printf("1. Incluir funcionario\n");
        printf("2. Listar funcionarios\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                incluirFuncionario();
                break;
            case 2:
                listarFuncionarios();
                break;
            case 3:
                sair();
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);
    
    return 0;
}

void incluirFuncionario() {
    if (numFuncionarios == MAX_SIZE) {
        printf("Nao e possivel adicionar mais funcionarios!\n");
        return;
    }
    
    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", funcionarios[numFuncionarios].nome);
    printf("Digite a idade do funcionario: ");
    scanf("%d", &funcionarios[numFuncionarios].idade);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionarios[numFuncionarios].salario);
    
    numFuncionarios++;
    printf("Funcionario adicionado com sucesso!\n");
}

void listarFuncionarios() {
    ordenarFuncionarios();
    
    printf("Lista de funcionarios:\n");
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Nome: %s | Idade: %d | Salario: %.2f\n", 
               funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].salario);
    }
}

void ordenarFuncionarios() {
    Funcionario temp;
    
    for (int i = 0; i < numFuncionarios; i++) {
        for (int j = i + 1; j < numFuncionarios; j++) {
            if (strcmp(funcionarios[i].nome, funcionarios[j].nome) > 0) {
                temp = funcionarios[i];
                funcionarios[i] = funcionarios[j];
                funcionarios[j] = temp;
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