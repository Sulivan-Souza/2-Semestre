// desenvolver uma funcao que calcule o consumo, para isso deve receber qts km percorrer e qts litros foram usados
// para percorrer. ao final dividir o primeiro parametro pelo segundo.
// tratar : -999 qdo km percorridos for menor ou igual a 0
//          -998 qdo a qtd de litros for menor ou igual a 0.



#include <stdio.h>
#include <stdlib.h>

float consumo(float km, float litros){
    if(km <= 0){
        return -999;
    }
    if(litros <= 0){
        return -998;
    }
    return km / litros;
}

int main()

{
    float km, litros;
    printf("Digite a qtd de km percorridos: ");
    scanf("%f", &km);
    printf("Digite a qtd de litros usados: ");
    scanf("%f", &litros);
    printf("Consumo: %.2f", consumo(km, litros));
    return 0;
}





 







