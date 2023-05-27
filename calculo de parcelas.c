// desenvolva uma função que receba os parametros : total da divida e quantidade de parcelas.
// a função deve calcular e retornar o valor da parcela.
// a função deve retornar -998 caso a quantidade de parcelas seja menor que 0.,
// a função deve retornar -999 caso a total da divida for zero ou negativo.

#include <stdio.h>
#include <stdlib.h>
//função que calcula a parcela e divida
float calculaParcela(float totalDivida, int qtdParcelas)
{    float resutado;
    if(qtdParcelas > 0){
        if(totalDivida > 0){
            resutado = totalDivida / qtdParcelas;
            return resutado;
        }else{
            resutado = -998;
        }
    }else{
        resutado = -999;     
    }
    return resutado;
}
int main()
{
    float totalDivida;
    int qtdParcelas;
    float resultado;

    printf("Digite o total da divida: ");
    scanf("%f", &totalDivida);
    printf("Digite a quantidade de parcelas: ");
    scanf("%d", &qtdParcelas);
    resultado = calculaParcela(totalDivida, qtdParcelas);
    if(resultado == -999){
        printf("Quantidade de parcelas tem que ser maior que zero.\n");
    }else if(resultado == -998){
        printf("Total da divida tem que ser maior que zero.\n");
    }else{
        printf("O valor da parcela e: %.2f\n", resultado);
    }
    return 0;
}


