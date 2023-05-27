// criar um vetor float de 50 posiçoes, o programa simula uma registradora de mercado,
// primeiro perguntar ao usuario quantos produtos serao digitados, 
//depois receber os valores dos produtos e ao final mostrar o preço a ser pago

#include <stdio.h>

int main(){
    int qtd_produtos;
    float produtos[50], soma = 0;
    int i;

    printf("Digite a quantidade de produtos: ");
    scanf("%i", &qtd_produtos);
    
    if (qtd_produtos > 0  && qtd_produtos < 50){
       for(i = 0; i < qtd_produtos; i++){ 
        printf("Digite o valor do produto %d: ", (i+1));
        scanf("%f", &produtos[i]);
        soma += produtos[i];
        } 
          printf("O valor total a ser pago eh: %.2f\n", soma);
            }else{
            printf("Quantidade de produtos invalida,capacidaqde de 50 produtos\n");
            }      
    }
