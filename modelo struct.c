
main(){
    int indice;

struct molde_pessoa{
char nome[30];
int idade;
float salario;

};
struct molde_pessoa pessoa[3];

for(indice = 0; indice < 3; indice++){
	system("cls");
    printf("pessoa %i \n\n", (indice + 1));
    printf("digite o nome: ");
    scanf("%s", &pessoa[indice].nome);
    printf("digite a idade: ");
    scanf("%i", &pessoa[indice].idade);
    printf("Digite o salario da pessoa");
    scanf("%f", &pessoa[indice].salario);
}


    for(indice = 0; indice < 3; indice++){
        printf("pessoa %i :: nome: %s idade: %i salario: %f\n\n", (indice+1), pessoa[indice].nome, pessoa[indice].idade,
        pessoa[indice].salario);
    }

}